#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Color_Tint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054B80: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80054B84: addiu       $t7, $zero, 0xFF0
    ctx->r15 = ADD32(0, 0XFF0);
    // 0x80054B88: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80054B8C: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054B90: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80054B94: lh          $t3, 0x2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2);
    // 0x80054B98: addiu       $t4, $zero, 0xFF0
    ctx->r12 = ADD32(0, 0XFF0);
    // 0x80054B9C: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x80054BA0: lh          $t1, 0x0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X0);
    // 0x80054BA4: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x80054BA8: mflo        $t9
    ctx->r25 = lo;
    // 0x80054BAC: nop

    // 0x80054BB0: nop

    // 0x80054BB4: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x80054BB8: mflo        $t0
    ctx->r8 = lo;
    // 0x80054BBC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80054BC0: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x80054BC4: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054BC8: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x80054BCC: addiu       $t1, $zero, 0xFF0
    ctx->r9 = ADD32(0, 0XFF0);
    // 0x80054BD0: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80054BD4: lh          $t5, 0x4($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X4);
    // 0x80054BD8: mflo        $t7
    ctx->r15 = lo;
    // 0x80054BDC: nop

    // 0x80054BE0: nop

    // 0x80054BE4: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x80054BE8: mflo        $t6
    ctx->r14 = lo;
    // 0x80054BEC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80054BF0: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80054BF4: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054BF8: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x80054BFC: addiu       $t8, $zero, 0xFF0
    ctx->r24 = ADD32(0, 0XFF0);
    // 0x80054C00: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x80054C04: lh          $t2, 0x6($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X6);
    // 0x80054C08: mflo        $t4
    ctx->r12 = lo;
    // 0x80054C0C: nop

    // 0x80054C10: nop

    // 0x80054C14: divu        $zero, $t4, $at
    lo = S32(U32(ctx->r12) / U32(ctx->r1)); hi = S32(U32(ctx->r12) % U32(ctx->r1));
    // 0x80054C18: mflo        $t3
    ctx->r11 = lo;
    // 0x80054C1C: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80054C20: lh          $t3, 0x8($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X8);
    // 0x80054C24: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054C28: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x80054C2C: addiu       $t5, $zero, 0xFF0
    ctx->r13 = ADD32(0, 0XFF0);
    // 0x80054C30: subu        $t7, $t5, $t3
    ctx->r15 = SUB32(ctx->r13, ctx->r11);
    // 0x80054C34: lh          $t9, 0x8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8);
    // 0x80054C38: mflo        $t1
    ctx->r9 = lo;
    // 0x80054C3C: nop

    // 0x80054C40: nop

    // 0x80054C44: divu        $zero, $t1, $at
    lo = S32(U32(ctx->r9) / U32(ctx->r1)); hi = S32(U32(ctx->r9) % U32(ctx->r1));
    // 0x80054C48: mflo        $t0
    ctx->r8 = lo;
    // 0x80054C4C: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x80054C50: lh          $t0, 0xA($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XA);
    // 0x80054C54: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054C58: sh          $t4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r12;
    // 0x80054C5C: addiu       $t2, $zero, 0xFF0
    ctx->r10 = ADD32(0, 0XFF0);
    // 0x80054C60: subu        $t4, $t2, $t0
    ctx->r12 = SUB32(ctx->r10, ctx->r8);
    // 0x80054C64: lh          $t7, 0xA($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XA);
    // 0x80054C68: mflo        $t8
    ctx->r24 = lo;
    // 0x80054C6C: nop

    // 0x80054C70: nop

    // 0x80054C74: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x80054C78: mflo        $t6
    ctx->r14 = lo;
    // 0x80054C7C: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x80054C80: sh          $t1, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r9;
    // 0x80054C84: multu       $t4, $a1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054C88: mflo        $t5
    ctx->r13 = lo;
    // 0x80054C8C: nop

    // 0x80054C90: nop

    // 0x80054C94: divu        $zero, $t5, $at
    lo = S32(U32(ctx->r13) / U32(ctx->r1)); hi = S32(U32(ctx->r13) % U32(ctx->r1));
    // 0x80054C98: mflo        $t3
    ctx->r11 = lo;
    // 0x80054C9C: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80054CA0: jr          $ra
    // 0x80054CA4: sh          $t8, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r24;
    return;
    // 0x80054CA4: sh          $t8, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r24;
;}

RECOMP_FUNC void Color_Brighten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054CA8: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80054CAC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80054CB0: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054CB4: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x80054CB8: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x80054CBC: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80054CC0: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x80054CC4: mflo        $t7
    ctx->r15 = lo;
    // 0x80054CC8: nop

    // 0x80054CCC: nop

    // 0x80054CD0: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x80054CD4: mflo        $t8
    ctx->r24 = lo;
    // 0x80054CD8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80054CDC: lh          $t9, 0x4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4);
    // 0x80054CE0: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054CE4: lh          $t1, 0x6($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X6);
    // 0x80054CE8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x80054CEC: mflo        $t2
    ctx->r10 = lo;
    // 0x80054CF0: nop

    // 0x80054CF4: nop

    // 0x80054CF8: divu        $zero, $t2, $at
    lo = S32(U32(ctx->r10) / U32(ctx->r1)); hi = S32(U32(ctx->r10) % U32(ctx->r1));
    // 0x80054CFC: mflo        $t3
    ctx->r11 = lo;
    // 0x80054D00: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80054D04: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x80054D08: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054D0C: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x80054D10: sh          $t5, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r13;
    // 0x80054D14: mflo        $t7
    ctx->r15 = lo;
    // 0x80054D18: nop

    // 0x80054D1C: nop

    // 0x80054D20: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x80054D24: mflo        $t8
    ctx->r24 = lo;
    // 0x80054D28: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80054D2C: lh          $t9, 0x8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8);
    // 0x80054D30: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054D34: lh          $t1, 0xA($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XA);
    // 0x80054D38: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x80054D3C: mflo        $t2
    ctx->r10 = lo;
    // 0x80054D40: nop

    // 0x80054D44: nop

    // 0x80054D48: divu        $zero, $t2, $at
    lo = S32(U32(ctx->r10) / U32(ctx->r1)); hi = S32(U32(ctx->r10) % U32(ctx->r1));
    // 0x80054D4C: mflo        $t3
    ctx->r11 = lo;
    // 0x80054D50: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80054D54: lh          $t4, 0xA($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XA);
    // 0x80054D58: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054D5C: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    // 0x80054D60: mflo        $t7
    ctx->r15 = lo;
    // 0x80054D64: nop

    // 0x80054D68: nop

    // 0x80054D6C: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x80054D70: mflo        $t8
    ctx->r24 = lo;
    // 0x80054D74: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80054D78: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
    // 0x80054D7C: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054D80: mflo        $t2
    ctx->r10 = lo;
    // 0x80054D84: nop

    // 0x80054D88: nop

    // 0x80054D8C: divu        $zero, $t2, $at
    lo = S32(U32(ctx->r10) / U32(ctx->r1)); hi = S32(U32(ctx->r10) % U32(ctx->r1));
    // 0x80054D90: mflo        $t3
    ctx->r11 = lo;
    // 0x80054D94: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80054D98: jr          $ra
    // 0x80054D9C: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
    return;
    // 0x80054D9C: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
;}

RECOMP_FUNC void Color_Blend(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054DA0: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80054DA4: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80054DA8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80054DAC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80054DB0: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054DB4: lh          $t1, 0x0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X0);
    // 0x80054DB8: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x80054DBC: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x80054DC0: mflo        $t9
    ctx->r25 = lo;
    // 0x80054DC4: nop

    // 0x80054DC8: nop

    // 0x80054DCC: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x80054DD0: mflo        $t0
    ctx->r8 = lo;
    // 0x80054DD4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80054DD8: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x80054DDC: lh          $t3, 0x2($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2);
    // 0x80054DE0: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x80054DE4: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80054DE8: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054DEC: lh          $t5, 0x4($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X4);
    // 0x80054DF0: mflo        $t6
    ctx->r14 = lo;
    // 0x80054DF4: nop

    // 0x80054DF8: nop

    // 0x80054DFC: divu        $zero, $t6, $at
    lo = S32(U32(ctx->r14) / U32(ctx->r1)); hi = S32(U32(ctx->r14) % U32(ctx->r1));
    // 0x80054E00: mflo        $t7
    ctx->r15 = lo;
    // 0x80054E04: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80054E08: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x80054E0C: lh          $t0, 0x4($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X4);
    // 0x80054E10: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80054E14: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80054E18: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054E1C: lh          $t2, 0x6($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X6);
    // 0x80054E20: mflo        $t3
    ctx->r11 = lo;
    // 0x80054E24: nop

    // 0x80054E28: nop

    // 0x80054E2C: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x80054E30: mflo        $t4
    ctx->r12 = lo;
    // 0x80054E34: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80054E38: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x80054E3C: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x80054E40: lh          $t5, 0x8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X8);
    // 0x80054E44: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80054E48: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054E4C: lh          $t9, 0x8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8);
    // 0x80054E50: mflo        $t0
    ctx->r8 = lo;
    // 0x80054E54: nop

    // 0x80054E58: nop

    // 0x80054E5C: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x80054E60: mflo        $t1
    ctx->r9 = lo;
    // 0x80054E64: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80054E68: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x80054E6C: lh          $t4, 0x8($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X8);
    // 0x80054E70: lh          $t2, 0xA($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XA);
    // 0x80054E74: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80054E78: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054E7C: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x80054E80: mflo        $t7
    ctx->r15 = lo;
    // 0x80054E84: nop

    // 0x80054E88: nop

    // 0x80054E8C: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x80054E90: mflo        $t8
    ctx->r24 = lo;
    // 0x80054E94: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80054E98: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
    // 0x80054E9C: lh          $t1, 0xA($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XA);
    // 0x80054EA0: nop

    // 0x80054EA4: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80054EA8: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054EAC: mflo        $t4
    ctx->r12 = lo;
    // 0x80054EB0: nop

    // 0x80054EB4: nop

    // 0x80054EB8: divu        $zero, $t4, $at
    lo = S32(U32(ctx->r12) / U32(ctx->r1)); hi = S32(U32(ctx->r12) % U32(ctx->r1));
    // 0x80054EBC: mflo        $t5
    ctx->r13 = lo;
    // 0x80054EC0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80054EC4: jr          $ra
    // 0x80054EC8: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    return;
    // 0x80054EC8: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    // 0x80054ECC: nop

;}

RECOMP_FUNC void getCurPieceSpawnOffsetAsPoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054ED0: lb          $t6, 0x1C($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1C);
    // 0x80054ED4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80054ED8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80054EDC: sh          $t7, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r15;
    // 0x80054EE0: lb          $t8, 0x1D($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1D);
    // 0x80054EE4: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x80054EE8: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80054EEC: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x80054EF0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80054EF4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80054EF8: swl         $at, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r1);
    // 0x80054EFC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80054F00: jr          $ra
    // 0x80054F04: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
    return;
    // 0x80054F04: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void getStartingRotOriginAsPoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054F08: lbu         $t6, 0x1E($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1E);
    // 0x80054F0C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80054F10: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80054F14: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80054F18: lb          $t9, 0xE($t8)
    ctx->r25 = MEM_B(ctx->r24, 0XE);
    // 0x80054F1C: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80054F20: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80054F24: sh          $t0, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r8;
    // 0x80054F28: lbu         $t1, 0x1E($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X1E);
    // 0x80054F2C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80054F30: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80054F34: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x80054F38: lb          $t4, 0xF($t3)
    ctx->r12 = MEM_B(ctx->r11, 0XF);
    // 0x80054F3C: nop

    // 0x80054F40: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80054F44: sh          $t5, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r13;
    // 0x80054F48: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80054F4C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80054F50: swl         $at, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r1);
    // 0x80054F54: jr          $ra
    // 0x80054F58: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
    return;
    // 0x80054F58: swr         $at, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r1);
;}

RECOMP_FUNC void initPieceColorsScale16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054F5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80054F60: sltiu       $at, $a2, 0x7
    ctx->r1 = ctx->r6 < 0X7 ? 1 : 0;
    // 0x80054F64: beq         $at, $zero, L_80054FEC
    if (ctx->r1 == 0) {
        // 0x80054F68: addiu       $sp, $sp, -0x10
        ctx->r29 = ADD32(ctx->r29, -0X10);
            goto L_80054FEC;
    }
    // 0x80054F68: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
L_80054F6C:
    // 0x80054F6C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80054F70: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80054F74: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80054F78: lw          $t7, 0x110($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X110);
    // 0x80054F7C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80054F80: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x80054F84: nop

    // 0x80054F88: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80054F8C: lh          $t0, 0x2($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X2);
    // 0x80054F90: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80054F94: lh          $t2, 0x4($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X4);
    // 0x80054F98: lh          $t4, 0x6($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X6);
    // 0x80054F9C: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x80054FA0: lh          $t8, 0xA($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XA);
    // 0x80054FA4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80054FA8: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80054FAC: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x80054FB0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80054FB4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80054FB8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80054FBC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80054FC0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80054FC4: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80054FC8: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // 0x80054FCC: sh          $t3, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r11;
    // 0x80054FD0: sh          $t5, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r13;
    // 0x80054FD4: sh          $t7, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r15;
    // 0x80054FD8: sh          $t9, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r25;
    // 0x80054FDC: sltiu       $at, $a2, 0x7
    ctx->r1 = ctx->r6 < 0X7 ? 1 : 0;
    // 0x80054FE0: lw          $a0, 0x110($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X110);
    // 0x80054FE4: bne         $at, $zero, L_80054F6C
    if (ctx->r1 != 0) {
        // 0x80054FE8: nop
    
            goto L_80054F6C;
    }
    // 0x80054FE8: nop

L_80054FEC:
    // 0x80054FEC: jr          $ra
    // 0x80054FF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80054FF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80054FF4: nop

    // 0x80054FF8: nop

    // 0x80054FFC: nop

;}

RECOMP_FUNC void gets_lineCounts_loops_numPlayers_checks_gametype(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055000: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80055004: addiu       $t6, $t6, 0xA00
    ctx->r14 = ADD32(ctx->r14, 0XA00);
    // 0x80055008: ori         $at, $zero, 0xE49C
    ctx->r1 = 0 | 0XE49C;
    // 0x8005500C: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80055010: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055014: sw          $zero, 0x14C($at)
    MEM_W(0X14C, ctx->r1) = 0;
    // 0x80055018: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005501C: sb          $zero, -0xDAC($at)
    MEM_B(-0XDAC, ctx->r1) = 0;
    // 0x80055020: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055024: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80055028: lbu         $t8, -0x118($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X118);
    // 0x8005502C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80055030: sb          $zero, 0x148($at)
    MEM_B(0X148, ctx->r1) = 0;
    // 0x80055034: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80055038: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005503C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80055040: beq         $t8, $at, L_800554D4
    if (ctx->r24 == ctx->r1) {
        // 0x80055044: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_800554D4;
    }
    // 0x80055044: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80055048: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8005504C:
    // 0x8005504C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80055050: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80055054: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80055058: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8005505C: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x80055060: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055064: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80055068: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005506C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80055070: sw          $zero, 0x18($t6)
    MEM_W(0X18, ctx->r14) = 0;
    // 0x80055074: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80055078: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005507C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80055080: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80055084: sb          $t7, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r15;
    // 0x80055088: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005508C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80055090: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80055094: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x80055098: sw          $zero, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = 0;
    // 0x8005509C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800550A0: nop

    // 0x800550A4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800550A8: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x800550AC: bne         $at, $zero, L_8005504C
    if (ctx->r1 != 0) {
        // 0x800550B0: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_8005504C;
    }
    // 0x800550B0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800550B4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800550B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800550BC: sw          $zero, 0x38($t8)
    MEM_W(0X38, ctx->r24) = 0;
    // 0x800550C0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800550C4: lbu         $t0, -0x10E0($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X10E0);
    // 0x800550C8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800550CC: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    // 0x800550D0: jal         0x8005102C
    // 0x800550D4: sb          $t0, 0x5($t7)
    MEM_B(0X5, ctx->r15) = ctx->r8;
    Game_countWinners(rdram, ctx);
        goto after_0;
    // 0x800550D4: sb          $t0, 0x5($t7)
    MEM_B(0X5, ctx->r15) = ctx->r8;
    after_0:
    // 0x800550D8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800550DC: nop

    // 0x800550E0: sb          $v0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r2;
    // 0x800550E4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800550E8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800550EC: lbu         $t1, 0x5($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X5);
    // 0x800550F0: nop

    // 0x800550F4: blez        $t1, L_80055208
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800550F8: nop
    
            goto L_80055208;
    }
    // 0x800550F8: nop

L_800550FC:
    // 0x800550FC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055100: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80055104: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80055108: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8005510C: lw          $t5, -0x14D4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X14D4);
    // 0x80055110: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80055114: lw          $t6, 0x6818($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X6818);
    // 0x80055118: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8005511C: divu        $zero, $t6, $at
    lo = S32(U32(ctx->r14) / U32(ctx->r1)); hi = S32(U32(ctx->r14) % U32(ctx->r1));
    // 0x80055120: addu        $t7, $t0, $t3
    ctx->r15 = ADD32(ctx->r8, ctx->r11);
    // 0x80055124: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80055128: mflo        $t8
    ctx->r24 = lo;
    // 0x8005512C: sw          $t8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r24;
    // 0x80055130: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80055134: nop

    // 0x80055138: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8005513C: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80055140: lw          $a0, -0x14D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X14D4);
    // 0x80055144: jal         0x8005282C
    // 0x80055148: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    getLineCount(rdram, ctx);
        goto after_1;
    // 0x80055148: addiu       $a0, $a0, 0x681C
    ctx->r4 = ADD32(ctx->r4, 0X681C);
    after_1:
    // 0x8005514C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80055150: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80055154: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80055158: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x8005515C: sw          $v0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r2;
    // 0x80055160: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80055164: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80055168: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8005516C: addu        $t7, $t0, $t8
    ctx->r15 = ADD32(ctx->r8, ctx->r24);
    // 0x80055170: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80055174: lw          $t2, 0x38($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X38);
    // 0x80055178: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005517C: addu        $t4, $t2, $t9
    ctx->r12 = ADD32(ctx->r10, ctx->r25);
    // 0x80055180: sw          $t4, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r12;
    // 0x80055184: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80055188: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8005518C: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80055190: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80055194: lw          $t6, -0x14D4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X14D4);
    // 0x80055198: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x8005519C: lw          $t3, 0x440($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X440);
    // 0x800551A0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800551A4: sw          $t3, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r11;
    // 0x800551A8: lbu         $t2, -0x1114($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X1114);
    // 0x800551AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800551B0: bne         $t2, $at, L_800551E4
    if (ctx->r10 != ctx->r1) {
        // 0x800551B4: nop
    
            goto L_800551E4;
    }
    // 0x800551B4: nop

    // 0x800551B8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800551BC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800551C0: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x800551C4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800551C8: lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X8);
    // 0x800551CC: nop

    // 0x800551D0: sltiu       $at, $t6, 0xB3
    ctx->r1 = ctx->r14 < 0XB3 ? 1 : 0;
    // 0x800551D4: bne         $at, $zero, L_800551E4
    if (ctx->r1 != 0) {
        // 0x800551D8: nop
    
            goto L_800551E4;
    }
    // 0x800551D8: nop

    // 0x800551DC: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x800551E0: sw          $t8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r24;
L_800551E4:
    // 0x800551E4: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800551E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800551EC: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x800551F0: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800551F4: lbu         $t2, 0x5($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X5);
    // 0x800551F8: nop

    // 0x800551FC: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80055200: bne         $at, $zero, L_800550FC
    if (ctx->r1 != 0) {
        // 0x80055204: nop
    
            goto L_800550FC;
    }
    // 0x80055204: nop

L_80055208:
    // 0x80055208: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8005520C: nop

    // 0x80055210: lbu         $t9, 0x0($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X0);
    // 0x80055214: nop

    // 0x80055218: bne         $t9, $zero, L_80055228
    if (ctx->r25 != 0) {
        // 0x8005521C: nop
    
            goto L_80055228;
    }
    // 0x8005521C: nop

    // 0x80055220: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80055224: sb          $t0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r8;
L_80055228:
    // 0x80055228: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005522C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80055230: lw          $t8, 0x38($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X38);
    // 0x80055234: lbu         $t1, 0x0($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X0);
    // 0x80055238: nop

    // 0x8005523C: divu        $zero, $t8, $t1
    lo = S32(U32(ctx->r24) / U32(ctx->r9)); hi = S32(U32(ctx->r24) % U32(ctx->r9));
    // 0x80055240: bne         $t1, $zero, L_8005524C
    if (ctx->r9 != 0) {
        // 0x80055244: nop
    
            goto L_8005524C;
    }
    // 0x80055244: nop

    // 0x80055248: break       7
    do_break(2147832392);
L_8005524C:
    // 0x8005524C: mflo        $t5
    ctx->r13 = lo;
    // 0x80055250: sw          $t5, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->r13;
    // 0x80055254: lh          $t7, -0x12C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X12C);
    // 0x80055258: nop

    // 0x8005525C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80055260: bne         $at, $zero, L_800552D0
    if (ctx->r1 != 0) {
        // 0x80055264: nop
    
            goto L_800552D0;
    }
    // 0x80055264: nop

    // 0x80055268: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005526C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80055270: lbu         $t2, 0x5($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X5);
    // 0x80055274: nop

    // 0x80055278: blez        $t2, L_800552DC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8005527C: nop
    
            goto L_800552DC;
    }
    // 0x8005527C: nop

L_80055280:
    // 0x80055280: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80055284: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80055288: jal         0x80050E60
    // 0x8005528C: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    Game_isGameWinner(rdram, ctx);
        goto after_2;
    // 0x8005528C: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    after_2:
    // 0x80055290: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80055294: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80055298: nop

    // 0x8005529C: addu        $t4, $t9, $t0
    ctx->r12 = ADD32(ctx->r25, ctx->r8);
    // 0x800552A0: sb          $v0, 0x1($t4)
    MEM_B(0X1, ctx->r12) = ctx->r2;
    // 0x800552A4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800552A8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800552AC: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800552B0: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800552B4: lbu         $t6, 0x5($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X5);
    // 0x800552B8: nop

    // 0x800552BC: slt         $at, $t1, $t6
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800552C0: bne         $at, $zero, L_80055280
    if (ctx->r1 != 0) {
        // 0x800552C4: nop
    
            goto L_80055280;
    }
    // 0x800552C4: nop

    // 0x800552C8: b           L_800552DC
    // 0x800552CC: nop

        goto L_800552DC;
    // 0x800552CC: nop

L_800552D0:
    // 0x800552D0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800552D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800552D8: sb          $t7, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r15;
L_800552DC:
    // 0x800552DC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800552E0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800552E4: lbu         $t9, 0x5($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X5);
    // 0x800552E8: nop

    // 0x800552EC: blez        $t9, L_800554C8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800552F0: nop
    
            goto L_800554C8;
    }
    // 0x800552F0: nop

L_800552F4:
    // 0x800552F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800552F8: ori         $at, $zero, 0xE13C
    ctx->r1 = 0 | 0XE13C;
    // 0x800552FC: sll         $t4, $t0, 3
    ctx->r12 = S32(ctx->r8 << 3);
    // 0x80055300: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x80055304: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80055308: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x8005530C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80055310: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80055314: addiu       $t5, $t5, 0xA00
    ctx->r13 = ADD32(ctx->r13, 0XA00);
    // 0x80055318: addu        $t8, $t4, $at
    ctx->r24 = ADD32(ctx->r12, ctx->r1);
    // 0x8005531C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80055320: addiu       $a0, $a0, 0x2D80
    ctx->r4 = ADD32(ctx->r4, 0X2D80);
    // 0x80055324: jal         0x8007AA5C
    // 0x80055328: addu        $a1, $t8, $t5
    ctx->r5 = ADD32(ctx->r24, ctx->r13);
    displayText_FindEntry(rdram, ctx);
        goto after_3;
    // 0x80055328: addu        $a1, $t8, $t5
    ctx->r5 = ADD32(ctx->r24, ctx->r13);
    after_3:
    // 0x8005532C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80055330: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80055334: nop

    // 0x80055338: beq         $t1, $zero, L_800554A4
    if (ctx->r9 == 0) {
        // 0x8005533C: nop
    
            goto L_800554A4;
    }
    // 0x8005533C: nop

    // 0x80055340: lw          $t6, 0xC($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XC);
    // 0x80055344: nop

    // 0x80055348: beq         $t6, $zero, L_80055490
    if (ctx->r14 == 0) {
        // 0x8005534C: nop
    
            goto L_80055490;
    }
    // 0x8005534C: nop

    // 0x80055350: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80055354: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80055358: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8005535C: addu        $t9, $t7, $t2
    ctx->r25 = ADD32(ctx->r15, ctx->r10);
    // 0x80055360: sw          $t6, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r14;
    // 0x80055364: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80055368: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8005536C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80055370: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x80055374: jal         0x8007875C
    // 0x80055378: nop

    FUN_SRAM_8007875c_check_gameover_conditions(rdram, ctx);
        goto after_4;
    // 0x80055378: nop

    after_4:
    // 0x8005537C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80055380: nop

    // 0x80055384: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x80055388: jal         0x8007B420
    // 0x8005538C: nop

    displayText_DeserializeTable(rdram, ctx);
        goto after_5;
    // 0x8005538C: nop

    after_5:
    // 0x80055390: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80055394: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80055398: lbu         $s0, 0xB($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0XB);
    // 0x8005539C: nop

    // 0x800553A0: andi        $t5, $s0, 0xF
    ctx->r13 = ctx->r16 & 0XF;
    // 0x800553A4: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x800553A8: beq         $s0, $at, L_8005546C
    if (ctx->r16 == ctx->r1) {
        // 0x800553AC: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_8005546C;
    }
    // 0x800553AC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800553B0: bne         $s0, $at, L_800554A4
    if (ctx->r16 != ctx->r1) {
        // 0x800553B4: nop
    
            goto L_800554A4;
    }
    // 0x800553B4: nop

    // 0x800553B8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800553BC:
    // 0x800553BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800553C0: lw          $t2, -0x310($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X310);
    // 0x800553C4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800553C8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800553CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800553D0: sllv        $t7, $t3, $t1
    ctx->r15 = S32(ctx->r11 << (ctx->r9 & 31));
    // 0x800553D4: and         $t9, $t7, $t6
    ctx->r25 = ctx->r15 & ctx->r14;
    // 0x800553D8: beq         $t9, $zero, L_8005543C
    if (ctx->r25 == 0) {
        // 0x800553DC: nop
    
            goto L_8005543C;
    }
    // 0x800553DC: nop

    // 0x800553E0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800553E4: sll         $t0, $t1, 4
    ctx->r8 = S32(ctx->r9 << 4);
    // 0x800553E8: lw          $t8, 0xC($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC);
    // 0x800553EC: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x800553F0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800553F4: addu        $a0, $t2, $t0
    ctx->r4 = ADD32(ctx->r10, ctx->r8);
    // 0x800553F8: lbu         $a1, 0x9($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X9);
    // 0x800553FC: lbu         $a2, 0xA($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0XA);
    // 0x80055400: jal         0x8007AADC
    // 0x80055404: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    displayText_MatchXY(rdram, ctx);
        goto after_6;
    // 0x80055404: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_6:
    // 0x80055408: beq         $v0, $zero, L_8005543C
    if (ctx->r2 == 0) {
        // 0x8005540C: nop
    
            goto L_8005543C;
    }
    // 0x8005540C: nop

    // 0x80055410: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80055414: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80055418: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005541C: sll         $t3, $a2, 4
    ctx->r11 = S32(ctx->r6 << 4);
    // 0x80055420: lw          $a1, -0x310($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X310);
    // 0x80055424: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x80055428: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8005542C: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x80055430: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80055434: jal         0x8007AF88
    // 0x80055438: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    displayText_EncodeEntry(rdram, ctx);
        goto after_7;
    // 0x80055438: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_7:
L_8005543C:
    // 0x8005543C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80055440: nop

    // 0x80055444: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80055448: slti        $at, $t6, 0x20
    ctx->r1 = SIGNED(ctx->r14) < 0X20 ? 1 : 0;
    // 0x8005544C: bne         $at, $zero, L_800553BC
    if (ctx->r1 != 0) {
        // 0x80055450: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_800553BC;
    }
    // 0x80055450: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80055454: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80055458: lw          $a0, -0x310($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X310);
    // 0x8005545C: jal         0x8007C5CC
    // 0x80055460: nop

    SaveData_Save(rdram, ctx);
        goto after_8;
    // 0x80055460: nop

    after_8:
    // 0x80055464: b           L_800554A4
    // 0x80055468: nop

        goto L_800554A4;
    // 0x80055468: nop

L_8005546C:
    // 0x8005546C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80055470: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80055474: lbu         $t9, -0xDAC($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0XDAC);
    // 0x80055478: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005547C: sllv        $t0, $t2, $t1
    ctx->r8 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80055480: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055484: or          $t4, $t9, $t0
    ctx->r12 = ctx->r25 | ctx->r8;
    // 0x80055488: b           L_800554A4
    // 0x8005548C: sb          $t4, -0xDAC($at)
    MEM_B(-0XDAC, ctx->r1) = ctx->r12;
        goto L_800554A4;
    // 0x8005548C: sb          $t4, -0xDAC($at)
    MEM_B(-0XDAC, ctx->r1) = ctx->r12;
L_80055490:
    // 0x80055490: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80055494: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80055498: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8005549C: addu        $t7, $t8, $t3
    ctx->r15 = ADD32(ctx->r24, ctx->r11);
    // 0x800554A0: sw          $zero, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = 0;
L_800554A4:
    // 0x800554A4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800554A8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800554AC: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x800554B0: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x800554B4: lbu         $t9, 0x5($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X5);
    // 0x800554B8: nop

    // 0x800554BC: slt         $at, $t2, $t9
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800554C0: bne         $at, $zero, L_800552F4
    if (ctx->r1 != 0) {
        // 0x800554C4: nop
    
            goto L_800552F4;
    }
    // 0x800554C4: nop

L_800554C8:
    // 0x800554C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800554CC: b           L_800554F0
    // 0x800554D0: sw          $zero, 0x144($at)
    MEM_W(0X144, ctx->r1) = 0;
        goto L_800554F0;
    // 0x800554D0: sw          $zero, 0x144($at)
    MEM_W(0X144, ctx->r1) = 0;
L_800554D4:
    // 0x800554D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800554D8: lbu         $t0, -0x10E0($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X10E0);
    // 0x800554DC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800554E0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800554E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800554E8: sb          $t0, 0x5($t4)
    MEM_B(0X5, ctx->r12) = ctx->r8;
    // 0x800554EC: sw          $t5, 0x144($at)
    MEM_W(0X144, ctx->r1) = ctx->r13;
L_800554F0:
    // 0x800554F0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800554F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800554F8: sb          $t8, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r24;
    // 0x800554FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055500: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80055504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80055508: sb          $t3, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r11;
    // 0x8005550C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055510: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80055514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80055518: sw          $t7, 0x140($at)
    MEM_W(0X140, ctx->r1) = ctx->r15;
    // 0x8005551C: jr          $ra
    // 0x80055520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80055520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

RECOMP_FUNC void calls_game_deinit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055524: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80055528: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005552C: jal         0x8004A34C
    // 0x80055530: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x80055530: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80055534: jal         0x80084F80
    // 0x80055538: nop

    Audio_UnloadSFX(rdram, ctx);
        goto after_1;
    // 0x80055538: nop

    after_1:
    // 0x8005553C: jal         0x80052570
    // 0x80055540: nop

    Game_Deinit(rdram, ctx);
        goto after_2;
    // 0x80055540: nop

    after_2:
    // 0x80055544: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80055548: jal         0x80085030
    // 0x8005554C: addiu       $a0, $a0, 0x3988
    ctx->r4 = ADD32(ctx->r4, 0X3988);
    Audio_LoadSFX(rdram, ctx);
        goto after_3;
    // 0x8005554C: addiu       $a0, $a0, 0x3988
    ctx->r4 = ADD32(ctx->r4, 0X3988);
    after_3:
    // 0x80055550: lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // 0x80055554: jal         0x8007E03C
    // 0x80055558: ori         $a0, $a0, 0xA988
    ctx->r4 = ctx->r4 | 0XA988;
    n64HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x80055558: ori         $a0, $a0, 0xA988
    ctx->r4 = ctx->r4 | 0XA988;
    after_4:
    // 0x8005555C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055560: sw          $v0, -0xDB0($at)
    MEM_W(-0XDB0, ctx->r1) = ctx->r2;
    // 0x80055564: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80055568: lw          $t7, -0xDB0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XDB0);
    // 0x8005556C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055570: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80055574: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80055578: lw          $t9, -0xDB0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XDB0);
    // 0x8005557C: addiu       $t8, $zero, 0x90
    ctx->r24 = ADD32(0, 0X90);
    // 0x80055580: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80055584: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
    // 0x80055588: lw          $t1, -0xDB0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XDB0);
    // 0x8005558C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80055590: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80055594: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x80055598: lw          $t3, -0xDB0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XDB0);
    // 0x8005559C: addiu       $t2, $zero, 0x2C
    ctx->r10 = ADD32(0, 0X2C);
    // 0x800555A0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800555A4: sb          $t2, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r10;
    // 0x800555A8: lw          $t4, -0xDB0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XDB0);
    // 0x800555AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800555B0: sb          $zero, 0x4($t4)
    MEM_B(0X4, ctx->r12) = 0;
    // 0x800555B4: lw          $t5, -0xDB0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XDB0);
    // 0x800555B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800555BC: sb          $zero, 0x5($t5)
    MEM_B(0X5, ctx->r13) = 0;
    // 0x800555C0: lw          $t6, -0xDB0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XDB0);
    // 0x800555C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800555C8: sb          $zero, 0x6($t6)
    MEM_B(0X6, ctx->r14) = 0;
    // 0x800555CC: lw          $t7, -0xDB0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XDB0);
    // 0x800555D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800555D4: sb          $zero, 0x7($t7)
    MEM_B(0X7, ctx->r15) = 0;
    // 0x800555D8: lw          $a0, -0xDB0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XDB0);
    // 0x800555DC: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800555E0: ori         $a1, $a1, 0xD4C4
    ctx->r5 = ctx->r5 | 0XD4C4;
    // 0x800555E4: jal         0x800A8FC8
    // 0x800555E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A8FC8(rdram, ctx);
        goto after_5;
    // 0x800555E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800555EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800555F0: lw          $t8, -0xDB0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XDB0);
    // 0x800555F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800555F8: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    // 0x800555FC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80055600: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x80055604: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x80055608: jal         0x8008F280
    // 0x8005560C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8008F280(rdram, ctx);
        goto after_6;
    // 0x8005560C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_6:
    // 0x80055610: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80055614: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80055618: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8005561C: addiu       $a2, $a2, 0x5FE8
    ctx->r6 = ADD32(ctx->r6, 0X5FE8);
    // 0x80055620: addiu       $a1, $a1, 0x6010
    ctx->r5 = ADD32(ctx->r5, 0X6010);
    // 0x80055624: jal         0x8008F360
    // 0x80055628: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    func_8008F360(rdram, ctx);
        goto after_7;
    // 0x80055628: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    after_7:
    // 0x8005562C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055630: sw          $zero, 0x3CF4($at)
    MEM_W(0X3CF4, ctx->r1) = 0;
    // 0x80055634: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055638: sw          $zero, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = 0;
    // 0x8005563C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055640: sw          $zero, 0x3CFC($at)
    MEM_W(0X3CFC, ctx->r1) = 0;
    // 0x80055644: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80055648: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8005564C: sw          $zero, -0x6E1C($at)
    MEM_W(-0X6E1C, ctx->r1) = 0;
    // 0x80055650: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80055654: jal         0x80074888
    // 0x80055658: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_8;
    // 0x80055658: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_8:
    // 0x8005565C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80055660: jal         0x8007E03C
    // 0x80055664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_9;
    // 0x80055664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80055668: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005566C: sw          $v0, -0xDC0($at)
    MEM_W(-0XDC0, ctx->r1) = ctx->r2;
    // 0x80055670: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80055674: lw          $a1, -0xDC0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XDC0);
    // 0x80055678: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8005567C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80055680: jal         0x800746C0
    // 0x80055684: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_10;
    // 0x80055684: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    after_10:
    // 0x80055688: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x8005568C: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x80055690: jal         0x80074888
    // 0x80055694: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    GarbageImg_GetDecodedSize(rdram, ctx);
        goto after_11;
    // 0x80055694: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    after_11:
    // 0x80055698: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005569C: jal         0x8007E03C
    // 0x800556A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n64HeapAlloc(rdram, ctx);
        goto after_12;
    // 0x800556A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800556A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800556A8: sw          $v0, -0xDA8($at)
    MEM_W(-0XDA8, ctx->r1) = ctx->r2;
    // 0x800556AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800556B0: lw          $a1, -0xDA8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XDA8);
    // 0x800556B4: lui         $a0, 0x27
    ctx->r4 = S32(0X27 << 16);
    // 0x800556B8: addiu       $a0, $a0, 0x3A00
    ctx->r4 = ADD32(ctx->r4, 0X3A00);
    // 0x800556BC: jal         0x800746C0
    // 0x800556C0: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    GarbageImg_DecodeSprite(rdram, ctx);
        goto after_13;
    // 0x800556C0: addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    after_13:
    // 0x800556C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800556C8: addiu       $a0, $a0, -0x7150
    ctx->r4 = ADD32(ctx->r4, -0X7150);
    // 0x800556CC: jal         0x80077408
    // 0x800556D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    Font_Init46Char(rdram, ctx);
        goto after_14;
    // 0x800556D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_14:
    // 0x800556D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800556D8: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // 0x800556DC: jal         0x80077408
    // 0x800556E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    Font_Init46Char(rdram, ctx);
        goto after_15;
    // 0x800556E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_15:
    // 0x800556E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800556E8: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    // 0x800556EC: jal         0x80077408
    // 0x800556F0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    Font_Init46Char(rdram, ctx);
        goto after_16;
    // 0x800556F0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_16:
    // 0x800556F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800556F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800556FC: jr          $ra
    // 0x80055700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80055700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

RECOMP_FUNC void FUN_80055704_threeliner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055704: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80055708: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005570C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055710: lw          $a0, -0xDA8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XDA8);
    // 0x80055714: jal         0x8007E328
    // 0x80055718: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_0;
    // 0x80055718: nop

    after_0:
    // 0x8005571C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80055720: lw          $a0, -0xDC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XDC0);
    // 0x80055724: jal         0x8007E328
    // 0x80055728: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_1;
    // 0x80055728: nop

    after_1:
    // 0x8005572C: jal         0x80090A44
    // 0x80055730: nop

    func_80090A44(rdram, ctx);
        goto after_2;
    // 0x80055730: nop

    after_2:
    // 0x80055734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80055738: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005573C: jr          $ra
    // 0x80055740: nop

    return;
    // 0x80055740: nop

;}

RECOMP_FUNC void game_over_display_stuff_huge_function_q(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055744: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80055748: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x8005574C: addiu       $t6, $t6, 0xA00
    ctx->r14 = ADD32(ctx->r14, 0XA00);
    // 0x80055750: ori         $at, $zero, 0xE49C
    ctx->r1 = 0 | 0XE49C;
    // 0x80055754: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80055758: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8005575C: lw          $t9, 0x144($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X144);
    // 0x80055760: ori         $at, $zero, 0xE13C
    ctx->r1 = 0 | 0XE13C;
    // 0x80055764: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x80055768: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005576C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80055770: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80055774: sw          $t7, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r15;
    // 0x80055778: beq         $t9, $zero, L_80055838
    if (ctx->r25 == 0) {
        // 0x8005577C: sw          $t8, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->r24;
            goto L_80055838;
    }
    // 0x8005577C: sw          $t8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r24;
    // 0x80055780: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80055784: lw          $t0, 0x140($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X140);
    // 0x80055788: nop

    // 0x8005578C: beq         $t0, $zero, L_80055838
    if (ctx->r8 == 0) {
        // 0x80055790: nop
    
            goto L_80055838;
    }
    // 0x80055790: nop

    // 0x80055794: jal         0x8004A34C
    // 0x80055798: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_0;
    // 0x80055798: nop

    after_0:
    // 0x8005579C: jal         0x80052570
    // 0x800557A0: nop

    Game_Deinit(rdram, ctx);
        goto after_1;
    // 0x800557A0: nop

    after_1:
    // 0x800557A4: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x800557A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800557AC: sw          $zero, 0x14C($at)
    MEM_W(0X14C, ctx->r1) = 0;
    // 0x800557B0: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x800557B4: nop

    // 0x800557B8: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800557BC: bne         $at, $zero, L_800557F8
    if (ctx->r1 != 0) {
        // 0x800557C0: nop
    
            goto L_800557F8;
    }
    // 0x800557C0: nop

    // 0x800557C4: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x800557C8: nop

    // 0x800557CC: lbu         $t4, 0x1A8($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1A8);
    // 0x800557D0: nop

    // 0x800557D4: bne         $t4, $zero, L_800557F8
    if (ctx->r12 != 0) {
        // 0x800557D8: nop
    
            goto L_800557F8;
    }
    // 0x800557D8: nop

    // 0x800557DC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800557E0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800557E4: addiu       $a1, $a1, 0x5CE8
    ctx->r5 = ADD32(ctx->r5, 0X5CE8);
    // 0x800557E8: jal         0x8009035C
    // 0x800557EC: addiu       $a0, $a0, 0x5D48
    ctx->r4 = ADD32(ctx->r4, 0X5D48);
    func_8009035C(rdram, ctx);
        goto after_2;
    // 0x800557EC: addiu       $a0, $a0, 0x5D48
    ctx->r4 = ADD32(ctx->r4, 0X5D48);
    after_2:
    // 0x800557F0: b           L_8005580C
    // 0x800557F4: nop

        goto L_8005580C;
    // 0x800557F4: nop

L_800557F8:
    // 0x800557F8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800557FC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80055800: addiu       $a1, $a1, 0x5808
    ctx->r5 = ADD32(ctx->r5, 0X5808);
    // 0x80055804: jal         0x8009035C
    // 0x80055808: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    func_8009035C(rdram, ctx);
        goto after_3;
    // 0x80055808: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    after_3:
L_8005580C:
    // 0x8005580C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80055810: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055814: sb          $t5, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r13;
    // 0x80055818: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005581C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80055820: sb          $t7, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r15;
    // 0x80055824: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055828: sw          $zero, 0x140($at)
    MEM_W(0X140, ctx->r1) = 0;
    // 0x8005582C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055830: b           L_80057068
    // 0x80055834: sb          $zero, 0x154($at)
    MEM_B(0X154, ctx->r1) = 0;
        goto L_80057068;
    // 0x80055834: sb          $zero, 0x154($at)
    MEM_B(0X154, ctx->r1) = 0;
L_80055838:
    // 0x80055838: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8005583C: lw          $t6, 0x140($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X140);
    // 0x80055840: nop

    // 0x80055844: beq         $t6, $zero, L_8005588C
    if (ctx->r14 == 0) {
        // 0x80055848: nop
    
            goto L_8005588C;
    }
    // 0x80055848: nop

    // 0x8005584C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80055850: lw          $t8, 0x144($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X144);
    // 0x80055854: nop

    // 0x80055858: bne         $t8, $zero, L_8005588C
    if (ctx->r24 != 0) {
        // 0x8005585C: nop
    
            goto L_8005588C;
    }
    // 0x8005585C: nop

    // 0x80055860: jal         0x8004A34C
    // 0x80055864: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_4;
    // 0x80055864: nop

    after_4:
    // 0x80055868: jal         0x80055524
    // 0x8005586C: nop

    calls_game_deinit(rdram, ctx);
        goto after_5;
    // 0x8005586C: nop

    after_5:
    // 0x80055870: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055874: sw          $zero, 0x140($at)
    MEM_W(0X140, ctx->r1) = 0;
    // 0x80055878: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005587C: sw          $zero, 0x150($at)
    MEM_W(0X150, ctx->r1) = 0;
    // 0x80055880: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055884: b           L_80057068
    // 0x80055888: sb          $zero, 0x154($at)
    MEM_B(0X154, ctx->r1) = 0;
        goto L_80057068;
    // 0x80055888: sb          $zero, 0x154($at)
    MEM_B(0X154, ctx->r1) = 0;
L_8005588C:
    // 0x8005588C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80055890: lw          $t9, 0x150($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X150);
    // 0x80055894: nop

    // 0x80055898: slti        $at, $t9, 0x78
    ctx->r1 = SIGNED(ctx->r25) < 0X78 ? 1 : 0;
    // 0x8005589C: beq         $at, $zero, L_8005594C
    if (ctx->r1 == 0) {
        // 0x800558A0: nop
    
            goto L_8005594C;
    }
    // 0x800558A0: nop

    // 0x800558A4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800558A8: addiu       $t0, $t0, -0x10D0
    ctx->r8 = ADD32(ctx->r8, -0X10D0);
    // 0x800558AC: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x800558B0: nop

    // 0x800558B4: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x800558B8: beq         $t2, $zero, L_8005594C
    if (ctx->r10 == 0) {
        // 0x800558BC: slti        $at, $t9, 0x1E
        ctx->r1 = SIGNED(ctx->r25) < 0X1E ? 1 : 0;
            goto L_8005594C;
    }
    // 0x800558BC: slti        $at, $t9, 0x1E
    ctx->r1 = SIGNED(ctx->r25) < 0X1E ? 1 : 0;
    // 0x800558C0: beq         $at, $zero, L_800558D8
    if (ctx->r1 == 0) {
        // 0x800558C4: nop
    
            goto L_800558D8;
    }
    // 0x800558C4: nop

    // 0x800558C8: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x800558CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800558D0: b           L_8005594C
    // 0x800558D4: sw          $t3, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r11;
        goto L_8005594C;
    // 0x800558D4: sw          $t3, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r11;
L_800558D8:
    // 0x800558D8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800558DC: lw          $t4, 0x150($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X150);
    // 0x800558E0: nop

    // 0x800558E4: slti        $at, $t4, 0x3C
    ctx->r1 = SIGNED(ctx->r12) < 0X3C ? 1 : 0;
    // 0x800558E8: beq         $at, $zero, L_80055900
    if (ctx->r1 == 0) {
        // 0x800558EC: nop
    
            goto L_80055900;
    }
    // 0x800558EC: nop

    // 0x800558F0: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x800558F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800558F8: b           L_8005594C
    // 0x800558FC: sw          $t5, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r13;
        goto L_8005594C;
    // 0x800558FC: sw          $t5, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r13;
L_80055900:
    // 0x80055900: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80055904: lw          $t7, 0x150($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X150);
    // 0x80055908: nop

    // 0x8005590C: slti        $at, $t7, 0x5A
    ctx->r1 = SIGNED(ctx->r15) < 0X5A ? 1 : 0;
    // 0x80055910: beq         $at, $zero, L_80055928
    if (ctx->r1 == 0) {
        // 0x80055914: nop
    
            goto L_80055928;
    }
    // 0x80055914: nop

    // 0x80055918: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x8005591C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055920: b           L_8005594C
    // 0x80055924: sw          $t6, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r14;
        goto L_8005594C;
    // 0x80055924: sw          $t6, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r14;
L_80055928:
    // 0x80055928: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8005592C: lw          $t8, 0x150($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X150);
    // 0x80055930: nop

    // 0x80055934: slti        $at, $t8, 0x78
    ctx->r1 = SIGNED(ctx->r24) < 0X78 ? 1 : 0;
    // 0x80055938: beq         $at, $zero, L_8005594C
    if (ctx->r1 == 0) {
        // 0x8005593C: nop
    
            goto L_8005594C;
    }
    // 0x8005593C: nop

    // 0x80055940: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x80055944: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055948: sw          $t0, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r8;
L_8005594C:
    // 0x8005594C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80055950: lbu         $t1, -0xDAC($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0XDAC);
    // 0x80055954: nop

    // 0x80055958: bne         $t1, $zero, L_80055974
    if (ctx->r9 != 0) {
        // 0x8005595C: nop
    
            goto L_80055974;
    }
    // 0x8005595C: nop

    // 0x80055960: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80055964: lw          $t2, 0x14C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X14C);
    // 0x80055968: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005596C: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x80055970: sw          $t9, 0x14C($at)
    MEM_W(0X14C, ctx->r1) = ctx->r25;
L_80055974:
    // 0x80055974: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80055978: lw          $t3, 0x14C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X14C);
    // 0x8005597C: nop

    // 0x80055980: slti        $at, $t3, 0xBB8
    ctx->r1 = SIGNED(ctx->r11) < 0XBB8 ? 1 : 0;
    // 0x80055984: beq         $at, $zero, L_800559C0
    if (ctx->r1 == 0) {
        // 0x80055988: nop
    
            goto L_800559C0;
    }
    // 0x80055988: nop

    // 0x8005598C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80055990: addiu       $t4, $t4, -0x10D0
    ctx->r12 = ADD32(ctx->r12, -0X10D0);
    // 0x80055994: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x80055998: nop

    // 0x8005599C: andi        $t7, $t5, 0x8000
    ctx->r15 = ctx->r13 & 0X8000;
    // 0x800559A0: beq         $t7, $zero, L_80055B9C
    if (ctx->r15 == 0) {
        // 0x800559A4: nop
    
            goto L_80055B9C;
    }
    // 0x800559A4: nop

    // 0x800559A8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800559AC: lw          $t6, 0x150($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X150);
    // 0x800559B0: nop

    // 0x800559B4: slti        $at, $t6, 0x79
    ctx->r1 = SIGNED(ctx->r14) < 0X79 ? 1 : 0;
    // 0x800559B8: bne         $at, $zero, L_80055B9C
    if (ctx->r1 != 0) {
        // 0x800559BC: nop
    
            goto L_80055B9C;
    }
    // 0x800559BC: nop

L_800559C0:
    // 0x800559C0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800559C4: lbu         $t0, 0x158($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X158);
    // 0x800559C8: addiu       $t8, $zero, 0xBB8
    ctx->r24 = ADD32(0, 0XBB8);
    // 0x800559CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800559D0: sw          $t8, 0x14C($at)
    MEM_W(0X14C, ctx->r1) = ctx->r24;
    // 0x800559D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800559D8: sltiu       $s0, $t0, 0x1
    ctx->r16 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800559DC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800559E0: beq         $s0, $zero, L_80055B2C
    if (ctx->r16 == 0) {
        // 0x800559E4: sb          $t1, 0x158($at)
        MEM_B(0X158, ctx->r1) = ctx->r9;
            goto L_80055B2C;
    }
    // 0x800559E4: sb          $t1, 0x158($at)
    MEM_B(0X158, ctx->r1) = ctx->r9;
    // 0x800559E8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800559EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800559F0: jal         0x80055704
    // 0x800559F4: sb          $t2, 0x158($at)
    MEM_B(0X158, ctx->r1) = ctx->r10;
    FUN_80055704_threeliner(rdram, ctx);
        goto after_6;
    // 0x800559F4: sb          $t2, 0x158($at)
    MEM_B(0X158, ctx->r1) = ctx->r10;
    after_6:
    // 0x800559F8: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x800559FC: nop

    // 0x80055A00: lbu         $t3, 0x0($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X0);
    // 0x80055A04: nop

    // 0x80055A08: beq         $t3, $zero, L_80055AAC
    if (ctx->r11 == 0) {
        // 0x80055A0C: nop
    
            goto L_80055AAC;
    }
    // 0x80055A0C: nop

    // 0x80055A10: jal         0x80045FDC
    // 0x80055A14: nop

    wonders2_80045fdc_sets_num_won_compl_q(rdram, ctx);
        goto after_7;
    // 0x80055A14: nop

    after_7:
    // 0x80055A18: beq         $v0, $zero, L_80055AAC
    if (ctx->r2 == 0) {
        // 0x80055A1C: nop
    
            goto L_80055AAC;
    }
    // 0x80055A1C: nop

    // 0x80055A20: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80055A24: lb          $t4, -0x7C8($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X7C8);
    // 0x80055A28: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x80055A2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055A30: sb          $t4, -0x1108($at)
    MEM_B(-0X1108, ctx->r1) = ctx->r12;
    // 0x80055A34: lbu         $t7, 0x5($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X5);
    // 0x80055A38: nop

    // 0x80055A3C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80055A40: bne         $at, $zero, L_80055A70
    if (ctx->r1 != 0) {
        // 0x80055A44: nop
    
            goto L_80055A70;
    }
    // 0x80055A44: nop

    // 0x80055A48: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    // 0x80055A4C: nop

    // 0x80055A50: lbu         $t8, 0x1A8($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1A8);
    // 0x80055A54: nop

    // 0x80055A58: bne         $t8, $zero, L_80055A70
    if (ctx->r24 != 0) {
        // 0x80055A5C: nop
    
            goto L_80055A70;
    }
    // 0x80055A5C: nop

    // 0x80055A60: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80055A64: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80055A68: b           L_80055A7C
    // 0x80055A6C: sb          $t0, 0x9F0($at)
    MEM_B(0X9F0, ctx->r1) = ctx->r8;
        goto L_80055A7C;
    // 0x80055A6C: sb          $t0, 0x9F0($at)
    MEM_B(0X9F0, ctx->r1) = ctx->r8;
L_80055A70:
    // 0x80055A70: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80055A74: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80055A78: sb          $t1, 0x9F0($at)
    MEM_B(0X9F0, ctx->r1) = ctx->r9;
L_80055A7C:
    // 0x80055A7C: jal         0x8004A34C
    // 0x80055A80: nop

    main_8004A34C_threeliner(rdram, ctx);
        goto after_8;
    // 0x80055A80: nop

    after_8:
    // 0x80055A84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055A88: sb          $zero, 0x3CF0($at)
    MEM_B(0X3CF0, ctx->r1) = 0;
    // 0x80055A8C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80055A90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055A94: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80055A98: lb          $a0, -0x7D0($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X7D0);
    // 0x80055A9C: jal         0x80045BDC
    // 0x80055AA0: sb          $t2, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r10;
    wonders1_Init(rdram, ctx);
        goto after_9;
    // 0x80055AA0: sb          $t2, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r10;
    after_9:
    // 0x80055AA4: b           L_80057068
    // 0x80055AA8: nop

        goto L_80057068;
    // 0x80055AA8: nop

L_80055AAC:
    // 0x80055AAC: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x80055AB0: nop

    // 0x80055AB4: lbu         $t3, 0x5($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X5);
    // 0x80055AB8: nop

    // 0x80055ABC: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80055AC0: bne         $at, $zero, L_80055AFC
    if (ctx->r1 != 0) {
        // 0x80055AC4: nop
    
            goto L_80055AFC;
    }
    // 0x80055AC4: nop

    // 0x80055AC8: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x80055ACC: nop

    // 0x80055AD0: lbu         $t5, 0x1A8($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1A8);
    // 0x80055AD4: nop

    // 0x80055AD8: bne         $t5, $zero, L_80055AFC
    if (ctx->r13 != 0) {
        // 0x80055ADC: nop
    
            goto L_80055AFC;
    }
    // 0x80055ADC: nop

    // 0x80055AE0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80055AE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80055AE8: addiu       $a1, $a1, 0x5CE8
    ctx->r5 = ADD32(ctx->r5, 0X5CE8);
    // 0x80055AEC: jal         0x8009035C
    // 0x80055AF0: addiu       $a0, $a0, 0x5D48
    ctx->r4 = ADD32(ctx->r4, 0X5D48);
    func_8009035C(rdram, ctx);
        goto after_10;
    // 0x80055AF0: addiu       $a0, $a0, 0x5D48
    ctx->r4 = ADD32(ctx->r4, 0X5D48);
    after_10:
    // 0x80055AF4: b           L_80055B10
    // 0x80055AF8: nop

        goto L_80055B10;
    // 0x80055AF8: nop

L_80055AFC:
    // 0x80055AFC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80055B00: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80055B04: addiu       $a1, $a1, 0x5808
    ctx->r5 = ADD32(ctx->r5, 0X5808);
    // 0x80055B08: jal         0x8009035C
    // 0x80055B0C: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    func_8009035C(rdram, ctx);
        goto after_11;
    // 0x80055B0C: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    after_11:
L_80055B10:
    // 0x80055B10: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80055B14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B18: sb          $t7, -0x118($at)
    MEM_B(-0X118, ctx->r1) = ctx->r15;
    // 0x80055B1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B20: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055B24: b           L_80057068
    // 0x80055B28: sb          $t6, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r14;
        goto L_80057068;
    // 0x80055B28: sb          $t6, -0x2B8($at)
    MEM_B(-0X2B8, ctx->r1) = ctx->r14;
L_80055B2C:
    // 0x80055B2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80055B30: jal         0x8005BBFC
    // 0x80055B34: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    func_8005BBFC(rdram, ctx);
        goto after_12;
    // 0x80055B34: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_12:
    // 0x80055B38: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80055B3C: lw          $t8, -0x6E0C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6E0C);
    // 0x80055B40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80055B44: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x80055B48: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80055B4C: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x80055B50: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x80055B54: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80055B58: lw          $t1, 0x10($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X10);
    // 0x80055B5C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80055B60: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80055B64: lw          $t2, 0x14($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X14);
    // 0x80055B68: nop

    // 0x80055B6C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80055B70: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x80055B74: nop

    // 0x80055B78: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80055B7C: lw          $t3, 0x1C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X1C);
    // 0x80055B80: jal         0x80057460
    // 0x80055B84: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_13;
    // 0x80055B84: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_13:
    // 0x80055B88: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80055B8C: jal         0x8005BE40
    // 0x80055B90: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_14;
    // 0x80055B90: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_14:
    // 0x80055B94: b           L_80057068
    // 0x80055B98: nop

        goto L_80057068;
    // 0x80055B98: nop

L_80055B9C:
    // 0x80055B9C: jal         0x8009D5E4
    // 0x80055BA0: nop

    func_8009D5E4(rdram, ctx);
        goto after_15;
    // 0x80055BA0: nop

    after_15:
    // 0x80055BA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80055BA8: lbu         $t4, -0xDAC($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0XDAC);
    // 0x80055BAC: nop

    // 0x80055BB0: beq         $t4, $zero, L_800568B0
    if (ctx->r12 == 0) {
        // 0x80055BB4: nop
    
            goto L_800568B0;
    }
    // 0x80055BB4: nop

    // 0x80055BB8: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80055BBC: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80055BC0: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80055BC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80055BC8: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    // 0x80055BCC: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x80055BD0: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x80055BD4: jal         0x8005BBFC
    // 0x80055BD8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    func_8005BBFC(rdram, ctx);
        goto after_16;
    // 0x80055BD8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_16:
    // 0x80055BDC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80055BE0: lbu         $t1, 0x154($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X154);
    // 0x80055BE4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80055BE8: lbu         $t0, -0xDAC($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0XDAC);
    // 0x80055BEC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80055BF0: sllv        $t9, $t2, $t1
    ctx->r25 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80055BF4: and         $t8, $t0, $t9
    ctx->r24 = ctx->r8 & ctx->r25;
    // 0x80055BF8: beq         $t8, $zero, L_80056888
    if (ctx->r24 == 0) {
        // 0x80055BFC: nop
    
            goto L_80056888;
    }
    // 0x80055BFC: nop

    // 0x80055C00: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80055C04: lbu         $s0, 0x148($s0)
    ctx->r16 = MEM_BU(ctx->r16, 0X148);
    // 0x80055C08: addiu       $t3, $zero, 0x1A
    ctx->r11 = ADD32(0, 0X1A);
    // 0x80055C0C: sb          $t3, 0x7B($sp)
    MEM_B(0X7B, ctx->r29) = ctx->r11;
    // 0x80055C10: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80055C14: beq         $s0, $zero, L_80055C38
    if (ctx->r16 == 0) {
        // 0x80055C18: sw          $zero, 0x70($sp)
        MEM_W(0X70, ctx->r29) = 0;
            goto L_80055C38;
    }
    // 0x80055C18: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80055C1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80055C20: beq         $s0, $at, L_80055F34
    if (ctx->r16 == ctx->r1) {
        // 0x80055C24: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80055F34;
    }
    // 0x80055C24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80055C28: beq         $s0, $at, L_800563B4
    if (ctx->r16 == ctx->r1) {
        // 0x80055C2C: nop
    
            goto L_800563B4;
    }
    // 0x80055C2C: nop

    // 0x80055C30: b           L_8005689C
    // 0x80055C34: nop

        goto L_8005689C;
    // 0x80055C34: nop

L_80055C38:
    // 0x80055C38: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80055C3C: lbu         $a1, 0x154($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X154);
    // 0x80055C40: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80055C44: jal         0x8003B684
    // 0x80055C48: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    FUN_001050_cpakInit(rdram, ctx);
        goto after_17;
    // 0x80055C48: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    after_17:
    // 0x80055C4C: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80055C50: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80055C54: nop

    // 0x80055C58: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x80055C5C: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x80055C60: beq         $t7, $zero, L_80055C78
    if (ctx->r15 == 0) {
        // 0x80055C64: nop
    
            goto L_80055C78;
    }
    // 0x80055C64: nop

    // 0x80055C68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055C6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055C70: b           L_80057068
    // 0x80055C74: sb          $t6, 0x148($at)
    MEM_B(0X148, ctx->r1) = ctx->r14;
        goto L_80057068;
    // 0x80055C74: sb          $t6, 0x148($at)
    MEM_B(0X148, ctx->r1) = ctx->r14;
L_80055C78:
    // 0x80055C78: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80055C7C: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x80055C80: jal         0x800B7450
    // 0x80055C84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bzero_recomp(rdram, ctx);
        goto after_18;
    // 0x80055C84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x80055C88: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80055C8C: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    // 0x80055C90: jal         0x800B7450
    // 0x80055C94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    bzero_recomp(rdram, ctx);
        goto after_19;
    // 0x80055C94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_19:
    // 0x80055C98: lui         $t1, 0x4E52
    ctx->r9 = S32(0X4E52 << 16);
    // 0x80055C9C: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80055CA0: ori         $t1, $t1, 0x4945
    ctx->r9 = ctx->r9 | 0X4945;
    // 0x80055CA4: addiu       $t0, $zero, 0x3031
    ctx->r8 = ADD32(0, 0X3031);
    // 0x80055CA8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80055CAC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80055CB0: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x80055CB4: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80055CB8: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x80055CBC: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x80055CC0: addiu       $t5, $zero, 0x2B
    ctx->r13 = ADD32(0, 0X2B);
    // 0x80055CC4: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x80055CC8: addiu       $t6, $zero, 0x2C
    ctx->r14 = ADD32(0, 0X2C);
    // 0x80055CCC: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x80055CD0: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x80055CD4: sh          $t0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r8;
    // 0x80055CD8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80055CDC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80055CE0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80055CE4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80055CE8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80055CEC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80055CF0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80055CF4: addiu       $a1, $a1, -0x2F60
    ctx->r5 = ADD32(ctx->r5, -0X2F60);
    // 0x80055CF8: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    // 0x80055CFC: addiu       $a2, $zero, 0x27
    ctx->r6 = ADD32(0, 0X27);
    // 0x80055D00: jal         0x800B62D4
    // 0x80055D04: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    sprintf_recomp(rdram, ctx);
        goto after_20;
    // 0x80055D04: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_20:
    // 0x80055D08: lbu         $t2, 0x7B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X7B);
    // 0x80055D0C: addiu       $t1, $sp, 0x7C
    ctx->r9 = ADD32(ctx->r29, 0X7C);
    // 0x80055D10: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80055D14: jal         0x8007E03C
    // 0x80055D18: sb          $t2, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r10;
    n64HeapAlloc(rdram, ctx);
        goto after_21;
    // 0x80055D18: sb          $t2, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r10;
    after_21:
    // 0x80055D1C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80055D20: sb          $zero, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = 0;
    // 0x80055D24: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80055D28: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
L_80055D2C:
    // 0x80055D2C: lbu         $t0, 0x7B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X7B);
    // 0x80055D30: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80055D34: addiu       $t3, $sp, 0x7C
    ctx->r11 = ADD32(ctx->r29, 0X7C);
    // 0x80055D38: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x80055D3C: sb          $t8, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r24;
    // 0x80055D40: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80055D44: lbu         $a2, 0x154($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X154);
    // 0x80055D48: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80055D4C: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x80055D50: jal         0x8003B8F4
    // 0x80055D54: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    FUN_001050_cpakFindFile(rdram, ctx);
        goto after_22;
    // 0x80055D54: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    after_22:
    // 0x80055D58: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80055D5C: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80055D60: nop

    // 0x80055D64: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x80055D68: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x80055D6C: bne         $t7, $zero, L_80055E98
    if (ctx->r15 != 0) {
        // 0x80055D70: nop
    
            goto L_80055E98;
    }
    // 0x80055D70: nop

    // 0x80055D74: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80055D78: lbu         $t2, 0x154($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X154);
    // 0x80055D7C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80055D80: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80055D84: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x80055D88: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x80055D8C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80055D90: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80055D94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80055D98: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80055D9C: jal         0x8003B6E8
    // 0x80055DA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    FUN_001050_cpakRead(rdram, ctx);
        goto after_23;
    // 0x80055DA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_23:
    // 0x80055DA4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80055DA8: lbu         $t0, 0x154($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X154);
    // 0x80055DAC: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x80055DB0: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80055DB4: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80055DB8: addu        $t8, $t1, $t9
    ctx->r24 = ADD32(ctx->r9, ctx->r25);
    // 0x80055DBC: lw          $t3, 0x3C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X3C);
    // 0x80055DC0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80055DC4: lbu         $a1, 0x9($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X9);
    // 0x80055DC8: lbu         $a2, 0xA($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0XA);
    // 0x80055DCC: jal         0x8007AADC
    // 0x80055DD0: nop

    displayText_MatchXY(rdram, ctx);
        goto after_24;
    // 0x80055DD0: nop

    after_24:
    // 0x80055DD4: beq         $v0, $zero, L_80055EB8
    if (ctx->r2 == 0) {
        // 0x80055DD8: nop
    
            goto L_80055EB8;
    }
    // 0x80055DD8: nop

    // 0x80055DDC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80055DE0: jal         0x800B7450
    // 0x80055DE4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    bzero_recomp(rdram, ctx);
        goto after_25;
    // 0x80055DE4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_25:
    // 0x80055DE8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80055DEC: lbu         $t7, 0x154($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X154);
    // 0x80055DF0: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x80055DF4: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80055DF8: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80055DFC: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    // 0x80055E00: jal         0x8007B420
    // 0x80055E04: nop

    displayText_DeserializeTable(rdram, ctx);
        goto after_26;
    // 0x80055E04: nop

    after_26:
    // 0x80055E08: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80055E0C: lbu         $t0, 0x154($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X154);
    // 0x80055E10: lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XFC);
    // 0x80055E14: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80055E18: addu        $t9, $t2, $t1
    ctx->r25 = ADD32(ctx->r10, ctx->r9);
    // 0x80055E1C: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    // 0x80055E20: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80055E24: jal         0x8007AF88
    // 0x80055E28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    displayText_EncodeEntry(rdram, ctx);
        goto after_27;
    // 0x80055E28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80055E2C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80055E30: lbu         $t3, 0x154($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X154);
    // 0x80055E34: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80055E38: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80055E3C: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80055E40: addiu       $a0, $a0, -0x21C0
    ctx->r4 = ADD32(ctx->r4, -0X21C0);
    // 0x80055E44: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80055E48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80055E4C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80055E50: jal         0x8003B7A8
    // 0x80055E54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    FUN_001050_cpakWrite(rdram, ctx);
        goto after_28;
    // 0x80055E54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_28:
    // 0x80055E58: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80055E5C: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80055E60: nop

    // 0x80055E64: srl         $t5, $t7, 4
    ctx->r13 = S32(U32(ctx->r15) >> 4);
    // 0x80055E68: andi        $t4, $t5, 0xF
    ctx->r12 = ctx->r13 & 0XF;
    // 0x80055E6C: beq         $t4, $zero, L_80055E90
    if (ctx->r12 == 0) {
        // 0x80055E70: nop
    
            goto L_80055E90;
    }
    // 0x80055E70: nop

    // 0x80055E74: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80055E78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055E7C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80055E80: jal         0x8007E328
    // 0x80055E84: sb          $t6, 0x148($at)
    MEM_B(0X148, ctx->r1) = ctx->r14;
    n64HeapUnalloc(rdram, ctx);
        goto after_29;
    // 0x80055E84: sb          $t6, 0x148($at)
    MEM_B(0X148, ctx->r1) = ctx->r14;
    after_29:
    // 0x80055E88: b           L_80057068
    // 0x80055E8C: nop

        goto L_80057068;
    // 0x80055E8C: nop

L_80055E90:
    // 0x80055E90: b           L_80055ED0
    // 0x80055E94: sb          $zero, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = 0;
        goto L_80055ED0;
    // 0x80055E94: sb          $zero, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = 0;
L_80055E98:
    // 0x80055E98: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80055E9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80055EA0: srl         $t2, $t0, 4
    ctx->r10 = S32(U32(ctx->r8) >> 4);
    // 0x80055EA4: andi        $t1, $t2, 0xF
    ctx->r9 = ctx->r10 & 0XF;
    // 0x80055EA8: bne         $t1, $at, L_80055EB8
    if (ctx->r9 != ctx->r1) {
        // 0x80055EAC: nop
    
            goto L_80055EB8;
    }
    // 0x80055EAC: nop

    // 0x80055EB0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80055EB4: sb          $t9, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r25;
L_80055EB8:
    // 0x80055EB8: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80055EBC: nop

    // 0x80055EC0: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x80055EC4: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x80055EC8: bne         $at, $zero, L_80055D2C
    if (ctx->r1 != 0) {
        // 0x80055ECC: sw          $t3, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r11;
            goto L_80055D2C;
    }
    // 0x80055ECC: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
L_80055ED0:
    // 0x80055ED0: lbu         $t7, 0x6B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X6B);
    // 0x80055ED4: nop

    // 0x80055ED8: beq         $t7, $zero, L_80055EFC
    if (ctx->r15 == 0) {
        // 0x80055EDC: nop
    
            goto L_80055EFC;
    }
    // 0x80055EDC: nop

    // 0x80055EE0: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80055EE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055EE8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80055EEC: jal         0x8007E328
    // 0x80055EF0: sb          $t5, 0x148($at)
    MEM_B(0X148, ctx->r1) = ctx->r13;
    n64HeapUnalloc(rdram, ctx);
        goto after_30;
    // 0x80055EF0: sb          $t5, 0x148($at)
    MEM_B(0X148, ctx->r1) = ctx->r13;
    after_30:
    // 0x80055EF4: b           L_80057068
    // 0x80055EF8: nop

        goto L_80057068;
    // 0x80055EF8: nop

L_80055EFC:
    // 0x80055EFC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80055F00: jal         0x8007E328
    // 0x80055F04: nop

    n64HeapUnalloc(rdram, ctx);
        goto after_31;
    // 0x80055F04: nop

    after_31:
    // 0x80055F08: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80055F0C: lbu         $t4, 0x154($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X154);
    // 0x80055F10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80055F14: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80055F18: lbu         $t1, -0xDAC($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0XDAC);
    // 0x80055F1C: sllv        $t0, $t6, $t4
    ctx->r8 = S32(ctx->r14 << (ctx->r12 & 31));
    // 0x80055F20: nor         $t2, $t0, $zero
    ctx->r10 = ~(ctx->r8 | 0);
    // 0x80055F24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055F28: and         $t9, $t2, $t1
    ctx->r25 = ctx->r10 & ctx->r9;
    // 0x80055F2C: b           L_8005689C
    // 0x80055F30: sb          $t9, -0xDAC($at)
    MEM_B(-0XDAC, ctx->r1) = ctx->r25;
        goto L_8005689C;
    // 0x80055F30: sb          $t9, -0xDAC($at)
    MEM_B(-0XDAC, ctx->r1) = ctx->r25;
L_80055F34:
    // 0x80055F34: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80055F38: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80055F3C: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x80055F40: lw          $a1, -0xDA8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XDA8);
    // 0x80055F44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80055F48: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80055F4C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80055F50: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80055F54: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80055F58: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80055F5C: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
    // 0x80055F60: sw          $t3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r11;
    // 0x80055F64: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80055F68: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80055F6C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80055F70: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80055F74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80055F78: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80055F7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80055F80: jal         0x80057460
    // 0x80055F84: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_32;
    // 0x80055F84: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_32:
    // 0x80055F88: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80055F8C: lbu         $t1, 0x154($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X154);
    // 0x80055F90: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x80055F94: sll         $t9, $t1, 3
    ctx->r25 = S32(ctx->r9 << 3);
    // 0x80055F98: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x80055F9C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80055FA0: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x80055FA4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80055FA8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80055FAC: addiu       $a1, $a1, -0x2F4C
    ctx->r5 = ADD32(ctx->r5, -0X2F4C);
    // 0x80055FB0: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80055FB4: jal         0x800B62D4
    // 0x80055FB8: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
    sprintf_recomp(rdram, ctx);
        goto after_33;
    // 0x80055FB8: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
    after_33:
    // 0x80055FBC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80055FC0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80055FC4: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80055FC8: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80055FCC: addiu       $t8, $sp, 0xB8
    ctx->r24 = ADD32(ctx->r29, 0XB8);
    // 0x80055FD0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80055FD4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80055FD8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80055FDC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80055FE0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80055FE4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80055FE8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80055FEC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80055FF0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80055FF4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x80055FF8: jal         0x80077960
    // 0x80055FFC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_34;
    // 0x80055FFC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_34:
    // 0x80056000: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80056004: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80056008: addiu       $t1, $t1, -0x2F48
    ctx->r9 = ADD32(ctx->r9, -0X2F48);
    // 0x8005600C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056010: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056014: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80056018: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005601C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80056020: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80056024: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80056028: addiu       $t0, $t4, 0xF
    ctx->r8 = ADD32(ctx->r12, 0XF);
    // 0x8005602C: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    // 0x80056030: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80056034: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80056038: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8005603C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80056040: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80056044: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x80056048: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x8005604C: jal         0x80077960
    // 0x80056050: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_35;
    // 0x80056050: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_35:
    // 0x80056054: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x80056058: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8005605C: lbu         $a2, 0x154($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X154);
    // 0x80056060: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056064: addiu       $t5, $t7, 0xF
    ctx->r13 = ADD32(ctx->r15, 0XF);
    // 0x80056068: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x8005606C: addiu       $a1, $a1, -0x2F24
    ctx->r5 = ADD32(ctx->r5, -0X2F24);
    // 0x80056070: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80056074: jal         0x800B62D4
    // 0x80056078: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_36;
    // 0x80056078: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_36:
    // 0x8005607C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056080: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056084: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80056088: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x8005608C: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x80056090: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80056094: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80056098: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8005609C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800560A0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800560A4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800560A8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800560AC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800560B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800560B4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800560B8: jal         0x80077960
    // 0x800560BC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_37;
    // 0x800560BC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_37:
    // 0x800560C0: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800560C4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800560C8: addiu       $t3, $t3, -0x2EFC
    ctx->r11 = ADD32(ctx->r11, -0X2EFC);
    // 0x800560CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800560D0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800560D4: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x800560D8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800560DC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800560E0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800560E4: addiu       $t8, $t9, 0x14
    ctx->r24 = ADD32(ctx->r25, 0X14);
    // 0x800560E8: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x800560EC: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800560F0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800560F4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800560F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800560FC: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x80056100: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056104: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80056108: jal         0x80077960
    // 0x8005610C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_38;
    // 0x8005610C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_38:
    // 0x80056110: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80056114: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056118: addiu       $a1, $a1, -0x2EF4
    ctx->r5 = ADD32(ctx->r5, -0X2EF4);
    // 0x8005611C: jal         0x80077D88
    // 0x80056120: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    Font_GetTextWidth(rdram, ctx);
        goto after_39;
    // 0x80056120: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    after_39:
    // 0x80056124: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x80056128: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005612C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80056130: addiu       $t1, $t1, -0x2EEC
    ctx->r9 = ADD32(ctx->r9, -0X2EEC);
    // 0x80056134: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056138: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005613C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80056140: addiu       $t2, $zero, 0x5A
    ctx->r10 = ADD32(0, 0X5A);
    // 0x80056144: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80056148: addiu       $t8, $zero, 0xB9
    ctx->r24 = ADD32(0, 0XB9);
    // 0x8005614C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80056150: addu        $t0, $t4, $s0
    ctx->r8 = ADD32(ctx->r12, ctx->r16);
    // 0x80056154: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    // 0x80056158: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8005615C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80056160: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80056164: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80056168: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8005616C: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x80056170: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056174: jal         0x80077960
    // 0x80056178: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_40;
    // 0x80056178: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_40:
    // 0x8005617C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80056180: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056184: addiu       $a1, $a1, -0x2EE8
    ctx->r5 = ADD32(ctx->r5, -0X2EE8);
    // 0x80056188: jal         0x80077D88
    // 0x8005618C: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    Font_GetTextWidth(rdram, ctx);
        goto after_41;
    // 0x8005618C: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    after_41:
    // 0x80056190: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80056194: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80056198: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005619C: addiu       $t6, $t6, -0x2EE4
    ctx->r14 = ADD32(ctx->r14, -0X2EE4);
    // 0x800561A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800561A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800561A8: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x800561AC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800561B0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800561B4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800561B8: addu        $t5, $t7, $s0
    ctx->r13 = ADD32(ctx->r15, ctx->r16);
    // 0x800561BC: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    // 0x800561C0: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800561C4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800561C8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800561CC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800561D0: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x800561D4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800561D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800561DC: jal         0x80077960
    // 0x800561E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_42;
    // 0x800561E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_42:
    // 0x800561E4: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x800561E8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800561EC: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x800561F0: addiu       $t3, $t3, -0x2EDC
    ctx->r11 = ADD32(ctx->r11, -0X2EDC);
    // 0x800561F4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800561F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800561FC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80056200: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80056204: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80056208: addiu       $t9, $t2, 0x11
    ctx->r25 = ADD32(ctx->r10, 0X11);
    // 0x8005620C: sw          $t9, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r25;
    // 0x80056210: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
    // 0x80056214: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80056218: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8005621C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80056220: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80056224: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x80056228: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x8005622C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80056230: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80056234: jal         0x80077960
    // 0x80056238: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_43;
    // 0x80056238: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_43:
    // 0x8005623C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80056240: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056244: addiu       $a1, $a1, -0x2ED4
    ctx->r5 = ADD32(ctx->r5, -0X2ED4);
    // 0x80056248: jal         0x80077D88
    // 0x8005624C: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    Font_GetTextWidth(rdram, ctx);
        goto after_44;
    // 0x8005624C: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    after_44:
    // 0x80056250: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x80056254: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80056258: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8005625C: addiu       $t1, $t1, -0x2ECC
    ctx->r9 = ADD32(ctx->r9, -0X2ECC);
    // 0x80056260: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056264: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056268: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x8005626C: addiu       $t2, $zero, 0x70
    ctx->r10 = ADD32(0, 0X70);
    // 0x80056270: addiu       $t8, $zero, 0xC3
    ctx->r24 = ADD32(0, 0XC3);
    // 0x80056274: addiu       $t9, $zero, 0x74
    ctx->r25 = ADD32(0, 0X74);
    // 0x80056278: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8005627C: addu        $t0, $t4, $s0
    ctx->r8 = ADD32(ctx->r12, ctx->r16);
    // 0x80056280: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    // 0x80056284: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80056288: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8005628C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80056290: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80056294: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80056298: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x8005629C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800562A0: jal         0x80077960
    // 0x800562A4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_45;
    // 0x800562A4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_45:
    // 0x800562A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800562AC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800562B0: addiu       $a1, $a1, -0x2EC8
    ctx->r5 = ADD32(ctx->r5, -0X2EC8);
    // 0x800562B4: jal         0x80077D88
    // 0x800562B8: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    Font_GetTextWidth(rdram, ctx);
        goto after_46;
    // 0x800562B8: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    after_46:
    // 0x800562BC: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x800562C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800562C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800562C8: addiu       $t6, $t6, -0x2EC4
    ctx->r14 = ADD32(ctx->r14, -0X2EC4);
    // 0x800562CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800562D0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800562D4: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x800562D8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800562DC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800562E0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800562E4: addu        $t5, $t7, $s0
    ctx->r13 = ADD32(ctx->r15, ctx->r16);
    // 0x800562E8: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    // 0x800562EC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800562F0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800562F4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800562F8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800562FC: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x80056300: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056304: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80056308: jal         0x80077960
    // 0x8005630C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_47;
    // 0x8005630C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_47:
    // 0x80056310: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80056314: lbu         $t2, 0x154($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X154);
    // 0x80056318: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005631C: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x80056320: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x80056324: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80056328: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x8005632C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80056330: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80056334: lw          $t9, -0x10AC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X10AC);
    // 0x80056338: nop

    // 0x8005633C: andi        $t3, $t9, 0x8000
    ctx->r11 = ctx->r25 & 0X8000;
    // 0x80056340: beq         $t3, $zero, L_80056350
    if (ctx->r11 == 0) {
        // 0x80056344: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80056350;
    }
    // 0x80056344: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056348: b           L_80057068
    // 0x8005634C: sb          $zero, 0x148($at)
    MEM_B(0X148, ctx->r1) = 0;
        goto L_80057068;
    // 0x8005634C: sb          $zero, 0x148($at)
    MEM_B(0X148, ctx->r1) = 0;
L_80056350:
    // 0x80056350: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80056354: lbu         $t7, 0x154($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X154);
    // 0x80056358: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005635C: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80056360: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x80056364: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80056368: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x8005636C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80056370: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80056374: lw          $t6, -0x10AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X10AC);
    // 0x80056378: nop

    // 0x8005637C: andi        $t4, $t6, 0x4000
    ctx->r12 = ctx->r14 & 0X4000;
    // 0x80056380: beq         $t4, $zero, L_8005689C
    if (ctx->r12 == 0) {
        // 0x80056384: nop
    
            goto L_8005689C;
    }
    // 0x80056384: nop

    // 0x80056388: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005638C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80056390: lbu         $t8, -0xDAC($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0XDAC);
    // 0x80056394: sllv        $t1, $t0, $t7
    ctx->r9 = S32(ctx->r8 << (ctx->r15 & 31));
    // 0x80056398: nor         $t2, $t1, $zero
    ctx->r10 = ~(ctx->r9 | 0);
    // 0x8005639C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800563A0: and         $t9, $t2, $t8
    ctx->r25 = ctx->r10 & ctx->r24;
    // 0x800563A4: sb          $t9, -0xDAC($at)
    MEM_B(-0XDAC, ctx->r1) = ctx->r25;
    // 0x800563A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800563AC: b           L_80057068
    // 0x800563B0: sb          $zero, 0x148($at)
    MEM_B(0X148, ctx->r1) = 0;
        goto L_80057068;
    // 0x800563B0: sb          $zero, 0x148($at)
    MEM_B(0X148, ctx->r1) = 0;
L_800563B4:
    // 0x800563B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800563B8: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x800563BC: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x800563C0: lw          $a1, -0xDA8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XDA8);
    // 0x800563C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800563C8: addiu       $t6, $zero, 0x29
    ctx->r14 = ADD32(0, 0X29);
    // 0x800563CC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800563D0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800563D4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800563D8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800563DC: sw          $t3, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r11;
    // 0x800563E0: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    // 0x800563E4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800563E8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800563EC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800563F0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800563F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800563F8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800563FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80056400: jal         0x80057460
    // 0x80056404: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_48;
    // 0x80056404: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    after_48:
    // 0x80056408: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8005640C: lbu         $t8, 0x154($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X154);
    // 0x80056410: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x80056414: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80056418: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005641C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80056420: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80056424: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80056428: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005642C: addiu       $a1, $a1, -0x2EB8
    ctx->r5 = ADD32(ctx->r5, -0X2EB8);
    // 0x80056430: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80056434: jal         0x800B62D4
    // 0x80056438: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
    sprintf_recomp(rdram, ctx);
        goto after_49;
    // 0x80056438: addu        $a2, $t2, $t9
    ctx->r6 = ADD32(ctx->r10, ctx->r25);
    after_49:
    // 0x8005643C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056440: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056444: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80056448: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x8005644C: addiu       $t3, $sp, 0xB8
    ctx->r11 = ADD32(ctx->r29, 0XB8);
    // 0x80056450: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80056454: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80056458: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8005645C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80056460: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80056464: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80056468: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8005646C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80056470: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80056474: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x80056478: jal         0x80077960
    // 0x8005647C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_50;
    // 0x8005647C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_50:
    // 0x80056480: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x80056484: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80056488: addiu       $t8, $t8, -0x2EB4
    ctx->r24 = ADD32(ctx->r24, -0X2EB4);
    // 0x8005648C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056490: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056494: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80056498: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005649C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800564A0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800564A4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800564A8: addiu       $t1, $t7, 0xF
    ctx->r9 = ADD32(ctx->r15, 0XF);
    // 0x800564AC: sw          $t1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r9;
    // 0x800564B0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800564B4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800564B8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800564BC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800564C0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800564C4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800564C8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800564CC: jal         0x80077960
    // 0x800564D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_51;
    // 0x800564D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_51:
    // 0x800564D4: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800564D8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800564DC: addiu       $t0, $t0, -0x2E8C
    ctx->r8 = ADD32(ctx->r8, -0X2E8C);
    // 0x800564E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800564E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800564E8: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x800564EC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800564F0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800564F4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800564F8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800564FC: addiu       $t4, $t6, 0xE
    ctx->r12 = ADD32(ctx->r14, 0XE);
    // 0x80056500: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
    // 0x80056504: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x80056508: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8005650C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80056510: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80056514: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80056518: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x8005651C: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056520: jal         0x80077960
    // 0x80056524: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_52;
    // 0x80056524: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_52:
    // 0x80056528: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x8005652C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80056530: lbu         $a2, 0x154($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X154);
    // 0x80056534: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056538: addiu       $t3, $t9, 0xE
    ctx->r11 = ADD32(ctx->r25, 0XE);
    // 0x8005653C: sw          $t3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r11;
    // 0x80056540: addiu       $a1, $a1, -0x2E64
    ctx->r5 = ADD32(ctx->r5, -0X2E64);
    // 0x80056544: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80056548: jal         0x800B62D4
    // 0x8005654C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_53;
    // 0x8005654C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_53:
    // 0x80056550: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056554: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056558: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x8005655C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80056560: addiu       $t5, $sp, 0xB8
    ctx->r13 = ADD32(ctx->r29, 0XB8);
    // 0x80056564: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80056568: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8005656C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80056570: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80056574: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80056578: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8005657C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80056580: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80056584: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80056588: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x8005658C: jal         0x80077960
    // 0x80056590: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_54;
    // 0x80056590: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_54:
    // 0x80056594: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x80056598: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8005659C: addiu       $t2, $t2, -0x2E3C
    ctx->r10 = ADD32(ctx->r10, -0X2E3C);
    // 0x800565A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800565A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800565A8: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x800565AC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800565B0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800565B4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800565B8: addiu       $t8, $t1, 0x11
    ctx->r24 = ADD32(ctx->r9, 0X11);
    // 0x800565BC: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x800565C0: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800565C4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800565C8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800565CC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800565D0: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800565D4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800565D8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800565DC: jal         0x80077960
    // 0x800565E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_55;
    // 0x800565E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_55:
    // 0x800565E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800565E8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800565EC: addiu       $a1, $a1, -0x2E34
    ctx->r5 = ADD32(ctx->r5, -0X2E34);
    // 0x800565F0: jal         0x80077D88
    // 0x800565F4: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_56;
    // 0x800565F4: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_56:
    // 0x800565F8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x800565FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80056600: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80056604: addiu       $t0, $t0, -0x2E2C
    ctx->r8 = ADD32(ctx->r8, -0X2E2C);
    // 0x80056608: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005660C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056610: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80056614: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80056618: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x8005661C: addiu       $t8, $zero, 0xB9
    ctx->r24 = ADD32(0, 0XB9);
    // 0x80056620: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80056624: addu        $t4, $t6, $s0
    ctx->r12 = ADD32(ctx->r14, ctx->r16);
    // 0x80056628: sw          $t4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r12;
    // 0x8005662C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80056630: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80056634: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80056638: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8005663C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80056640: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x80056644: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056648: jal         0x80077960
    // 0x8005664C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_57;
    // 0x8005664C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_57:
    // 0x80056650: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80056654: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056658: addiu       $a1, $a1, -0x2E28
    ctx->r5 = ADD32(ctx->r5, -0X2E28);
    // 0x8005665C: jal         0x80077D88
    // 0x80056660: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_58;
    // 0x80056660: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_58:
    // 0x80056664: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80056668: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005666C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80056670: addiu       $t5, $t5, -0x2E24
    ctx->r13 = ADD32(ctx->r13, -0X2E24);
    // 0x80056674: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056678: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005667C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80056680: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80056684: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80056688: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8005668C: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x80056690: sw          $t3, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r11;
    // 0x80056694: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80056698: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8005669C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800566A0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800566A4: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800566A8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800566AC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800566B0: jal         0x80077960
    // 0x800566B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_59;
    // 0x800566B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_59:
    // 0x800566B8: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800566BC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800566C0: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x800566C4: addiu       $t2, $t2, -0x2E14
    ctx->r10 = ADD32(ctx->r10, -0X2E14);
    // 0x800566C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800566CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800566D0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800566D4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800566D8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800566DC: addiu       $t1, $t7, 0xD
    ctx->r9 = ADD32(ctx->r15, 0XD);
    // 0x800566E0: sw          $t1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r9;
    // 0x800566E4: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
    // 0x800566E8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800566EC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800566F0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800566F4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800566F8: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800566FC: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056700: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80056704: addiu       $a2, $zero, 0x3A
    ctx->r6 = ADD32(0, 0X3A);
    // 0x80056708: jal         0x80077960
    // 0x8005670C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_60;
    // 0x8005670C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_60:
    // 0x80056710: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80056714: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056718: addiu       $a1, $a1, -0x2E0C
    ctx->r5 = ADD32(ctx->r5, -0X2E0C);
    // 0x8005671C: jal         0x80077D88
    // 0x80056720: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_61;
    // 0x80056720: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_61:
    // 0x80056724: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80056728: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005672C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80056730: addiu       $t0, $t0, -0x2E04
    ctx->r8 = ADD32(ctx->r8, -0X2E04);
    // 0x80056734: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056738: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005673C: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x80056740: addiu       $t7, $zero, 0x70
    ctx->r15 = ADD32(0, 0X70);
    // 0x80056744: addiu       $t8, $zero, 0xC3
    ctx->r24 = ADD32(0, 0XC3);
    // 0x80056748: addiu       $t1, $zero, 0x74
    ctx->r9 = ADD32(0, 0X74);
    // 0x8005674C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80056750: addu        $t4, $t6, $s0
    ctx->r12 = ADD32(ctx->r14, ctx->r16);
    // 0x80056754: sw          $t4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r12;
    // 0x80056758: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8005675C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80056760: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80056764: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80056768: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8005676C: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x80056770: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056774: jal         0x80077960
    // 0x80056778: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_62;
    // 0x80056778: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_62:
    // 0x8005677C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80056780: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056784: addiu       $a1, $a1, -0x2E00
    ctx->r5 = ADD32(ctx->r5, -0X2E00);
    // 0x80056788: jal         0x80077D88
    // 0x8005678C: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    Font_GetTextWidth(rdram, ctx);
        goto after_63;
    // 0x8005678C: addiu       $a0, $a0, -0x7060
    ctx->r4 = ADD32(ctx->r4, -0X7060);
    after_63:
    // 0x80056790: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80056794: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80056798: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005679C: addiu       $t5, $t5, -0x2DFC
    ctx->r13 = ADD32(ctx->r13, -0X2DFC);
    // 0x800567A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800567A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800567A8: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    // 0x800567AC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800567B0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800567B4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800567B8: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800567BC: sw          $t3, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r11;
    // 0x800567C0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800567C4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800567C8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800567CC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800567D0: addiu       $a1, $a1, -0x7060
    ctx->r5 = ADD32(ctx->r5, -0X7060);
    // 0x800567D4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800567D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800567DC: jal         0x80077960
    // 0x800567E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_64;
    // 0x800567E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_64:
    // 0x800567E4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800567E8: lbu         $t7, 0x154($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X154);
    // 0x800567EC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800567F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800567F4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800567F8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800567FC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80056800: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80056804: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80056808: lw          $t1, -0x10AC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X10AC);
    // 0x8005680C: nop

    // 0x80056810: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x80056814: beq         $t2, $zero, L_80056824
    if (ctx->r10 == 0) {
        // 0x80056818: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80056824;
    }
    // 0x80056818: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005681C: b           L_80057068
    // 0x80056820: sb          $zero, 0x148($at)
    MEM_B(0X148, ctx->r1) = 0;
        goto L_80057068;
    // 0x80056820: sb          $zero, 0x148($at)
    MEM_B(0X148, ctx->r1) = 0;
L_80056824:
    // 0x80056824: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80056828: lbu         $t9, 0x154($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X154);
    // 0x8005682C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80056830: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80056834: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x80056838: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8005683C: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x80056840: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80056844: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80056848: lw          $t5, -0x10AC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X10AC);
    // 0x8005684C: nop

    // 0x80056850: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x80056854: beq         $t6, $zero, L_8005689C
    if (ctx->r14 == 0) {
        // 0x80056858: nop
    
            goto L_8005689C;
    }
    // 0x80056858: nop

    // 0x8005685C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80056860: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80056864: lbu         $t8, -0xDAC($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0XDAC);
    // 0x80056868: sllv        $t0, $t4, $t9
    ctx->r8 = S32(ctx->r12 << (ctx->r25 & 31));
    // 0x8005686C: nor         $t7, $t0, $zero
    ctx->r15 = ~(ctx->r8 | 0);
    // 0x80056870: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80056874: and         $t1, $t7, $t8
    ctx->r9 = ctx->r15 & ctx->r24;
    // 0x80056878: sb          $t1, -0xDAC($at)
    MEM_B(-0XDAC, ctx->r1) = ctx->r9;
    // 0x8005687C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056880: b           L_80057068
    // 0x80056884: sb          $zero, 0x148($at)
    MEM_B(0X148, ctx->r1) = 0;
        goto L_80057068;
    // 0x80056884: sb          $zero, 0x148($at)
    MEM_B(0X148, ctx->r1) = 0;
L_80056888:
    // 0x80056888: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005688C: lbu         $t2, 0x154($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X154);
    // 0x80056890: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056894: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80056898: sb          $t3, 0x154($at)
    MEM_B(0X154, ctx->r1) = ctx->r11;
L_8005689C:
    // 0x8005689C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800568A0: jal         0x8005BE40
    // 0x800568A4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_65;
    // 0x800568A4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_65:
    // 0x800568A8: b           L_80057068
    // 0x800568AC: nop

        goto L_80057068;
    // 0x800568AC: nop

L_800568B0:
    // 0x800568B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800568B4: jal         0x8005BBFC
    // 0x800568B8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    func_8005BBFC(rdram, ctx);
        goto after_66;
    // 0x800568B8: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_66:
    // 0x800568BC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800568C0: lw          $t5, 0x20C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X20C0);
    // 0x800568C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800568C8: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x800568CC: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800568D0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800568D4: sw          $t6, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r14;
    // 0x800568D8: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800568DC: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x800568E0: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800568E4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800568E8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800568EC: lw          $t7, 0x144($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X144);
    // 0x800568F0: nop

    // 0x800568F4: bne         $t7, $zero, L_80057068
    if (ctx->r15 != 0) {
        // 0x800568F8: nop
    
            goto L_80057068;
    }
    // 0x800568F8: nop

    // 0x800568FC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80056900: lw          $t8, 0x150($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X150);
    // 0x80056904: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x80056908: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005690C: addiu       $t2, $zero, 0x5A
    ctx->r10 = ADD32(0, 0X5A);
    // 0x80056910: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80056914: sw          $t1, 0x150($at)
    MEM_W(0X150, ctx->r1) = ctx->r9;
    // 0x80056918: sw          $t2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r10;
    // 0x8005691C: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80056920: lbu         $t5, 0x5($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X5);
    // 0x80056924: nop

    // 0x80056928: blez        $t5, L_80056B54
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005692C: nop
    
            goto L_80056B54;
    }
    // 0x8005692C: nop

L_80056930:
    // 0x80056930: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x80056934: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80056938: sll         $t4, $t6, 3
    ctx->r12 = S32(ctx->r14 << 3);
    // 0x8005693C: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x80056940: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x80056944: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80056948: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8005694C: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x80056950: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80056954: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80056958: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8005695C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056960: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80056964: addu        $t0, $t4, $t9
    ctx->r8 = ADD32(ctx->r12, ctx->r25);
    // 0x80056968: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8005696C: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x80056970: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80056974: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80056978: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8005697C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80056980: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80056984: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80056988: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8005698C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80056990: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80056994: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80056998: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005699C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800569A0: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x800569A4: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x800569A8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800569AC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800569B0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800569B4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800569B8: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // 0x800569BC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800569C0: jal         0x80077960
    // 0x800569C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_67;
    // 0x800569C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_67:
    // 0x800569C8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800569CC: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x800569D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800569D4: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800569D8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800569DC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800569E0: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x800569E4: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x800569E8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800569EC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800569F0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800569F4: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800569F8: lw          $t5, 0x150($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X150);
    // 0x800569FC: nop

    // 0x80056A00: slti        $at, $t5, 0x5B
    ctx->r1 = SIGNED(ctx->r13) < 0X5B ? 1 : 0;
    // 0x80056A04: bne         $at, $zero, L_80056A60
    if (ctx->r1 != 0) {
        // 0x80056A08: nop
    
            goto L_80056A60;
    }
    // 0x80056A08: nop

    // 0x80056A0C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80056A10: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80056A14: jal         0x8007AA5C
    // 0x80056A18: addiu       $a0, $a0, 0x2D98
    ctx->r4 = ADD32(ctx->r4, 0X2D98);
    displayText_FindEntry(rdram, ctx);
        goto after_68;
    // 0x80056A18: addiu       $a0, $a0, 0x2D98
    ctx->r4 = ADD32(ctx->r4, 0X2D98);
    after_68:
    // 0x80056A1C: sw          $v0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r2;
    // 0x80056A20: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x80056A24: nop

    // 0x80056A28: beq         $t6, $zero, L_80056A48
    if (ctx->r14 == 0) {
        // 0x80056A2C: nop
    
            goto L_80056A48;
    }
    // 0x80056A2C: nop

    // 0x80056A30: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x80056A34: jal         0x80078300
    // 0x80056A38: nop

    FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(rdram, ctx);
        goto after_69;
    // 0x80056A38: nop

    after_69:
    // 0x80056A3C: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80056A40: b           L_80056A74
    // 0x80056A44: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
        goto L_80056A74;
    // 0x80056A44: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
L_80056A48:
    // 0x80056A48: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80056A4C: jal         0x80078300
    // 0x80056A50: nop

    FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(rdram, ctx);
        goto after_70;
    // 0x80056A50: nop

    after_70:
    // 0x80056A54: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80056A58: b           L_80056A74
    // 0x80056A5C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
        goto L_80056A74;
    // 0x80056A5C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_80056A60:
    // 0x80056A60: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80056A64: jal         0x80078300
    // 0x80056A68: nop

    FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(rdram, ctx);
        goto after_71;
    // 0x80056A68: nop

    after_71:
    // 0x80056A6C: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80056A70: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
L_80056A74:
    // 0x80056A74: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80056A78: lw          $t7, 0x20C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20C0);
    // 0x80056A7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056A80: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80056A84: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80056A88: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80056A8C: sw          $t8, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r24;
    // 0x80056A90: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80056A94: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80056A98: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80056A9C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056AA0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80056AA4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80056AA8: addiu       $a1, $a1, -0x2DF0
    ctx->r5 = ADD32(ctx->r5, -0X2DF0);
    // 0x80056AAC: jal         0x800B62D4
    // 0x80056AB0: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    sprintf_recomp(rdram, ctx);
        goto after_72;
    // 0x80056AB0: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_72:
    // 0x80056AB4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80056AB8: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // 0x80056ABC: jal         0x80077D88
    // 0x80056AC0: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    Font_GetTextWidth(rdram, ctx);
        goto after_73;
    // 0x80056AC0: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_73:
    // 0x80056AC4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80056AC8: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x80056ACC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056AD0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056AD4: addiu       $t6, $zero, 0xA6
    ctx->r14 = ADD32(0, 0XA6);
    // 0x80056AD8: addiu       $t4, $sp, 0xB8
    ctx->r12 = ADD32(ctx->r29, 0XB8);
    // 0x80056ADC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80056AE0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80056AE4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80056AE8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80056AEC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80056AF0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80056AF4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80056AF8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80056AFC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80056B00: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x80056B04: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056B08: bgez        $s0, L_80056B18
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80056B0C: sra         $t5, $s0, 1
        ctx->r13 = S32(SIGNED(ctx->r16) >> 1);
            goto L_80056B18;
    }
    // 0x80056B0C: sra         $t5, $s0, 1
    ctx->r13 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80056B10: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x80056B14: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_80056B18:
    // 0x80056B18: subu        $a2, $t6, $t5
    ctx->r6 = SUB32(ctx->r14, ctx->r13);
    // 0x80056B1C: jal         0x80077960
    // 0x80056B20: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_74;
    // 0x80056B20: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_74:
    // 0x80056B24: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x80056B28: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x80056B2C: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x80056B30: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80056B34: addiu       $t6, $t3, 0x19
    ctx->r14 = ADD32(ctx->r11, 0X19);
    // 0x80056B38: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x80056B3C: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
    // 0x80056B40: lbu         $t4, 0x5($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X5);
    // 0x80056B44: nop

    // 0x80056B48: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80056B4C: bne         $at, $zero, L_80056930
    if (ctx->r1 != 0) {
        // 0x80056B50: nop
    
            goto L_80056930;
    }
    // 0x80056B50: nop

L_80056B54:
    // 0x80056B54: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80056B58: lw          $t9, 0x150($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X150);
    // 0x80056B5C: nop

    // 0x80056B60: slti        $at, $t9, 0x1F
    ctx->r1 = SIGNED(ctx->r25) < 0X1F ? 1 : 0;
    // 0x80056B64: bne         $at, $zero, L_80056CD4
    if (ctx->r1 != 0) {
        // 0x80056B68: nop
    
            goto L_80056CD4;
    }
    // 0x80056B68: nop

    // 0x80056B6C: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x80056B70: addiu       $t0, $zero, 0x5D
    ctx->r8 = ADD32(0, 0X5D);
    // 0x80056B74: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x80056B78: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80056B7C: lbu         $t8, 0x5($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5);
    // 0x80056B80: nop

    // 0x80056B84: blez        $t8, L_80056CD4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80056B88: nop
    
            goto L_80056CD4;
    }
    // 0x80056B88: nop

L_80056B8C:
    // 0x80056B8C: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x80056B90: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x80056B94: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80056B98: addu        $t5, $t1, $t6
    ctx->r13 = ADD32(ctx->r9, ctx->r14);
    // 0x80056B9C: lw          $a2, 0x18($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X18);
    // 0x80056BA0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056BA4: addiu       $a1, $a1, -0x2DEC
    ctx->r5 = ADD32(ctx->r5, -0X2DEC);
    // 0x80056BA8: jal         0x800B62D4
    // 0x80056BAC: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    sprintf_recomp(rdram, ctx);
        goto after_75;
    // 0x80056BAC: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_75:
    // 0x80056BB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80056BB4: addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // 0x80056BB8: jal         0x80077D88
    // 0x80056BBC: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    Font_GetTextWidth(rdram, ctx);
        goto after_76;
    // 0x80056BBC: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    after_76:
    // 0x80056BC0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80056BC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056BC8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056BCC: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x80056BD0: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x80056BD4: addiu       $t9, $sp, 0xB8
    ctx->r25 = ADD32(ctx->r29, 0XB8);
    // 0x80056BD8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80056BDC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80056BE0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80056BE4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80056BE8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80056BEC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80056BF0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80056BF4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80056BF8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80056BFC: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x80056C00: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056C04: bgez        $s0, L_80056C14
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80056C08: sra         $t2, $s0, 1
        ctx->r10 = S32(SIGNED(ctx->r16) >> 1);
            goto L_80056C14;
    }
    // 0x80056C08: sra         $t2, $s0, 1
    ctx->r10 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80056C0C: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x80056C10: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_80056C14:
    // 0x80056C14: jal         0x80077960
    // 0x80056C18: subu        $a2, $t4, $t2
    ctx->r6 = SUB32(ctx->r12, ctx->r10);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_77;
    // 0x80056C18: subu        $a2, $t4, $t2
    ctx->r6 = SUB32(ctx->r12, ctx->r10);
    after_77:
    // 0x80056C1C: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x80056C20: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x80056C24: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80056C28: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x80056C2C: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x80056C30: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056C34: sll         $t2, $a0, 4
    ctx->r10 = S32(ctx->r4 << 4);
    // 0x80056C38: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x80056C3C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80056C40: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x80056C44: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80056C48: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80056C4C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80056C50: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80056C54: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80056C58: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80056C5C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80056C60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80056C64: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80056C68: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x80056C6C: jal         0x80071480
    // 0x80056C70: addiu       $a2, $zero, 0x14D
    ctx->r6 = ADD32(0, 0X14D);
    displayTimeFormatted_XY_RGBA(rdram, ctx);
        goto after_78;
    // 0x80056C70: addiu       $a2, $zero, 0x14D
    ctx->r6 = ADD32(0, 0X14D);
    after_78:
    // 0x80056C74: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80056C78: lw          $t3, 0x20C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X20C0);
    // 0x80056C7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056C80: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80056C84: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80056C88: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x80056C8C: sw          $t6, 0x20C0($at)
    MEM_W(0X20C0, ctx->r1) = ctx->r14;
    // 0x80056C90: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80056C94: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
    // 0x80056C98: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80056C9C: nop

    // 0x80056CA0: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80056CA4: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80056CA8: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80056CAC: lw          $t8, 0xFC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XFC);
    // 0x80056CB0: addiu       $t7, $t0, 0x19
    ctx->r15 = ADD32(ctx->r8, 0X19);
    // 0x80056CB4: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x80056CB8: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x80056CBC: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x80056CC0: lbu         $t3, 0x5($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X5);
    // 0x80056CC4: nop

    // 0x80056CC8: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80056CCC: bne         $at, $zero, L_80056B8C
    if (ctx->r1 != 0) {
        // 0x80056CD0: nop
    
            goto L_80056B8C;
    }
    // 0x80056CD0: nop

L_80056CD4:
    // 0x80056CD4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80056CD8: lw          $t6, 0x150($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X150);
    // 0x80056CDC: nop

    // 0x80056CE0: slti        $at, $t6, 0x3D
    ctx->r1 = SIGNED(ctx->r14) < 0X3D ? 1 : 0;
    // 0x80056CE4: bne         $at, $zero, L_80056DB8
    if (ctx->r1 != 0) {
        // 0x80056CE8: nop
    
            goto L_80056DB8;
    }
    // 0x80056CE8: nop

    // 0x80056CEC: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x80056CF0: nop

    // 0x80056CF4: lbu         $t5, 0x5($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X5);
    // 0x80056CF8: nop

    // 0x80056CFC: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x80056D00: bne         $at, $zero, L_80056DB8
    if (ctx->r1 != 0) {
        // 0x80056D04: nop
    
            goto L_80056DB8;
    }
    // 0x80056D04: nop

    // 0x80056D08: addiu       $t4, $zero, 0x5A
    ctx->r12 = ADD32(0, 0X5A);
    // 0x80056D0C: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x80056D10: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80056D14: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x80056D18: nop

    // 0x80056D1C: blez        $t2, L_80056DB8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80056D20: nop
    
            goto L_80056DB8;
    }
    // 0x80056D20: nop

L_80056D24:
    // 0x80056D24: lw          $t0, 0xFC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XFC);
    // 0x80056D28: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80056D2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056D30: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80056D34: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x80056D38: nop

    // 0x80056D3C: bne         $t9, $at, L_80056D88
    if (ctx->r25 != ctx->r1) {
        // 0x80056D40: nop
    
            goto L_80056D88;
    }
    // 0x80056D40: nop

    // 0x80056D44: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x80056D48: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80056D4C: lw          $a1, -0xDC0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XDC0);
    // 0x80056D50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056D54: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80056D58: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80056D5C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80056D60: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80056D64: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80056D68: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80056D6C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80056D70: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80056D74: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056D78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80056D7C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80056D80: jal         0x80057460
    // 0x80056D84: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    weird_lots_of_magic_number_setting_66xrefs(rdram, ctx);
        goto after_79;
    // 0x80056D84: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_79:
L_80056D88:
    // 0x80056D88: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80056D8C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80056D90: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x80056D94: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x80056D98: addiu       $t8, $t7, 0x19
    ctx->r24 = ADD32(ctx->r15, 0X19);
    // 0x80056D9C: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x80056DA0: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x80056DA4: lbu         $t3, 0x5($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X5);
    // 0x80056DA8: nop

    // 0x80056DAC: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80056DB0: bne         $at, $zero, L_80056D24
    if (ctx->r1 != 0) {
        // 0x80056DB4: nop
    
            goto L_80056D24;
    }
    // 0x80056DB4: nop

L_80056DB8:
    // 0x80056DB8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80056DBC: lw          $t6, 0x150($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X150);
    // 0x80056DC0: nop

    // 0x80056DC4: slti        $at, $t6, 0x5B
    ctx->r1 = SIGNED(ctx->r14) < 0X5B ? 1 : 0;
    // 0x80056DC8: bne         $at, $zero, L_80056E80
    if (ctx->r1 != 0) {
        // 0x80056DCC: nop
    
            goto L_80056E80;
    }
    // 0x80056DCC: nop

    // 0x80056DD0: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x80056DD4: addiu       $t5, $zero, 0x5A
    ctx->r13 = ADD32(0, 0X5A);
    // 0x80056DD8: sw          $t5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r13;
    // 0x80056DDC: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80056DE0: lbu         $t1, 0x5($t4)
    ctx->r9 = MEM_BU(ctx->r12, 0X5);
    // 0x80056DE4: nop

    // 0x80056DE8: blez        $t1, L_80056E80
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80056DEC: nop
    
            goto L_80056E80;
    }
    // 0x80056DEC: nop

L_80056DF0:
    // 0x80056DF0: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80056DF4: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x80056DF8: sll         $t7, $t2, 3
    ctx->r15 = S32(ctx->r10 << 3);
    // 0x80056DFC: subu        $t7, $t7, $t2
    ctx->r15 = SUB32(ctx->r15, ctx->r10);
    // 0x80056E00: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80056E04: subu        $t7, $t7, $t2
    ctx->r15 = SUB32(ctx->r15, ctx->r10);
    // 0x80056E08: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80056E0C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80056E10: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80056E14: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x80056E18: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80056E1C: jal         0x8007AA5C
    // 0x80056E20: addiu       $a0, $a0, 0x2D98
    ctx->r4 = ADD32(ctx->r4, 0X2D98);
    displayText_FindEntry(rdram, ctx);
        goto after_80;
    // 0x80056E20: addiu       $a0, $a0, 0x2D98
    ctx->r4 = ADD32(ctx->r4, 0X2D98);
    after_80:
    // 0x80056E24: sw          $v0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r2;
    // 0x80056E28: lw          $t0, 0xF4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF4);
    // 0x80056E2C: nop

    // 0x80056E30: beq         $t0, $zero, L_80056E50
    if (ctx->r8 == 0) {
        // 0x80056E34: nop
    
            goto L_80056E50;
    }
    // 0x80056E34: nop

    // 0x80056E38: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x80056E3C: jal         0x80078300
    // 0x80056E40: nop

    FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(rdram, ctx);
        goto after_81;
    // 0x80056E40: nop

    after_81:
    // 0x80056E44: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80056E48: jal         0x80078300
    // 0x80056E4C: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    FUN_SRAM_80078300_twelveliner_div60_loop_30t_a(rdram, ctx);
        goto after_82;
    // 0x80056E4C: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    after_82:
L_80056E50:
    // 0x80056E50: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x80056E54: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x80056E58: lw          $t1, 0xFC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XFC);
    // 0x80056E5C: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80056E60: addiu       $t4, $t5, 0x19
    ctx->r12 = ADD32(ctx->r13, 0X19);
    // 0x80056E64: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x80056E68: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x80056E6C: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x80056E70: nop

    // 0x80056E74: slt         $at, $t6, $t2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80056E78: bne         $at, $zero, L_80056DF0
    if (ctx->r1 != 0) {
        // 0x80056E7C: nop
    
            goto L_80056DF0;
    }
    // 0x80056E7C: nop

L_80056E80:
    // 0x80056E80: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80056E84: lw          $t7, 0x150($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X150);
    // 0x80056E88: nop

    // 0x80056E8C: slti        $at, $t7, 0x79
    ctx->r1 = SIGNED(ctx->r15) < 0X79 ? 1 : 0;
    // 0x80056E90: bne         $at, $zero, L_8005705C
    if (ctx->r1 != 0) {
        // 0x80056E94: nop
    
            goto L_8005705C;
    }
    // 0x80056E94: nop

    // 0x80056E98: lw          $t8, 0xFC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XFC);
    // 0x80056E9C: nop

    // 0x80056EA0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80056EA4: nop

    // 0x80056EA8: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80056EAC: bne         $at, $zero, L_80056F4C
    if (ctx->r1 != 0) {
        // 0x80056EB0: nop
    
            goto L_80056F4C;
    }
    // 0x80056EB0: nop

    // 0x80056EB4: lw          $t0, 0x38($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X38);
    // 0x80056EB8: nop

    // 0x80056EBC: beq         $t0, $zero, L_8005705C
    if (ctx->r8 == 0) {
        // 0x80056EC0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005705C;
    }
    // 0x80056EC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056EC4: bne         $t0, $at, L_80056EE8
    if (ctx->r8 != ctx->r1) {
        // 0x80056EC8: nop
    
            goto L_80056EE8;
    }
    // 0x80056EC8: nop

    // 0x80056ECC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056ED0: addiu       $a1, $a1, -0x2DE8
    ctx->r5 = ADD32(ctx->r5, -0X2DE8);
    // 0x80056ED4: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80056ED8: jal         0x800B62D4
    // 0x80056EDC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_83;
    // 0x80056EDC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_83:
    // 0x80056EE0: b           L_80056F00
    // 0x80056EE4: nop

        goto L_80056F00;
    // 0x80056EE4: nop

L_80056EE8:
    // 0x80056EE8: lw          $t3, 0xFC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XFC);
    // 0x80056EEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056EF0: lw          $a2, 0x38($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X38);
    // 0x80056EF4: addiu       $a1, $a1, -0x2DD4
    ctx->r5 = ADD32(ctx->r5, -0X2DD4);
    // 0x80056EF8: jal         0x800B62D4
    // 0x80056EFC: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    sprintf_recomp(rdram, ctx);
        goto after_84;
    // 0x80056EFC: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_84:
L_80056F00:
    // 0x80056F00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056F04: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056F08: addiu       $t5, $sp, 0xB8
    ctx->r13 = ADD32(ctx->r29, 0XB8);
    // 0x80056F0C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80056F10: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80056F14: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80056F18: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80056F1C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80056F20: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80056F24: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80056F28: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80056F2C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80056F30: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x80056F34: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x80056F38: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    // 0x80056F3C: jal         0x80077960
    // 0x80056F40: addiu       $a3, $zero, 0xC6
    ctx->r7 = ADD32(0, 0XC6);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_85;
    // 0x80056F40: addiu       $a3, $zero, 0xC6
    ctx->r7 = ADD32(0, 0XC6);
    after_85:
    // 0x80056F44: b           L_8005705C
    // 0x80056F48: nop

        goto L_8005705C;
    // 0x80056F48: nop

L_80056F4C:
    // 0x80056F4C: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x80056F50: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80056F54: lbu         $t9, 0x5($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X5);
    // 0x80056F58: nop

    // 0x80056F5C: blez        $t9, L_8005705C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80056F60: nop
    
            goto L_8005705C;
    }
    // 0x80056F60: nop

L_80056F64:
    // 0x80056F64: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x80056F68: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x80056F6C: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x80056F70: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80056F74: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80056F78: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80056F7C: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x80056F80: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80056F84: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x80056F88: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x80056F8C: addu        $t1, $t4, $t8
    ctx->r9 = ADD32(ctx->r12, ctx->r24);
    // 0x80056F90: lbu         $t6, 0x1($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X1);
    // 0x80056F94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056F98: bne         $t6, $at, L_80057038
    if (ctx->r14 != ctx->r1) {
        // 0x80056F9C: nop
    
            goto L_80057038;
    }
    // 0x80056F9C: nop

    // 0x80056FA0: lw          $t2, 0x38($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X38);
    // 0x80056FA4: nop

    // 0x80056FA8: beq         $t2, $zero, L_80057038
    if (ctx->r10 == 0) {
        // 0x80056FAC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80057038;
    }
    // 0x80056FAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056FB0: bne         $t2, $at, L_80056FD8
    if (ctx->r10 != ctx->r1) {
        // 0x80056FB4: nop
    
            goto L_80056FD8;
    }
    // 0x80056FB4: nop

    // 0x80056FB8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056FBC: addiu       $a1, $a1, -0x2DBC
    ctx->r5 = ADD32(ctx->r5, -0X2DBC);
    // 0x80056FC0: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80056FC4: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80056FC8: jal         0x800B62D4
    // 0x80056FCC: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_86;
    // 0x80056FCC: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    after_86:
    // 0x80056FD0: b           L_80056FF4
    // 0x80056FD4: nop

        goto L_80056FF4;
    // 0x80056FD4: nop

L_80056FD8:
    // 0x80056FD8: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x80056FDC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80056FE0: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80056FE4: lw          $a3, 0x38($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X38);
    // 0x80056FE8: addiu       $a1, $a1, -0x2DAC
    ctx->r5 = ADD32(ctx->r5, -0X2DAC);
    // 0x80056FEC: jal         0x800B62D4
    // 0x80056FF0: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    sprintf_recomp(rdram, ctx);
        goto after_87;
    // 0x80056FF0: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    after_87:
L_80056FF4:
    // 0x80056FF4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80056FF8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80056FFC: addiu       $t9, $sp, 0xB8
    ctx->r25 = ADD32(ctx->r29, 0XB8);
    // 0x80057000: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80057004: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80057008: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8005700C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80057010: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80057014: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80057018: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8005701C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80057020: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80057024: addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // 0x80057028: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    // 0x8005702C: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    // 0x80057030: jal         0x80077960
    // 0x80057034: addiu       $a3, $zero, 0xC3
    ctx->r7 = ADD32(0, 0XC3);
    displayText_XY_RGBA_2(rdram, ctx);
        goto after_88;
    // 0x80057034: addiu       $a3, $zero, 0xC3
    ctx->r7 = ADD32(0, 0XC3);
    after_88:
L_80057038:
    // 0x80057038: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x8005703C: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x80057040: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x80057044: sw          $t4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r12;
    // 0x80057048: lbu         $t2, 0x5($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X5);
    // 0x8005704C: nop

    // 0x80057050: slt         $at, $t4, $t2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80057054: bne         $at, $zero, L_80056F64
    if (ctx->r1 != 0) {
        // 0x80057058: nop
    
            goto L_80056F64;
    }
    // 0x80057058: nop

L_8005705C:
    // 0x8005705C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80057060: jal         0x8005BE40
    // 0x80057064: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    Color_SetSpriteRenderMode(rdram, ctx);
        goto after_89;
    // 0x80057064: addiu       $a0, $a0, 0x20C0
    ctx->r4 = ADD32(ctx->r4, 0X20C0);
    after_89:
L_80057068:
    // 0x80057068: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005706C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80057070: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80057074: jr          $ra
    // 0x80057078: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80057078: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    // 0x8005707C: nop

;}

RECOMP_FUNC void Color_SetSpriteRenderMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BE40: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005BE44: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8005BE48: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8005BE4C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005BE50: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005BE54: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005BE58: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005BE5C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8005BE60: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x8005BE64: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8005BE68: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8005BE6C: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x8005BE70: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8005BE74: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005BE78: lui         $t7, 0xFFFE
    ctx->r15 = S32(0XFFFE << 16);
    // 0x8005BE7C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8005BE80: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005BE84: ori         $t7, $t7, 0x793C
    ctx->r15 = ctx->r15 | 0X793C;
    // 0x8005BE88: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005BE8C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005BE90: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8005BE94: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x8005BE98: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005BE9C: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8005BEA0: ori         $t2, $t2, 0xC00
    ctx->r10 = ctx->r10 | 0XC00;
    // 0x8005BEA4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8005BEA8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005BEAC: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x8005BEB0: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8005BEB4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8005BEB8: nop

    // 0x8005BEBC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8005BEC0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005BEC4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005BEC8: nop

    // 0x8005BECC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8005BED0: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8005BED4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8005BED8: jr          $ra
    // 0x8005BEDC: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    return;
    // 0x8005BEDC: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
;}

RECOMP_FUNC void func_8005BEE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BEE0: beq         $a1, $zero, L_8005DB88
    if (ctx->r5 == 0) {
        // 0x8005BEE4: addiu       $sp, $sp, -0x170
        ctx->r29 = ADD32(ctx->r29, -0X170);
            goto L_8005DB88;
    }
    // 0x8005BEE4: addiu       $sp, $sp, -0x170
    ctx->r29 = ADD32(ctx->r29, -0X170);
    // 0x8005BEE8: lw          $t6, 0x1A0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A0);
    // 0x8005BEEC: nop

    // 0x8005BEF0: beq         $t6, $zero, L_8005DB88
    if (ctx->r14 == 0) {
        // 0x8005BEF4: nop
    
            goto L_8005DB88;
    }
    // 0x8005BEF4: nop

    // 0x8005BEF8: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x8005BEFC: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x8005BF00: subu        $t2, $t1, $a3
    ctx->r10 = SUB32(ctx->r9, ctx->r7);
    // 0x8005BF04: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005BF08: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x8005BF0C: addiu       $t5, $t4, 0xFFF
    ctx->r13 = ADD32(ctx->r12, 0XFFF);
    // 0x8005BF10: div         $zero, $t5, $t6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r14)));
    // 0x8005BF14: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x8005BF18: lw          $t1, 0x180($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X180);
    // 0x8005BF1C: sw          $t7, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r15;
    // 0x8005BF20: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x8005BF24: nop

    // 0x8005BF28: sw          $t8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r24;
    // 0x8005BF2C: lhu         $t9, 0x4($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X4);
    // 0x8005BF30: nop

    // 0x8005BF34: sw          $t9, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r25;
    // 0x8005BF38: lw          $t9, 0x188($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X188);
    // 0x8005BF3C: bne         $t6, $zero, L_8005BF48
    if (ctx->r14 != 0) {
        // 0x8005BF40: nop
    
            goto L_8005BF48;
    }
    // 0x8005BF40: nop

    // 0x8005BF44: break       7
    do_break(2147860292);
L_8005BF48:
    // 0x8005BF48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BF4C: bne         $t6, $at, L_8005BF60
    if (ctx->r14 != ctx->r1) {
        // 0x8005BF50: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005BF60;
    }
    // 0x8005BF50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005BF54: bne         $t5, $at, L_8005BF60
    if (ctx->r13 != ctx->r1) {
        // 0x8005BF58: nop
    
            goto L_8005BF60;
    }
    // 0x8005BF58: nop

    // 0x8005BF5C: break       6
    do_break(2147860316);
L_8005BF60:
    // 0x8005BF60: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x8005BF64: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x8005BF68: lw          $t6, 0x1A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A8);
    // 0x8005BF6C: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x8005BF70: addiu       $t5, $t4, 0xFFF
    ctx->r13 = ADD32(ctx->r12, 0XFFF);
    // 0x8005BF74: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x8005BF78: mflo        $t7
    ctx->r15 = lo;
    // 0x8005BF7C: addiu       $t8, $t7, -0x5
    ctx->r24 = ADD32(ctx->r15, -0X5);
    // 0x8005BF80: sw          $t8, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r24;
    // 0x8005BF84: div         $zero, $t5, $t6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r14)));
    // 0x8005BF88: bne         $t6, $zero, L_8005BF94
    if (ctx->r14 != 0) {
        // 0x8005BF8C: nop
    
            goto L_8005BF94;
    }
    // 0x8005BF8C: nop

    // 0x8005BF90: break       7
    do_break(2147860368);
L_8005BF94:
    // 0x8005BF94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BF98: bne         $t6, $at, L_8005BFAC
    if (ctx->r14 != ctx->r1) {
        // 0x8005BF9C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005BFAC;
    }
    // 0x8005BF9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005BFA0: bne         $t5, $at, L_8005BFAC
    if (ctx->r13 != ctx->r1) {
        // 0x8005BFA4: nop
    
            goto L_8005BFAC;
    }
    // 0x8005BFA4: nop

    // 0x8005BFA8: break       6
    do_break(2147860392);
L_8005BFAC:
    // 0x8005BFAC: mflo        $t7
    ctx->r15 = lo;
    // 0x8005BFB0: addiu       $t8, $t7, -0x9
    ctx->r24 = ADD32(ctx->r15, -0X9);
    // 0x8005BFB4: blez        $t9, L_8005DB88
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8005BFB8: sw          $t8, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r24;
            goto L_8005DB88;
    }
    // 0x8005BFB8: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
    // 0x8005BFBC: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x8005BFC0: nop

    // 0x8005BFC4: blez        $t1, L_8005DB88
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8005BFC8: nop
    
            goto L_8005DB88;
    }
    // 0x8005BFC8: nop

    // 0x8005BFCC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005BFD0: lh          $t2, 0x164($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X164);
    // 0x8005BFD4: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x8005BFD8: nop

    // 0x8005BFDC: beq         $t2, $t3, L_8005C248
    if (ctx->r10 == ctx->r11) {
        // 0x8005BFE0: nop
    
            goto L_8005C248;
    }
    // 0x8005BFE0: nop

    // 0x8005BFE4: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x8005BFE8: beq         $t0, $zero, L_8005C010
    if (ctx->r8 == 0) {
        // 0x8005BFEC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005C010;
    }
    // 0x8005BFEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005BFF0: beq         $t0, $at, L_8005C090
    if (ctx->r8 == ctx->r1) {
        // 0x8005BFF4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005C090;
    }
    // 0x8005BFF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005BFF8: beq         $t0, $at, L_8005C050
    if (ctx->r8 == ctx->r1) {
        // 0x8005BFFC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005C050;
    }
    // 0x8005BFFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005C000: beq         $t0, $at, L_8005C0D0
    if (ctx->r8 == ctx->r1) {
        // 0x8005C004: nop
    
            goto L_8005C0D0;
    }
    // 0x8005C004: nop

    // 0x8005C008: b           L_8005DB88
    // 0x8005C00C: nop

        goto L_8005DB88;
    // 0x8005C00C: nop

L_8005C010:
    // 0x8005C010: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x8005C014: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C018: sw          $t4, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r12;
    // 0x8005C01C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005C020: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8005C024: sw          $t5, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r13;
    // 0x8005C028: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005C02C: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x8005C030: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005C034: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005C038: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x8005C03C: nop

    // 0x8005C040: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005C044: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x8005C048: b           L_8005C380
    // 0x8005C04C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
        goto L_8005C380;
    // 0x8005C04C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
L_8005C050:
    // 0x8005C050: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x8005C054: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C058: sw          $t2, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r10;
    // 0x8005C05C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005C060: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x8005C064: sw          $t3, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r11;
    // 0x8005C068: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005C06C: ori         $t6, $t6, 0x1001
    ctx->r14 = ctx->r14 | 0X1001;
    // 0x8005C070: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005C074: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005C078: lw          $t7, 0x14C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14C);
    // 0x8005C07C: nop

    // 0x8005C080: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005C084: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x8005C088: b           L_8005C380
    // 0x8005C08C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
        goto L_8005C380;
    // 0x8005C08C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
L_8005C090:
    // 0x8005C090: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x8005C094: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C098: sw          $t9, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r25;
    // 0x8005C09C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005C0A0: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x8005C0A4: sw          $t1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r9;
    // 0x8005C0A8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005C0AC: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x8005C0B0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8005C0B4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005C0B8: lw          $t5, 0x148($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X148);
    // 0x8005C0BC: nop

    // 0x8005C0C0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005C0C4: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x8005C0C8: b           L_8005C380
    // 0x8005C0CC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
        goto L_8005C380;
    // 0x8005C0CC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_8005C0D0:
    // 0x8005C0D0: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x8005C0D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C0D8: sw          $t7, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r15;
    // 0x8005C0DC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005C0E0: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x8005C0E4: sw          $t8, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r24;
    // 0x8005C0E8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005C0EC: ori         $t2, $t2, 0x1001
    ctx->r10 = ctx->r10 | 0X1001;
    // 0x8005C0F0: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005C0F4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005C0F8: lw          $t3, 0x144($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X144);
    // 0x8005C0FC: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x8005C100: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8005C104: lw          $t5, 0x144($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X144);
    // 0x8005C108: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8005C10C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8005C110: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005C114: nop

    // 0x8005C118: sw          $t6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r14;
    // 0x8005C11C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005C120: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8005C124: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005C128: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005C12C: lw          $t1, 0x140($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X140);
    // 0x8005C130: nop

    // 0x8005C134: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005C138: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x8005C13C: nop

    // 0x8005C140: sw          $a2, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r6;
    // 0x8005C144: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005C148: nop

    // 0x8005C14C: sw          $t3, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r11;
    // 0x8005C150: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005C154: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x8005C158: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005C15C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005C160: lw          $t7, 0x13C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X13C);
    // 0x8005C164: ori         $t3, $t3, 0x100
    ctx->r11 = ctx->r11 | 0X100;
    // 0x8005C168: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005C16C: lw          $t8, 0x13C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X13C);
    // 0x8005C170: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x8005C174: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8005C178: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005C17C: nop

    // 0x8005C180: sw          $t9, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r25;
    // 0x8005C184: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005C188: nop

    // 0x8005C18C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8005C190: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005C194: lw          $t4, 0x138($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X138);
    // 0x8005C198: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x8005C19C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005C1A0: lw          $t6, 0x138($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X138);
    // 0x8005C1A4: nop

    // 0x8005C1A8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005C1AC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005C1B0: nop

    // 0x8005C1B4: sw          $t7, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r15;
    // 0x8005C1B8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005C1BC: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8005C1C0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8005C1C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005C1C8: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x8005C1CC: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8005C1D0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8005C1D4: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x8005C1D8: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8005C1DC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005C1E0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005C1E4: nop

    // 0x8005C1E8: sw          $t4, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r12;
    // 0x8005C1EC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005C1F0: nop

    // 0x8005C1F4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005C1F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005C1FC: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x8005C200: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8005C204: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005C208: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x8005C20C: nop

    // 0x8005C210: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8005C214: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005C218: nop

    // 0x8005C21C: sw          $t2, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r10;
    // 0x8005C220: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005C224: nop

    // 0x8005C228: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005C22C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005C230: lw          $t6, 0x12C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X12C);
    // 0x8005C234: nop

    // 0x8005C238: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005C23C: lw          $t7, 0x12C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X12C);
    // 0x8005C240: b           L_8005C380
    // 0x8005C244: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
        goto L_8005C380;
    // 0x8005C244: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
L_8005C248:
    // 0x8005C248: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005C24C: lui         $t2, 0xFD10
    ctx->r10 = S32(0XFD10 << 16);
    // 0x8005C250: sw          $t8, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r24;
    // 0x8005C254: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005C258: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8005C25C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005C260: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005C264: lw          $t3, 0x128($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X128);
    // 0x8005C268: nop

    // 0x8005C26C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8005C270: lw          $t4, 0x128($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X128);
    // 0x8005C274: nop

    // 0x8005C278: sw          $a2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r6;
    // 0x8005C27C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005C280: nop

    // 0x8005C284: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x8005C288: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005C28C: lui         $t5, 0xF500
    ctx->r13 = S32(0XF500 << 16);
    // 0x8005C290: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005C294: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005C298: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x8005C29C: ori         $t5, $t5, 0x100
    ctx->r13 = ctx->r13 | 0X100;
    // 0x8005C2A0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005C2A4: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x8005C2A8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8005C2AC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8005C2B0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005C2B4: nop

    // 0x8005C2B8: sw          $t2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r10;
    // 0x8005C2BC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005C2C0: nop

    // 0x8005C2C4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005C2C8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005C2CC: lw          $t6, 0x120($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X120);
    // 0x8005C2D0: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x8005C2D4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005C2D8: lw          $t8, 0x120($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X120);
    // 0x8005C2DC: nop

    // 0x8005C2E0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8005C2E4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005C2E8: nop

    // 0x8005C2EC: sw          $t9, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r25;
    // 0x8005C2F0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005C2F4: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8005C2F8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8005C2FC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005C300: lw          $t4, 0x11C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X11C);
    // 0x8005C304: lui         $t2, 0x73F
    ctx->r10 = S32(0X73F << 16);
    // 0x8005C308: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005C30C: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
    // 0x8005C310: ori         $t2, $t2, 0xC000
    ctx->r10 = ctx->r10 | 0XC000;
    // 0x8005C314: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8005C318: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005C31C: nop

    // 0x8005C320: sw          $t6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r14;
    // 0x8005C324: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005C328: nop

    // 0x8005C32C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005C330: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005C334: lw          $t1, 0x118($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X118);
    // 0x8005C338: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8005C33C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005C340: lw          $t3, 0x118($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X118);
    // 0x8005C344: nop

    // 0x8005C348: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8005C34C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005C350: nop

    // 0x8005C354: sw          $t4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r12;
    // 0x8005C358: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005C35C: nop

    // 0x8005C360: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005C364: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005C368: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x8005C36C: nop

    // 0x8005C370: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005C374: lw          $t9, 0x114($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X114);
    // 0x8005C378: nop

    // 0x8005C37C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_8005C380:
    // 0x8005C380: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005C384: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8005C388: lw          $t1, 0x160($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X160);
    // 0x8005C38C: addiu       $t3, $t2, 0x3
    ctx->r11 = ADD32(ctx->r10, 0X3);
    // 0x8005C390: andi        $t4, $t3, 0xFFFC
    ctx->r12 = ctx->r11 & 0XFFFC;
    // 0x8005C394: div         $zero, $t1, $t4
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r12)));
    // 0x8005C398: bne         $t4, $zero, L_8005C3A4
    if (ctx->r12 != 0) {
        // 0x8005C39C: nop
    
            goto L_8005C3A4;
    }
    // 0x8005C39C: nop

    // 0x8005C3A0: break       7
    do_break(2147861408);
L_8005C3A4:
    // 0x8005C3A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005C3A8: bne         $t4, $at, L_8005C3BC
    if (ctx->r12 != ctx->r1) {
        // 0x8005C3AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005C3BC;
    }
    // 0x8005C3AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005C3B0: bne         $t1, $at, L_8005C3BC
    if (ctx->r9 != ctx->r1) {
        // 0x8005C3B4: nop
    
            goto L_8005C3BC;
    }
    // 0x8005C3B4: nop

    // 0x8005C3B8: break       6
    do_break(2147861432);
L_8005C3BC:
    // 0x8005C3BC: mflo        $t5
    ctx->r13 = lo;
    // 0x8005C3C0: sw          $t5, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r13;
    // 0x8005C3C4: blez        $t5, L_8005DB88
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8005C3C8: nop
    
            goto L_8005DB88;
    }
    // 0x8005C3C8: nop

    // 0x8005C3CC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8005C3D0: lbu         $t6, 0x168($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X168);
    // 0x8005C3D4: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x8005C3D8: nop

    // 0x8005C3DC: bne         $t6, $t7, L_8005C444
    if (ctx->r14 != ctx->r15) {
        // 0x8005C3E0: nop
    
            goto L_8005C444;
    }
    // 0x8005C3E0: nop

    // 0x8005C3E4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8005C3E8: lbu         $t8, 0x16C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X16C);
    // 0x8005C3EC: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x8005C3F0: nop

    // 0x8005C3F4: bne         $t8, $t9, L_8005C444
    if (ctx->r24 != ctx->r25) {
        // 0x8005C3F8: nop
    
            goto L_8005C444;
    }
    // 0x8005C3F8: nop

    // 0x8005C3FC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005C400: lbu         $t2, 0x170($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X170);
    // 0x8005C404: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x8005C408: nop

    // 0x8005C40C: bne         $t2, $t3, L_8005C444
    if (ctx->r10 != ctx->r11) {
        // 0x8005C410: nop
    
            goto L_8005C444;
    }
    // 0x8005C410: nop

    // 0x8005C414: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8005C418: lbu         $t1, 0x174($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X174);
    // 0x8005C41C: lw          $t4, 0x1A0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A0);
    // 0x8005C420: nop

    // 0x8005C424: bne         $t1, $t4, L_8005C444
    if (ctx->r9 != ctx->r12) {
        // 0x8005C428: nop
    
            goto L_8005C444;
    }
    // 0x8005C428: nop

    // 0x8005C42C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8005C430: lh          $t5, 0x164($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X164);
    // 0x8005C434: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x8005C438: nop

    // 0x8005C43C: beq         $t5, $t6, L_8005C5F0
    if (ctx->r13 == ctx->r14) {
        // 0x8005C440: nop
    
            goto L_8005C5F0;
    }
    // 0x8005C440: nop

L_8005C444:
    // 0x8005C444: lw          $t7, 0x1A0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A0);
    // 0x8005C448: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005C44C: bne         $t7, $at, L_8005C4BC
    if (ctx->r15 != ctx->r1) {
        // 0x8005C450: nop
    
            goto L_8005C4BC;
    }
    // 0x8005C450: nop

    // 0x8005C454: lw          $t8, 0x194($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X194);
    // 0x8005C458: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005C45C: bne         $t8, $at, L_8005C4BC
    if (ctx->r24 != ctx->r1) {
        // 0x8005C460: nop
    
            goto L_8005C4BC;
    }
    // 0x8005C460: nop

    // 0x8005C464: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x8005C468: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005C46C: bne         $t9, $at, L_8005C4BC
    if (ctx->r25 != ctx->r1) {
        // 0x8005C470: nop
    
            goto L_8005C4BC;
    }
    // 0x8005C470: nop

    // 0x8005C474: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x8005C478: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005C47C: bne         $t2, $at, L_8005C4BC
    if (ctx->r10 != ctx->r1) {
        // 0x8005C480: nop
    
            goto L_8005C4BC;
    }
    // 0x8005C480: nop

    // 0x8005C484: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005C488: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x8005C48C: sw          $t3, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r11;
    // 0x8005C490: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005C494: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x8005C498: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x8005C49C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005C4A0: lw          $t6, 0x110($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X110);
    // 0x8005C4A4: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x8005C4A8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005C4AC: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
    // 0x8005C4B0: ori         $t7, $t7, 0xF279
    ctx->r15 = ctx->r15 | 0XF279;
    // 0x8005C4B4: b           L_8005C5C0
    // 0x8005C4B8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
        goto L_8005C5C0;
    // 0x8005C4B8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_8005C4BC:
    // 0x8005C4BC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8005C4C0: lbu         $t9, 0x168($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X168);
    // 0x8005C4C4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005C4C8: bne         $t9, $at, L_8005C50C
    if (ctx->r25 != ctx->r1) {
        // 0x8005C4CC: nop
    
            goto L_8005C50C;
    }
    // 0x8005C4CC: nop

    // 0x8005C4D0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005C4D4: lbu         $t2, 0x16C($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X16C);
    // 0x8005C4D8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005C4DC: bne         $t2, $at, L_8005C50C
    if (ctx->r10 != ctx->r1) {
        // 0x8005C4E0: nop
    
            goto L_8005C50C;
    }
    // 0x8005C4E0: nop

    // 0x8005C4E4: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005C4E8: lbu         $t3, 0x170($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X170);
    // 0x8005C4EC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005C4F0: bne         $t3, $at, L_8005C50C
    if (ctx->r11 != ctx->r1) {
        // 0x8005C4F4: nop
    
            goto L_8005C50C;
    }
    // 0x8005C4F4: nop

    // 0x8005C4F8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8005C4FC: lbu         $t1, 0x174($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X174);
    // 0x8005C500: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005C504: beq         $t1, $at, L_8005C524
    if (ctx->r9 == ctx->r1) {
        // 0x8005C508: nop
    
            goto L_8005C524;
    }
    // 0x8005C508: nop

L_8005C50C:
    // 0x8005C50C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8005C510: lh          $t4, 0x164($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X164);
    // 0x8005C514: lw          $t5, 0x15C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X15C);
    // 0x8005C518: nop

    // 0x8005C51C: beq         $t4, $t5, L_8005C558
    if (ctx->r12 == ctx->r13) {
        // 0x8005C520: nop
    
            goto L_8005C558;
    }
    // 0x8005C520: nop

L_8005C524:
    // 0x8005C524: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005C528: lui         $t9, 0xFC11
    ctx->r25 = S32(0XFC11 << 16);
    // 0x8005C52C: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
    // 0x8005C530: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005C534: ori         $t9, $t9, 0x9623
    ctx->r25 = ctx->r25 | 0X9623;
    // 0x8005C538: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005C53C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005C540: lw          $t2, 0x10C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10C);
    // 0x8005C544: lui         $t3, 0xFF2F
    ctx->r11 = S32(0XFF2F << 16);
    // 0x8005C548: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8005C54C: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
    // 0x8005C550: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x8005C554: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
L_8005C558:
    // 0x8005C558: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005C55C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8005C560: sw          $t4, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r12;
    // 0x8005C564: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005C568: nop

    // 0x8005C56C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005C570: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005C574: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x8005C578: nop

    // 0x8005C57C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005C580: lw          $t1, 0x198($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X198);
    // 0x8005C584: lw          $t9, 0x194($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X194);
    // 0x8005C588: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8005C58C: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x8005C590: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x8005C594: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x8005C598: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8005C59C: lw          $t1, 0x1A0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A0);
    // 0x8005C5A0: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x8005C5A4: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8005C5A8: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8005C5AC: lw          $t5, 0x108($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X108);
    // 0x8005C5B0: or          $t2, $t6, $t9
    ctx->r10 = ctx->r14 | ctx->r25;
    // 0x8005C5B4: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x8005C5B8: or          $t3, $t2, $t4
    ctx->r11 = ctx->r10 | ctx->r12;
    // 0x8005C5BC: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
L_8005C5C0:
    // 0x8005C5C0: lw          $t7, 0x194($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X194);
    // 0x8005C5C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C5C8: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x8005C5CC: sb          $t7, 0x168($at)
    MEM_B(0X168, ctx->r1) = ctx->r15;
    // 0x8005C5D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C5D4: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x8005C5D8: sb          $t8, 0x16C($at)
    MEM_B(0X16C, ctx->r1) = ctx->r24;
    // 0x8005C5DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C5E0: lw          $t9, 0x1A0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A0);
    // 0x8005C5E4: sb          $t6, 0x170($at)
    MEM_B(0X170, ctx->r1) = ctx->r14;
    // 0x8005C5E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C5EC: sb          $t9, 0x174($at)
    MEM_B(0X174, ctx->r1) = ctx->r25;
L_8005C5F0:
    // 0x8005C5F0: lw          $t1, 0x15C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X15C);
    // 0x8005C5F4: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x8005C5F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C5FC: sh          $t1, 0x164($at)
    MEM_H(0X164, ctx->r1) = ctx->r9;
    // 0x8005C600: beq         $t2, $zero, L_8005DB54
    if (ctx->r10 == 0) {
        // 0x8005C604: sw          $t2, 0x168($sp)
        MEM_W(0X168, ctx->r29) = ctx->r10;
            goto L_8005DB54;
    }
    // 0x8005C604: sw          $t2, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r10;
L_8005C608:
    // 0x8005C608: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x8005C60C: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x8005C610: nop

    // 0x8005C614: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8005C618: beq         $at, $zero, L_8005D104
    if (ctx->r1 == 0) {
        // 0x8005C61C: nop
    
            goto L_8005D104;
    }
    // 0x8005C61C: nop

    // 0x8005C620: lw          $t0, 0x15C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X15C);
    // 0x8005C624: nop

    // 0x8005C628: beq         $t0, $zero, L_8005C650
    if (ctx->r8 == 0) {
        // 0x8005C62C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005C650;
    }
    // 0x8005C62C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C630: beq         $t0, $at, L_8005C89C
    if (ctx->r8 == ctx->r1) {
        // 0x8005C634: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005C89C;
    }
    // 0x8005C634: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005C638: beq         $t0, $at, L_8005CAEC
    if (ctx->r8 == ctx->r1) {
        // 0x8005C63C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005CAEC;
    }
    // 0x8005C63C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005C640: beq         $t0, $at, L_8005CD30
    if (ctx->r8 == ctx->r1) {
        // 0x8005C644: nop
    
            goto L_8005CD30;
    }
    // 0x8005C644: nop

    // 0x8005C648: b           L_8005CF70
    // 0x8005C64C: nop

        goto L_8005CF70;
    // 0x8005C64C: nop

L_8005C650:
    // 0x8005C650: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005C654: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x8005C658: sw          $t5, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r13;
    // 0x8005C65C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005C660: addiu       $t3, $a1, 0x8
    ctx->r11 = ADD32(ctx->r5, 0X8);
    // 0x8005C664: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005C668: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005C66C: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x8005C670: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x8005C674: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8005C678: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x8005C67C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8005C680: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8005C684: lw          $t5, 0x104($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X104);
    // 0x8005C688: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005C68C: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x8005C690: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005C694: nop

    // 0x8005C698: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x8005C69C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005C6A0: nop

    // 0x8005C6A4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8005C6A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005C6AC: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x8005C6B0: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x8005C6B4: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8005C6B8: addiu       $t2, $t1, 0x7
    ctx->r10 = ADD32(ctx->r9, 0X7);
    // 0x8005C6BC: sra         $t4, $t2, 3
    ctx->r12 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8005C6C0: andi        $t3, $t4, 0x1FF
    ctx->r11 = ctx->r12 & 0X1FF;
    // 0x8005C6C4: sll         $t5, $t3, 9
    ctx->r13 = S32(ctx->r11 << 9);
    // 0x8005C6C8: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x8005C6CC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005C6D0: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x8005C6D4: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x8005C6D8: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8005C6DC: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8005C6E0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005C6E4: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x8005C6E8: sw          $t1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r9;
    // 0x8005C6EC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005C6F0: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005C6F4: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8005C6F8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005C6FC: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x8005C700: nop

    // 0x8005C704: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x8005C708: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x8005C70C: nop

    // 0x8005C710: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8005C714: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005C718: nop

    // 0x8005C71C: sw          $t8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r24;
    // 0x8005C720: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005C724: nop

    // 0x8005C728: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8005C72C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005C730: lw          $t2, 0x168($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X168);
    // 0x8005C734: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x8005C738: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8005C73C: subu        $t4, $t1, $t2
    ctx->r12 = SUB32(ctx->r9, ctx->r10);
    // 0x8005C740: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8005C744: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x8005C748: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x8005C74C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005C750: lw          $t9, 0x168($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X168);
    // 0x8005C754: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x8005C758: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x8005C75C: lw          $t2, 0x16C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X16C);
    // 0x8005C760: subu        $t1, $t6, $t9
    ctx->r9 = SUB32(ctx->r14, ctx->r25);
    // 0x8005C764: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x8005C768: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8005C76C: addiu       $t3, $t4, -0x1
    ctx->r11 = ADD32(ctx->r12, -0X1);
    // 0x8005C770: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8005C774: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x8005C778: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8005C77C: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x8005C780: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x8005C784: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005C788: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8005C78C: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x8005C790: or          $t3, $t4, $t7
    ctx->r11 = ctx->r12 | ctx->r15;
    // 0x8005C794: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x8005C798: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005C79C: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x8005C7A0: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
    // 0x8005C7A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005C7A8: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005C7AC: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8005C7B0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005C7B4: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x8005C7B8: nop

    // 0x8005C7BC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8005C7C0: lw          $t4, 0xF4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF4);
    // 0x8005C7C4: nop

    // 0x8005C7C8: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8005C7CC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005C7D0: nop

    // 0x8005C7D4: sw          $t7, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r15;
    // 0x8005C7D8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005C7DC: nop

    // 0x8005C7E0: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x8005C7E4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005C7E8: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x8005C7EC: lw          $t3, 0xF0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF0);
    // 0x8005C7F0: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x8005C7F4: addiu       $t9, $t6, 0x7
    ctx->r25 = ADD32(ctx->r14, 0X7);
    // 0x8005C7F8: sra         $t1, $t9, 3
    ctx->r9 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8005C7FC: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x8005C800: sll         $t4, $t2, 9
    ctx->r12 = S32(ctx->r10 << 9);
    // 0x8005C804: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x8005C808: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8005C80C: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x8005C810: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x8005C814: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x8005C818: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8005C81C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005C820: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005C824: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x8005C828: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005C82C: nop

    // 0x8005C830: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005C834: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005C838: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x8005C83C: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x8005C840: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x8005C844: subu        $t7, $t2, $t4
    ctx->r15 = SUB32(ctx->r10, ctx->r12);
    // 0x8005C848: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8005C84C: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x8005C850: or          $t8, $t5, $at
    ctx->r24 = ctx->r13 | ctx->r1;
    // 0x8005C854: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8005C858: lw          $t1, 0x168($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X168);
    // 0x8005C85C: lw          $t9, 0x160($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X160);
    // 0x8005C860: lw          $t4, 0x16C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X16C);
    // 0x8005C864: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x8005C868: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x8005C86C: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x8005C870: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x8005C874: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8005C878: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005C87C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8005C880: andi        $t2, $t1, 0xFFF
    ctx->r10 = ctx->r9 & 0XFFF;
    // 0x8005C884: lw          $t3, 0xEC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XEC);
    // 0x8005C888: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x8005C88C: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x8005C890: or          $t7, $t4, $t8
    ctx->r15 = ctx->r12 | ctx->r24;
    // 0x8005C894: b           L_8005CF70
    // 0x8005C898: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
        goto L_8005CF70;
    // 0x8005C898: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
L_8005C89C:
    // 0x8005C89C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005C8A0: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x8005C8A4: sw          $t5, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r13;
    // 0x8005C8A8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005C8AC: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
    // 0x8005C8B0: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8005C8B4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005C8B8: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8005C8BC: lw          $t3, 0xE8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE8);
    // 0x8005C8C0: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8005C8C4: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8005C8C8: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x8005C8CC: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8005C8D0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8005C8D4: lw          $t6, 0xE8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE8);
    // 0x8005C8D8: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8005C8DC: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005C8E0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005C8E4: nop

    // 0x8005C8E8: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
    // 0x8005C8EC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005C8F0: nop

    // 0x8005C8F4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8005C8F8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005C8FC: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x8005C900: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x8005C904: sra         $t8, $t4, 1
    ctx->r24 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8005C908: addiu       $t7, $t8, 0x7
    ctx->r15 = ADD32(ctx->r24, 0X7);
    // 0x8005C90C: sra         $t3, $t7, 3
    ctx->r11 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8005C910: andi        $t5, $t3, 0x1FF
    ctx->r13 = ctx->r11 & 0X1FF;
    // 0x8005C914: sll         $t6, $t5, 9
    ctx->r14 = S32(ctx->r13 << 9);
    // 0x8005C918: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8005C91C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005C920: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x8005C924: lui         $t2, 0x708
    ctx->r10 = S32(0X708 << 16);
    // 0x8005C928: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8005C92C: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8005C930: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005C934: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8005C938: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x8005C93C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005C940: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005C944: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x8005C948: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005C94C: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x8005C950: nop

    // 0x8005C954: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005C958: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8005C95C: nop

    // 0x8005C960: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8005C964: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005C968: nop

    // 0x8005C96C: sw          $t1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r9;
    // 0x8005C970: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005C974: nop

    // 0x8005C978: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8005C97C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005C980: lw          $t7, 0x168($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X168);
    // 0x8005C984: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x8005C988: lw          $t1, 0xDC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XDC);
    // 0x8005C98C: subu        $t3, $t8, $t7
    ctx->r11 = SUB32(ctx->r24, ctx->r15);
    // 0x8005C990: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8005C994: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8005C998: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8005C99C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005C9A0: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x8005C9A4: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x8005C9A8: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8005C9AC: lw          $t7, 0x16C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X16C);
    // 0x8005C9B0: subu        $t8, $t2, $t4
    ctx->r24 = SUB32(ctx->r10, ctx->r12);
    // 0x8005C9B4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8005C9B8: addu        $t3, $t8, $t7
    ctx->r11 = ADD32(ctx->r24, ctx->r15);
    // 0x8005C9BC: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x8005C9C0: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8005C9C4: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x8005C9C8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8005C9CC: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8005C9D0: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8005C9D4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005C9D8: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x8005C9DC: or          $t3, $t7, $at
    ctx->r11 = ctx->r15 | ctx->r1;
    // 0x8005C9E0: or          $t5, $t3, $t9
    ctx->r13 = ctx->r11 | ctx->r25;
    // 0x8005C9E4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005C9E8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005C9EC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8005C9F0: sw          $t1, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r9;
    // 0x8005C9F4: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005C9F8: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8005C9FC: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8005CA00: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005CA04: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x8005CA08: nop

    // 0x8005CA0C: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8005CA10: lw          $t3, 0xD8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD8);
    // 0x8005CA14: nop

    // 0x8005CA18: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005CA1C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005CA20: nop

    // 0x8005CA24: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    // 0x8005CA28: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005CA2C: nop

    // 0x8005CA30: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005CA34: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005CA38: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8005CA3C: lw          $t5, 0xD4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD4);
    // 0x8005CA40: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8005CA44: addiu       $t4, $t2, 0x7
    ctx->r12 = ADD32(ctx->r10, 0X7);
    // 0x8005CA48: sra         $t8, $t4, 3
    ctx->r24 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8005CA4C: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x8005CA50: sll         $t3, $t7, 9
    ctx->r11 = S32(ctx->r15 << 9);
    // 0x8005CA54: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x8005CA58: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8005CA5C: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8005CA60: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x8005CA64: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8005CA68: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8005CA6C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CA70: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005CA74: sw          $t2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r10;
    // 0x8005CA78: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005CA7C: nop

    // 0x8005CA80: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005CA84: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CA88: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x8005CA8C: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x8005CA90: lw          $t2, 0xD0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD0);
    // 0x8005CA94: subu        $t9, $t7, $t3
    ctx->r25 = SUB32(ctx->r15, ctx->r11);
    // 0x8005CA98: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005CA9C: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8005CAA0: or          $t1, $t6, $at
    ctx->r9 = ctx->r14 | ctx->r1;
    // 0x8005CAA4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8005CAA8: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x8005CAAC: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005CAB0: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x8005CAB4: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005CAB8: subu        $t7, $t4, $t8
    ctx->r15 = SUB32(ctx->r12, ctx->r24);
    // 0x8005CABC: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x8005CAC0: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x8005CAC4: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8005CAC8: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8005CACC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8005CAD0: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8005CAD4: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x8005CAD8: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x8005CADC: andi        $t1, $t6, 0xFFF
    ctx->r9 = ctx->r14 & 0XFFF;
    // 0x8005CAE0: or          $t9, $t3, $t1
    ctx->r25 = ctx->r11 | ctx->r9;
    // 0x8005CAE4: b           L_8005CF70
    // 0x8005CAE8: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
        goto L_8005CF70;
    // 0x8005CAE8: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
L_8005CAEC:
    // 0x8005CAEC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005CAF0: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x8005CAF4: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x8005CAF8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CAFC: addiu       $t5, $a1, 0x8
    ctx->r13 = ADD32(ctx->r5, 0X8);
    // 0x8005CB00: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8005CB04: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005CB08: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x8005CB0C: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8005CB10: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8005CB14: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x8005CB18: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8005CB1C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8005CB20: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8005CB24: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005CB28: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005CB2C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CB30: nop

    // 0x8005CB34: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x8005CB38: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005CB3C: nop

    // 0x8005CB40: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005CB44: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CB48: lw          $t7, 0x164($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X164);
    // 0x8005CB4C: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8005CB50: addiu       $t3, $t7, 0x7
    ctx->r11 = ADD32(ctx->r15, 0X7);
    // 0x8005CB54: sra         $t1, $t3, 3
    ctx->r9 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8005CB58: andi        $t9, $t1, 0x1FF
    ctx->r25 = ctx->r9 & 0X1FF;
    // 0x8005CB5C: sll         $t5, $t9, 9
    ctx->r13 = S32(ctx->r25 << 9);
    // 0x8005CB60: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8005CB64: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005CB68: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8005CB6C: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x8005CB70: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8005CB74: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x8005CB78: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005CB7C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8005CB80: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x8005CB84: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005CB88: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005CB8C: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x8005CB90: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005CB94: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x8005CB98: nop

    // 0x8005CB9C: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8005CBA0: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x8005CBA4: nop

    // 0x8005CBA8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8005CBAC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CBB0: nop

    // 0x8005CBB4: sw          $t2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r10;
    // 0x8005CBB8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005CBBC: nop

    // 0x8005CBC0: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005CBC4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CBC8: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x8005CBCC: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x8005CBD0: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8005CBD4: subu        $t1, $t7, $t3
    ctx->r9 = SUB32(ctx->r15, ctx->r11);
    // 0x8005CBD8: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8005CBDC: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x8005CBE0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8005CBE4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005CBE8: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x8005CBEC: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005CBF0: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005CBF4: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x8005CBF8: subu        $t7, $t4, $t8
    ctx->r15 = SUB32(ctx->r12, ctx->r24);
    // 0x8005CBFC: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8005CC00: addu        $t1, $t7, $t3
    ctx->r9 = ADD32(ctx->r15, ctx->r11);
    // 0x8005CC04: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x8005CC08: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8005CC0C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8005CC10: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005CC14: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8005CC18: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x8005CC1C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005CC20: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x8005CC24: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8005CC28: or          $t9, $t1, $t6
    ctx->r25 = ctx->r9 | ctx->r14;
    // 0x8005CC2C: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8005CC30: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CC34: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8005CC38: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x8005CC3C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005CC40: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005CC44: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005CC48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CC4C: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x8005CC50: nop

    // 0x8005CC54: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8005CC58: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x8005CC5C: nop

    // 0x8005CC60: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8005CC64: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005CC68: nop

    // 0x8005CC6C: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x8005CC70: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005CC74: nop

    // 0x8005CC78: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x8005CC7C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005CC80: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005CC84: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8005CC88: addiu       $t4, $t2, 0x7
    ctx->r12 = ADD32(ctx->r10, 0X7);
    // 0x8005CC8C: sra         $t8, $t4, 3
    ctx->r24 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8005CC90: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x8005CC94: sll         $t3, $t7, 9
    ctx->r11 = S32(ctx->r15 << 9);
    // 0x8005CC98: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8005CC9C: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x8005CCA0: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x8005CCA4: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8005CCA8: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x8005CCAC: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8005CCB0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CCB4: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005CCB8: sw          $t2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r10;
    // 0x8005CCBC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005CCC0: nop

    // 0x8005CCC4: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005CCC8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CCCC: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x8005CCD0: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x8005CCD4: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x8005CCD8: subu        $t1, $t7, $t3
    ctx->r9 = SUB32(ctx->r15, ctx->r11);
    // 0x8005CCDC: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8005CCE0: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8005CCE4: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x8005CCE8: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x8005CCEC: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x8005CCF0: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005CCF4: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x8005CCF8: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005CCFC: subu        $t7, $t4, $t8
    ctx->r15 = SUB32(ctx->r12, ctx->r24);
    // 0x8005CD00: addu        $t1, $t7, $t3
    ctx->r9 = ADD32(ctx->r15, ctx->r11);
    // 0x8005CD04: addiu       $t6, $t1, -0x1
    ctx->r14 = ADD32(ctx->r9, -0X1);
    // 0x8005CD08: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8005CD0C: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8005CD10: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8005CD14: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8005CD18: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8005CD1C: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x8005CD20: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x8005CD24: or          $t1, $t3, $t5
    ctx->r9 = ctx->r11 | ctx->r13;
    // 0x8005CD28: b           L_8005CF70
    // 0x8005CD2C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
        goto L_8005CF70;
    // 0x8005CD2C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
L_8005CD30:
    // 0x8005CD30: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005CD34: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x8005CD38: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x8005CD3C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CD40: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8005CD44: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8005CD48: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005CD4C: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x8005CD50: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8005CD54: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8005CD58: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x8005CD5C: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x8005CD60: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8005CD64: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8005CD68: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005CD6C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8005CD70: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CD74: nop

    // 0x8005CD78: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
    // 0x8005CD7C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005CD80: nop

    // 0x8005CD84: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005CD88: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CD8C: lw          $t7, 0x164($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X164);
    // 0x8005CD90: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x8005CD94: addiu       $t3, $t7, 0x7
    ctx->r11 = ADD32(ctx->r15, 0X7);
    // 0x8005CD98: sra         $t5, $t3, 3
    ctx->r13 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8005CD9C: andi        $t1, $t5, 0x1FF
    ctx->r9 = ctx->r13 & 0X1FF;
    // 0x8005CDA0: sll         $t6, $t1, 9
    ctx->r14 = S32(ctx->r9 << 9);
    // 0x8005CDA4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8005CDA8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8005CDAC: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x8005CDB0: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x8005CDB4: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8005CDB8: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x8005CDBC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005CDC0: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x8005CDC4: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x8005CDC8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005CDCC: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005CDD0: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x8005CDD4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005CDD8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005CDDC: nop

    // 0x8005CDE0: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x8005CDE4: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8005CDE8: nop

    // 0x8005CDEC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8005CDF0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CDF4: nop

    // 0x8005CDF8: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
    // 0x8005CDFC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005CE00: nop

    // 0x8005CE04: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005CE08: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CE0C: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x8005CE10: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x8005CE14: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x8005CE18: subu        $t5, $t7, $t3
    ctx->r13 = SUB32(ctx->r15, ctx->r11);
    // 0x8005CE1C: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8005CE20: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8005CE24: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8005CE28: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8005CE2C: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x8005CE30: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005CE34: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005CE38: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x8005CE3C: subu        $t7, $t4, $t8
    ctx->r15 = SUB32(ctx->r12, ctx->r24);
    // 0x8005CE40: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8005CE44: addu        $t5, $t7, $t3
    ctx->r13 = ADD32(ctx->r15, ctx->r11);
    // 0x8005CE48: addiu       $t1, $t5, -0x1
    ctx->r9 = ADD32(ctx->r13, -0X1);
    // 0x8005CE4C: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8005CE50: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8005CE54: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8005CE58: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8005CE5C: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x8005CE60: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005CE64: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x8005CE68: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x8005CE6C: or          $t1, $t5, $t9
    ctx->r9 = ctx->r13 | ctx->r25;
    // 0x8005CE70: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8005CE74: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CE78: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8005CE7C: sw          $t2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r10;
    // 0x8005CE80: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005CE84: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005CE88: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005CE8C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CE90: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x8005CE94: nop

    // 0x8005CE98: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8005CE9C: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8005CEA0: nop

    // 0x8005CEA4: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8005CEA8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005CEAC: nop

    // 0x8005CEB0: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8005CEB4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005CEB8: nop

    // 0x8005CEBC: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x8005CEC0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005CEC4: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005CEC8: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8005CECC: addiu       $t4, $t2, 0x7
    ctx->r12 = ADD32(ctx->r10, 0X7);
    // 0x8005CED0: sra         $t8, $t4, 3
    ctx->r24 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8005CED4: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x8005CED8: sll         $t3, $t7, 9
    ctx->r11 = S32(ctx->r15 << 9);
    // 0x8005CEDC: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x8005CEE0: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8005CEE4: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8005CEE8: lui         $t1, 0x8
    ctx->r9 = S32(0X8 << 16);
    // 0x8005CEEC: ori         $t1, $t1, 0x200
    ctx->r9 = ctx->r9 | 0X200;
    // 0x8005CEF0: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8005CEF4: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CEF8: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005CEFC: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x8005CF00: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005CF04: nop

    // 0x8005CF08: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005CF0C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005CF10: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x8005CF14: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x8005CF18: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x8005CF1C: subu        $t5, $t7, $t3
    ctx->r13 = SUB32(ctx->r15, ctx->r11);
    // 0x8005CF20: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8005CF24: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x8005CF28: or          $t6, $t1, $at
    ctx->r14 = ctx->r9 | ctx->r1;
    // 0x8005CF2C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005CF30: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x8005CF34: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005CF38: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x8005CF3C: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005CF40: subu        $t7, $t4, $t8
    ctx->r15 = SUB32(ctx->r12, ctx->r24);
    // 0x8005CF44: addu        $t5, $t7, $t3
    ctx->r13 = ADD32(ctx->r15, ctx->r11);
    // 0x8005CF48: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8005CF4C: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8005CF50: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8005CF54: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005CF58: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8005CF5C: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8005CF60: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x8005CF64: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x8005CF68: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x8005CF6C: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
L_8005CF70:
    // 0x8005CF70: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005CF74: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8005CF78: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
    // 0x8005CF7C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005CF80: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8005CF84: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8005CF88: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005CF8C: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8005CF90: nop

    // 0x8005CF94: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8005CF98: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x8005CF9C: lw          $t2, 0x16C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X16C);
    // 0x8005CFA0: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8005CFA4: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x8005CFA8: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8005CFAC: addiu       $t8, $t4, -0x1
    ctx->r24 = ADD32(ctx->r12, -0X1);
    // 0x8005CFB0: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x8005CFB4: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8005CFB8: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x8005CFBC: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8005CFC0: or          $t3, $t1, $t7
    ctx->r11 = ctx->r9 | ctx->r15;
    // 0x8005CFC4: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8005CFC8: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005CFCC: nop

    // 0x8005CFD0: sw          $t5, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r13;
    // 0x8005CFD4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005CFD8: nop

    // 0x8005CFDC: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x8005CFE0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005CFE4: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x8005CFE8: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x8005CFEC: lw          $t2, 0x190($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X190);
    // 0x8005CFF0: addu        $t1, $t4, $t8
    ctx->r9 = ADD32(ctx->r12, ctx->r24);
    // 0x8005CFF4: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8005CFF8: addiu       $t3, $t7, -0x1
    ctx->r11 = ADD32(ctx->r15, -0X1);
    // 0x8005CFFC: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005D000: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8005D004: lw          $t1, 0x168($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X168);
    // 0x8005D008: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x8005D00C: sll         $t5, $t6, 12
    ctx->r13 = S32(ctx->r14 << 12);
    // 0x8005D010: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x8005D014: subu        $t7, $t8, $t1
    ctx->r15 = SUB32(ctx->r24, ctx->r9);
    // 0x8005D018: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8005D01C: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x8005D020: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8005D024: addiu       $t2, $t5, -0x1
    ctx->r10 = ADD32(ctx->r13, -0X1);
    // 0x8005D028: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x8005D02C: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x8005D030: or          $t8, $t9, $t4
    ctx->r24 = ctx->r25 | ctx->r12;
    // 0x8005D034: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D038: lw          $t3, 0x160($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X160);
    // 0x8005D03C: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x8005D040: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x8005D044: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x8005D048: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x8005D04C: subu        $t2, $t6, $t5
    ctx->r10 = SUB32(ctx->r14, ctx->r13);
    // 0x8005D050: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8005D054: andi        $t7, $t1, 0xFFF
    ctx->r15 = ctx->r9 & 0XFFF;
    // 0x8005D058: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8005D05C: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x8005D060: andi        $t4, $t9, 0xFFF
    ctx->r12 = ctx->r25 & 0XFFF;
    // 0x8005D064: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x8005D068: or          $t6, $t3, $t4
    ctx->r14 = ctx->r11 | ctx->r12;
    // 0x8005D06C: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x8005D070: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D074: lui         $t1, 0xE100
    ctx->r9 = S32(0XE100 << 16);
    // 0x8005D078: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    // 0x8005D07C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005D080: lui         $t2, 0xF100
    ctx->r10 = S32(0XF100 << 16);
    // 0x8005D084: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8005D088: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005D08C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8005D090: nop

    // 0x8005D094: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x8005D098: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x8005D09C: nop

    // 0x8005D0A0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005D0A4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D0A8: nop

    // 0x8005D0AC: sw          $t4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r12;
    // 0x8005D0B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005D0B4: nop

    // 0x8005D0B8: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x8005D0BC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005D0C0: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8005D0C4: nop

    // 0x8005D0C8: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8005D0CC: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8005D0D0: lw          $t3, 0x1A8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A8);
    // 0x8005D0D4: andi        $t1, $t8, 0xFFFF
    ctx->r9 = ctx->r24 & 0XFFFF;
    // 0x8005D0D8: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8005D0DC: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8005D0E0: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8005D0E4: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x8005D0E8: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x8005D0EC: lw          $t2, 0x168($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X168);
    // 0x8005D0F0: lw          $t9, 0x16C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X16C);
    // 0x8005D0F4: nop

    // 0x8005D0F8: subu        $t8, $t2, $t9
    ctx->r24 = SUB32(ctx->r10, ctx->r25);
    // 0x8005D0FC: b           L_8005DB44
    // 0x8005D100: sw          $t8, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r24;
        goto L_8005DB44;
    // 0x8005D100: sw          $t8, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r24;
L_8005D104:
    // 0x8005D104: lw          $t0, 0x15C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X15C);
    // 0x8005D108: nop

    // 0x8005D10C: beq         $t0, $zero, L_8005D134
    if (ctx->r8 == 0) {
        // 0x8005D110: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005D134;
    }
    // 0x8005D110: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D114: beq         $t0, $at, L_8005D360
    if (ctx->r8 == ctx->r1) {
        // 0x8005D118: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005D360;
    }
    // 0x8005D118: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005D11C: beq         $t0, $at, L_8005D590
    if (ctx->r8 == ctx->r1) {
        // 0x8005D120: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005D590;
    }
    // 0x8005D120: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005D124: beq         $t0, $at, L_8005D7B4
    if (ctx->r8 == ctx->r1) {
        // 0x8005D128: nop
    
            goto L_8005D7B4;
    }
    // 0x8005D128: nop

    // 0x8005D12C: b           L_8005D9D4
    // 0x8005D130: nop

        goto L_8005D9D4;
    // 0x8005D130: nop

L_8005D134:
    // 0x8005D134: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005D138: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x8005D13C: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x8005D140: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005D144: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x8005D148: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x8005D14C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005D150: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x8005D154: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x8005D158: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8005D15C: andi        $t5, $t6, 0xFFF
    ctx->r13 = ctx->r14 & 0XFFF;
    // 0x8005D160: or          $t2, $t5, $at
    ctx->r10 = ctx->r13 | ctx->r1;
    // 0x8005D164: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8005D168: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x8005D16C: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005D170: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8005D174: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005D178: nop

    // 0x8005D17C: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x8005D180: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D184: nop

    // 0x8005D188: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x8005D18C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005D190: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x8005D194: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x8005D198: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x8005D19C: addiu       $t2, $t5, 0x7
    ctx->r10 = ADD32(ctx->r13, 0X7);
    // 0x8005D1A0: sra         $t9, $t2, 3
    ctx->r25 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8005D1A4: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8005D1A8: sll         $t1, $t8, 9
    ctx->r9 = S32(ctx->r24 << 9);
    // 0x8005D1AC: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x8005D1B0: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x8005D1B4: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8005D1B8: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x8005D1BC: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8005D1C0: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x8005D1C4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005D1C8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005D1CC: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8005D1D0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D1D4: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005D1D8: addiu       $t9, $t2, 0x8
    ctx->r25 = ADD32(ctx->r10, 0X8);
    // 0x8005D1DC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005D1E0: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8005D1E4: nop

    // 0x8005D1E8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8005D1EC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x8005D1F0: nop

    // 0x8005D1F4: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005D1F8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D1FC: nop

    // 0x8005D200: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x8005D204: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D208: nop

    // 0x8005D20C: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x8005D210: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005D214: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x8005D218: lw          $t2, 0x168($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X168);
    // 0x8005D21C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8005D220: subu        $t9, $t5, $t2
    ctx->r25 = SUB32(ctx->r13, ctx->r10);
    // 0x8005D224: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8005D228: andi        $t1, $t8, 0xFFF
    ctx->r9 = ctx->r24 & 0XFFF;
    // 0x8005D22C: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x8005D230: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x8005D234: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x8005D238: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x8005D23C: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8005D240: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8005D244: andi        $t2, $t5, 0xFFF
    ctx->r10 = ctx->r13 & 0XFFF;
    // 0x8005D248: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8005D24C: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8005D250: sll         $t9, $t2, 12
    ctx->r25 = S32(ctx->r10 << 12);
    // 0x8005D254: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005D258: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8005D25C: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8005D260: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x8005D264: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x8005D268: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x8005D26C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D270: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8005D274: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x8005D278: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005D27C: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005D280: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005D284: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005D288: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8005D28C: nop

    // 0x8005D290: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x8005D294: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8005D298: nop

    // 0x8005D29C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8005D2A0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D2A4: nop

    // 0x8005D2A8: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x8005D2AC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005D2B0: nop

    // 0x8005D2B4: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x8005D2B8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005D2BC: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005D2C0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8005D2C4: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x8005D2C8: addiu       $t1, $t9, 0x7
    ctx->r9 = ADD32(ctx->r25, 0X7);
    // 0x8005D2CC: sra         $t3, $t1, 3
    ctx->r11 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8005D2D0: andi        $t7, $t3, 0x1FF
    ctx->r15 = ctx->r11 & 0X1FF;
    // 0x8005D2D4: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8005D2D8: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x8005D2DC: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x8005D2E0: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8005D2E4: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x8005D2E8: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x8005D2EC: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8005D2F0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005D2F4: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005D2F8: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x8005D2FC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005D300: nop

    // 0x8005D304: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x8005D308: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005D30C: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x8005D310: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x8005D314: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8005D318: subu        $t4, $t7, $t8
    ctx->r12 = SUB32(ctx->r15, ctx->r24);
    // 0x8005D31C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8005D320: andi        $t5, $t6, 0xFFF
    ctx->r13 = ctx->r14 & 0XFFF;
    // 0x8005D324: or          $t2, $t5, $at
    ctx->r10 = ctx->r13 | ctx->r1;
    // 0x8005D328: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8005D32C: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8005D330: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x8005D334: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8005D338: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8005D33C: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x8005D340: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8005D344: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8005D348: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8005D34C: sll         $t4, $t8, 12
    ctx->r12 = S32(ctx->r24 << 12);
    // 0x8005D350: andi        $t9, $t2, 0xFFF
    ctx->r25 = ctx->r10 & 0XFFF;
    // 0x8005D354: or          $t1, $t4, $t9
    ctx->r9 = ctx->r12 | ctx->r25;
    // 0x8005D358: b           L_8005D9D4
    // 0x8005D35C: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
        goto L_8005D9D4;
    // 0x8005D35C: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
L_8005D360:
    // 0x8005D360: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D364: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x8005D368: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x8005D36C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005D370: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x8005D374: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8005D378: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005D37C: lw          $t5, 0x164($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X164);
    // 0x8005D380: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8005D384: sra         $t2, $t5, 1
    ctx->r10 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8005D388: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8005D38C: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x8005D390: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8005D394: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8005D398: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8005D39C: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8005D3A0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8005D3A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005D3A8: nop

    // 0x8005D3AC: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x8005D3B0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005D3B4: nop

    // 0x8005D3B8: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x8005D3BC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005D3C0: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x8005D3C4: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8005D3C8: sra         $t9, $t4, 1
    ctx->r25 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8005D3CC: addiu       $t1, $t9, 0x7
    ctx->r9 = ADD32(ctx->r25, 0X7);
    // 0x8005D3D0: sra         $t3, $t1, 3
    ctx->r11 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8005D3D4: andi        $t7, $t3, 0x1FF
    ctx->r15 = ctx->r11 & 0X1FF;
    // 0x8005D3D8: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8005D3DC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8005D3E0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8005D3E4: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8005D3E8: lui         $t2, 0x708
    ctx->r10 = S32(0X708 << 16);
    // 0x8005D3EC: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8005D3F0: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8005D3F4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005D3F8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8005D3FC: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x8005D400: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005D404: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005D408: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x8005D40C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005D410: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8005D414: nop

    // 0x8005D418: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005D41C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8005D420: nop

    // 0x8005D424: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8005D428: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005D42C: nop

    // 0x8005D430: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x8005D434: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D438: nop

    // 0x8005D43C: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8005D440: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005D444: lw          $t9, 0x160($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X160);
    // 0x8005D448: lw          $t1, 0x168($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X168);
    // 0x8005D44C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8005D450: subu        $t3, $t9, $t1
    ctx->r11 = SUB32(ctx->r25, ctx->r9);
    // 0x8005D454: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8005D458: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8005D45C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8005D460: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8005D464: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005D468: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x8005D46C: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8005D470: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x8005D474: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x8005D478: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x8005D47C: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8005D480: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x8005D484: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005D488: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8005D48C: or          $t7, $t3, $at
    ctx->r15 = ctx->r11 | ctx->r1;
    // 0x8005D490: andi        $t2, $t5, 0xFFF
    ctx->r10 = ctx->r13 & 0XFFF;
    // 0x8005D494: or          $t4, $t7, $t2
    ctx->r12 = ctx->r15 | ctx->r10;
    // 0x8005D498: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x8005D49C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005D4A0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005D4A4: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x8005D4A8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005D4AC: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8005D4B0: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x8005D4B4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005D4B8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8005D4BC: nop

    // 0x8005D4C0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8005D4C4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8005D4C8: nop

    // 0x8005D4CC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8005D4D0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D4D4: nop

    // 0x8005D4D8: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8005D4DC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D4E0: nop

    // 0x8005D4E4: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x8005D4E8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005D4EC: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8005D4F0: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8005D4F4: sra         $t3, $t1, 1
    ctx->r11 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8005D4F8: addiu       $t8, $t3, 0x7
    ctx->r24 = ADD32(ctx->r11, 0X7);
    // 0x8005D4FC: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8005D500: andi        $t5, $t6, 0x1FF
    ctx->r13 = ctx->r14 & 0X1FF;
    // 0x8005D504: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x8005D508: or          $t2, $t7, $at
    ctx->r10 = ctx->r15 | ctx->r1;
    // 0x8005D50C: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8005D510: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8005D514: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8005D518: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x8005D51C: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8005D520: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005D524: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005D528: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x8005D52C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005D530: nop

    // 0x8005D534: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8005D538: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005D53C: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x8005D540: lw          $t7, 0x168($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X168);
    // 0x8005D544: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8005D548: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x8005D54C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8005D550: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x8005D554: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8005D558: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8005D55C: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x8005D560: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005D564: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x8005D568: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8005D56C: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x8005D570: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005D574: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x8005D578: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8005D57C: sll         $t2, $t7, 12
    ctx->r10 = S32(ctx->r15 << 12);
    // 0x8005D580: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x8005D584: or          $t8, $t2, $t3
    ctx->r24 = ctx->r10 | ctx->r11;
    // 0x8005D588: b           L_8005D9D4
    // 0x8005D58C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
        goto L_8005D9D4;
    // 0x8005D58C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
L_8005D590:
    // 0x8005D590: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005D594: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x8005D598: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x8005D59C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D5A0: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8005D5A4: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x8005D5A8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005D5AC: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x8005D5B0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8005D5B4: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8005D5B8: andi        $t2, $t1, 0xFFF
    ctx->r10 = ctx->r9 & 0XFFF;
    // 0x8005D5BC: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8005D5C0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8005D5C4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8005D5C8: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005D5CC: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x8005D5D0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D5D4: nop

    // 0x8005D5D8: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8005D5DC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D5E0: nop

    // 0x8005D5E4: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x8005D5E8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005D5EC: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8005D5F0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8005D5F4: addiu       $t2, $t1, 0x7
    ctx->r10 = ADD32(ctx->r9, 0X7);
    // 0x8005D5F8: sra         $t3, $t2, 3
    ctx->r11 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8005D5FC: andi        $t8, $t3, 0x1FF
    ctx->r24 = ctx->r11 & 0X1FF;
    // 0x8005D600: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x8005D604: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x8005D608: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005D60C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8005D610: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x8005D614: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8005D618: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x8005D61C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005D620: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005D624: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8005D628: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D62C: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005D630: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8005D634: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005D638: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8005D63C: nop

    // 0x8005D640: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8005D644: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8005D648: nop

    // 0x8005D64C: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8005D650: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D654: nop

    // 0x8005D658: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8005D65C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D660: nop

    // 0x8005D664: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x8005D668: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005D66C: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x8005D670: lw          $t2, 0x168($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X168);
    // 0x8005D674: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8005D678: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8005D67C: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8005D680: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8005D684: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x8005D688: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005D68C: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x8005D690: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x8005D694: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x8005D698: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005D69C: andi        $t2, $t1, 0xFFF
    ctx->r10 = ctx->r9 & 0XFFF;
    // 0x8005D6A0: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x8005D6A4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8005D6A8: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x8005D6AC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005D6B0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8005D6B4: or          $t8, $t3, $at
    ctx->r24 = ctx->r11 | ctx->r1;
    // 0x8005D6B8: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x8005D6BC: or          $t9, $t8, $t4
    ctx->r25 = ctx->r24 | ctx->r12;
    // 0x8005D6C0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8005D6C4: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D6C8: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8005D6CC: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8005D6D0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005D6D4: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005D6D8: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8005D6DC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005D6E0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D6E4: nop

    // 0x8005D6E8: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005D6EC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D6F0: nop

    // 0x8005D6F4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8005D6F8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D6FC: nop

    // 0x8005D700: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8005D704: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005D708: nop

    // 0x8005D70C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005D710: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005D714: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005D718: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005D71C: addiu       $t3, $t2, 0x7
    ctx->r11 = ADD32(ctx->r10, 0X7);
    // 0x8005D720: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8005D724: andi        $t5, $t6, 0x1FF
    ctx->r13 = ctx->r14 & 0X1FF;
    // 0x8005D728: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x8005D72C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8005D730: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8005D734: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005D738: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8005D73C: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x8005D740: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8005D744: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D748: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005D74C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8005D750: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005D754: nop

    // 0x8005D758: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8005D75C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005D760: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x8005D764: lw          $t7, 0x168($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X168);
    // 0x8005D768: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005D76C: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x8005D770: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8005D774: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x8005D778: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8005D77C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8005D780: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x8005D784: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005D788: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x8005D78C: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8005D790: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x8005D794: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005D798: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x8005D79C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005D7A0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8005D7A4: andi        $t2, $t1, 0xFFF
    ctx->r10 = ctx->r9 & 0XFFF;
    // 0x8005D7A8: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x8005D7AC: b           L_8005D9D4
    // 0x8005D7B0: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
        goto L_8005D9D4;
    // 0x8005D7B0: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
L_8005D7B4:
    // 0x8005D7B4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005D7B8: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x8005D7BC: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x8005D7C0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D7C4: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8005D7C8: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x8005D7CC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005D7D0: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x8005D7D4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8005D7D8: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8005D7DC: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8005D7E0: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x8005D7E4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8005D7E8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8005D7EC: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005D7F0: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x8005D7F4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D7F8: nop

    // 0x8005D7FC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8005D800: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D804: nop

    // 0x8005D808: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x8005D80C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005D810: lw          $t1, 0x164($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X164);
    // 0x8005D814: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D818: addiu       $t8, $t1, 0x7
    ctx->r24 = ADD32(ctx->r9, 0X7);
    // 0x8005D81C: sra         $t2, $t8, 3
    ctx->r10 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8005D820: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x8005D824: sll         $t6, $t3, 9
    ctx->r14 = S32(ctx->r11 << 9);
    // 0x8005D828: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x8005D82C: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005D830: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D834: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x8005D838: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8005D83C: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x8005D840: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005D844: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x8005D848: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005D84C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005D850: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005D854: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8005D858: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005D85C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8005D860: nop

    // 0x8005D864: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8005D868: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005D86C: nop

    // 0x8005D870: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8005D874: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D878: nop

    // 0x8005D87C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8005D880: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D884: nop

    // 0x8005D888: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x8005D88C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005D890: lw          $t1, 0x160($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X160);
    // 0x8005D894: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x8005D898: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005D89C: subu        $t2, $t1, $t8
    ctx->r10 = SUB32(ctx->r9, ctx->r24);
    // 0x8005D8A0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005D8A4: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8005D8A8: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x8005D8AC: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005D8B0: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x8005D8B4: lw          $t6, 0x160($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X160);
    // 0x8005D8B8: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x8005D8BC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005D8C0: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8005D8C4: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x8005D8C8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8005D8CC: sll         $t2, $t8, 12
    ctx->r10 = S32(ctx->r24 << 12);
    // 0x8005D8D0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005D8D4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8005D8D8: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8005D8DC: andi        $t4, $t7, 0xFFF
    ctx->r12 = ctx->r15 & 0XFFF;
    // 0x8005D8E0: or          $t9, $t3, $t4
    ctx->r25 = ctx->r11 | ctx->r12;
    // 0x8005D8E4: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8005D8E8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005D8EC: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8005D8F0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8005D8F4: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D8F8: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005D8FC: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x8005D900: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005D904: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8005D908: nop

    // 0x8005D90C: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8005D910: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8005D914: nop

    // 0x8005D918: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005D91C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005D920: nop

    // 0x8005D924: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8005D928: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005D92C: nop

    // 0x8005D930: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005D934: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005D938: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x8005D93C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D940: addiu       $t2, $t8, 0x7
    ctx->r10 = ADD32(ctx->r24, 0X7);
    // 0x8005D944: sra         $t6, $t2, 3
    ctx->r14 = S32(SIGNED(ctx->r10) >> 3);
    // 0x8005D948: andi        $t5, $t6, 0x1FF
    ctx->r13 = ctx->r14 & 0X1FF;
    // 0x8005D94C: sll         $t7, $t5, 9
    ctx->r15 = S32(ctx->r13 << 9);
    // 0x8005D950: or          $t3, $t7, $at
    ctx->r11 = ctx->r15 | ctx->r1;
    // 0x8005D954: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005D958: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D95C: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8005D960: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x8005D964: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8005D968: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005D96C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8005D970: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8005D974: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005D978: nop

    // 0x8005D97C: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x8005D980: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005D984: lw          $t5, 0x160($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X160);
    // 0x8005D988: lw          $t7, 0x168($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X168);
    // 0x8005D98C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005D990: subu        $t3, $t5, $t7
    ctx->r11 = SUB32(ctx->r13, ctx->r15);
    // 0x8005D994: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005D998: andi        $t9, $t4, 0xFFF
    ctx->r25 = ctx->r12 & 0XFFF;
    // 0x8005D99C: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8005D9A0: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8005D9A4: lw          $t2, 0x164($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X164);
    // 0x8005D9A8: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005D9AC: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8005D9B0: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8005D9B4: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x8005D9B8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005D9BC: andi        $t7, $t5, 0xFFF
    ctx->r15 = ctx->r13 & 0XFFF;
    // 0x8005D9C0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005D9C4: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x8005D9C8: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x8005D9CC: or          $t2, $t3, $t8
    ctx->r10 = ctx->r11 | ctx->r24;
    // 0x8005D9D0: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
L_8005D9D4:
    // 0x8005D9D4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005D9D8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8005D9DC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8005D9E0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005D9E4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8005D9E8: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x8005D9EC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005D9F0: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x8005D9F4: nop

    // 0x8005D9F8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D9FC: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x8005DA00: lw          $t7, 0x168($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X168);
    // 0x8005DA04: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8005DA08: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x8005DA0C: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x8005DA10: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x8005DA14: andi        $t6, $t2, 0xFFF
    ctx->r14 = ctx->r10 & 0XFFF;
    // 0x8005DA18: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x8005DA1C: sll         $t5, $t6, 12
    ctx->r13 = S32(ctx->r14 << 12);
    // 0x8005DA20: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x8005DA24: or          $t3, $t5, $t1
    ctx->r11 = ctx->r13 | ctx->r9;
    // 0x8005DA28: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8005DA2C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005DA30: nop

    // 0x8005DA34: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8005DA38: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005DA3C: nop

    // 0x8005DA40: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005DA44: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005DA48: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x8005DA4C: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x8005DA50: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x8005DA54: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x8005DA58: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005DA5C: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8005DA60: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8005DA64: andi        $t8, $t3, 0xFFF
    ctx->r24 = ctx->r11 & 0XFFF;
    // 0x8005DA68: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x8005DA6C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005DA70: sll         $t2, $t8, 12
    ctx->r10 = S32(ctx->r24 << 12);
    // 0x8005DA74: or          $t6, $t2, $at
    ctx->r14 = ctx->r10 | ctx->r1;
    // 0x8005DA78: addiu       $t1, $t5, -0x1
    ctx->r9 = ADD32(ctx->r13, -0X1);
    // 0x8005DA7C: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x8005DA80: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x8005DA84: or          $t8, $t6, $t3
    ctx->r24 = ctx->r14 | ctx->r11;
    // 0x8005DA88: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8005DA8C: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x8005DA90: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x8005DA94: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x8005DA98: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x8005DA9C: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x8005DAA0: subu        $t1, $t9, $t5
    ctx->r9 = SUB32(ctx->r25, ctx->r13);
    // 0x8005DAA4: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x8005DAA8: andi        $t7, $t2, 0xFFF
    ctx->r15 = ctx->r10 & 0XFFF;
    // 0x8005DAAC: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8005DAB0: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x8005DAB4: andi        $t3, $t6, 0xFFF
    ctx->r11 = ctx->r14 & 0XFFF;
    // 0x8005DAB8: sll         $t4, $t7, 12
    ctx->r12 = S32(ctx->r15 << 12);
    // 0x8005DABC: or          $t9, $t4, $t3
    ctx->r25 = ctx->r12 | ctx->r11;
    // 0x8005DAC0: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8005DAC4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005DAC8: lui         $t2, 0xE100
    ctx->r10 = S32(0XE100 << 16);
    // 0x8005DACC: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x8005DAD0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005DAD4: lui         $t1, 0xF100
    ctx->r9 = S32(0XF100 << 16);
    // 0x8005DAD8: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8005DADC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005DAE0: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8005DAE4: nop

    // 0x8005DAE8: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x8005DAEC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8005DAF0: nop

    // 0x8005DAF4: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8005DAF8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005DAFC: nop

    // 0x8005DB00: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x8005DB04: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005DB08: nop

    // 0x8005DB0C: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x8005DB10: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005DB14: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8005DB18: nop

    // 0x8005DB1C: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x8005DB20: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x8005DB24: lw          $t4, 0x1A8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A8);
    // 0x8005DB28: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x8005DB2C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8005DB30: sll         $t7, $t2, 16
    ctx->r15 = S32(ctx->r10 << 16);
    // 0x8005DB34: andi        $t3, $t4, 0xFFFF
    ctx->r11 = ctx->r12 & 0XFFFF;
    // 0x8005DB38: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x8005DB3C: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8005DB40: sw          $zero, 0x168($sp)
    MEM_W(0X168, ctx->r29) = 0;
L_8005DB44:
    // 0x8005DB44: lw          $t1, 0x168($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X168);
    // 0x8005DB48: nop

    // 0x8005DB4C: bne         $t1, $zero, L_8005C608
    if (ctx->r9 != 0) {
        // 0x8005DB50: nop
    
            goto L_8005C608;
    }
    // 0x8005DB50: nop

L_8005DB54:
    // 0x8005DB54: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005DB58: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8005DB5C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8005DB60: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005DB64: nop

    // 0x8005DB68: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8005DB6C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005DB70: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8005DB74: nop

    // 0x8005DB78: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8005DB7C: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005DB80: nop

    // 0x8005DB84: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
L_8005DB88:
    // 0x8005DB88: jr          $ra
    // 0x8005DB8C: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
    return;
    // 0x8005DB8C: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
;}

RECOMP_FUNC void func_8005DB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DB90: beq         $a1, $zero, L_8005EBFC
    if (ctx->r5 == 0) {
        // 0x8005DB94: addiu       $sp, $sp, -0xE8
        ctx->r29 = ADD32(ctx->r29, -0XE8);
            goto L_8005EBFC;
    }
    // 0x8005DB94: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8005DB98: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x8005DB9C: nop

    // 0x8005DBA0: beq         $t6, $zero, L_8005EBFC
    if (ctx->r14 == 0) {
        // 0x8005DBA4: nop
    
            goto L_8005EBFC;
    }
    // 0x8005DBA4: nop

    // 0x8005DBA8: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x8005DBAC: nop

    // 0x8005DBB0: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x8005DBB4: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x8005DBB8: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x8005DBBC: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x8005DBC0: lhu         $t9, 0x4($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X4);
    // 0x8005DBC4: blez        $t1, L_8005EBFC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8005DBC8: sw          $t9, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r25;
            goto L_8005EBFC;
    }
    // 0x8005DBC8: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
    // 0x8005DBCC: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x8005DBD0: nop

    // 0x8005DBD4: blez        $t2, L_8005EBFC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8005DBD8: nop
    
            goto L_8005EBFC;
    }
    // 0x8005DBD8: nop

    // 0x8005DBDC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005DBE0: lh          $t3, 0x164($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X164);
    // 0x8005DBE4: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x8005DBE8: nop

    // 0x8005DBEC: beq         $t3, $t4, L_8005DE58
    if (ctx->r11 == ctx->r12) {
        // 0x8005DBF0: nop
    
            goto L_8005DE58;
    }
    // 0x8005DBF0: nop

    // 0x8005DBF4: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x8005DBF8: beq         $t0, $zero, L_8005DC20
    if (ctx->r8 == 0) {
        // 0x8005DBFC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005DC20;
    }
    // 0x8005DBFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DC00: beq         $t0, $at, L_8005DCA0
    if (ctx->r8 == ctx->r1) {
        // 0x8005DC04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005DCA0;
    }
    // 0x8005DC04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005DC08: beq         $t0, $at, L_8005DC60
    if (ctx->r8 == ctx->r1) {
        // 0x8005DC0C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005DC60;
    }
    // 0x8005DC0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005DC10: beq         $t0, $at, L_8005DCE0
    if (ctx->r8 == ctx->r1) {
        // 0x8005DC14: nop
    
            goto L_8005DCE0;
    }
    // 0x8005DC14: nop

    // 0x8005DC18: b           L_8005EBFC
    // 0x8005DC1C: nop

        goto L_8005EBFC;
    // 0x8005DC1C: nop

L_8005DC20:
    // 0x8005DC20: addiu       $t5, $zero, 0x800
    ctx->r13 = ADD32(0, 0X800);
    // 0x8005DC24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DC28: sw          $t5, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r13;
    // 0x8005DC2C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005DC30: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8005DC34: sw          $t6, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r14;
    // 0x8005DC38: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005DC3C: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x8005DC40: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005DC44: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005DC48: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x8005DC4C: nop

    // 0x8005DC50: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DC54: lw          $t2, 0xD0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD0);
    // 0x8005DC58: b           L_8005DFA0
    // 0x8005DC5C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
        goto L_8005DFA0;
    // 0x8005DC5C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_8005DC60:
    // 0x8005DC60: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x8005DC64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DC68: sw          $t3, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r11;
    // 0x8005DC6C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005DC70: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x8005DC74: sw          $t4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r12;
    // 0x8005DC78: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005DC7C: ori         $t7, $t7, 0x1001
    ctx->r15 = ctx->r15 | 0X1001;
    // 0x8005DC80: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005DC84: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005DC88: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8005DC8C: nop

    // 0x8005DC90: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005DC94: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8005DC98: b           L_8005DFA0
    // 0x8005DC9C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
        goto L_8005DFA0;
    // 0x8005DC9C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_8005DCA0:
    // 0x8005DCA0: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x8005DCA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DCA8: sw          $t1, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r9;
    // 0x8005DCAC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005DCB0: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x8005DCB4: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x8005DCB8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005DCBC: ori         $t5, $t5, 0x1001
    ctx->r13 = ctx->r13 | 0X1001;
    // 0x8005DCC0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005DCC4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005DCC8: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8005DCCC: nop

    // 0x8005DCD0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005DCD4: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8005DCD8: b           L_8005DFA0
    // 0x8005DCDC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
        goto L_8005DFA0;
    // 0x8005DCDC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
L_8005DCE0:
    // 0x8005DCE0: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x8005DCE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DCE8: sw          $t8, 0x160($at)
    MEM_W(0X160, ctx->r1) = ctx->r24;
    // 0x8005DCEC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005DCF0: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x8005DCF4: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x8005DCF8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005DCFC: ori         $t3, $t3, 0x1001
    ctx->r11 = ctx->r11 | 0X1001;
    // 0x8005DD00: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8005DD04: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005DD08: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x8005DD0C: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x8005DD10: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8005DD14: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x8005DD18: lui         $t1, 0xFD10
    ctx->r9 = S32(0XFD10 << 16);
    // 0x8005DD1C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8005DD20: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005DD24: nop

    // 0x8005DD28: sw          $t7, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r15;
    // 0x8005DD2C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005DD30: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8005DD34: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8005DD38: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005DD3C: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8005DD40: nop

    // 0x8005DD44: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8005DD48: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
    // 0x8005DD4C: nop

    // 0x8005DD50: sw          $a2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r6;
    // 0x8005DD54: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005DD58: nop

    // 0x8005DD5C: sw          $t4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r12;
    // 0x8005DD60: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005DD64: lui         $t4, 0xF500
    ctx->r12 = S32(0XF500 << 16);
    // 0x8005DD68: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005DD6C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005DD70: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x8005DD74: ori         $t4, $t4, 0x100
    ctx->r12 = ctx->r12 | 0X100;
    // 0x8005DD78: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005DD7C: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x8005DD80: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8005DD84: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8005DD88: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005DD8C: nop

    // 0x8005DD90: sw          $t1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r9;
    // 0x8005DD94: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005DD98: nop

    // 0x8005DD9C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8005DDA0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005DDA4: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x8005DDA8: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8005DDAC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005DDB0: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8005DDB4: nop

    // 0x8005DDB8: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8005DDBC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005DDC0: nop

    // 0x8005DDC4: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8005DDC8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005DDCC: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8005DDD0: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005DDD4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005DDD8: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x8005DDDC: lui         $t1, 0x73F
    ctx->r9 = S32(0X73F << 16);
    // 0x8005DDE0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8005DDE4: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x8005DDE8: ori         $t1, $t1, 0xC000
    ctx->r9 = ctx->r9 | 0XC000;
    // 0x8005DDEC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8005DDF0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005DDF4: nop

    // 0x8005DDF8: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    // 0x8005DDFC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005DE00: nop

    // 0x8005DE04: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8005DE08: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005DE0C: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8005DE10: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005DE14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8005DE18: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x8005DE1C: nop

    // 0x8005DE20: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8005DE24: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005DE28: nop

    // 0x8005DE2C: sw          $t3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r11;
    // 0x8005DE30: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005DE34: nop

    // 0x8005DE38: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005DE3C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005DE40: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8005DE44: nop

    // 0x8005DE48: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005DE4C: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x8005DE50: b           L_8005DFA0
    // 0x8005DE54: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
        goto L_8005DFA0;
    // 0x8005DE54: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
L_8005DE58:
    // 0x8005DE58: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x8005DE5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005DE60: bne         $t9, $at, L_8005DFA0
    if (ctx->r25 != ctx->r1) {
        // 0x8005DE64: nop
    
            goto L_8005DFA0;
    }
    // 0x8005DE64: nop

    // 0x8005DE68: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005DE6C: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x8005DE70: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x8005DE74: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005DE78: lui         $t1, 0xE800
    ctx->r9 = S32(0XE800 << 16);
    // 0x8005DE7C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8005DE80: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005DE84: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x8005DE88: nop

    // 0x8005DE8C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005DE90: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8005DE94: nop

    // 0x8005DE98: sw          $a2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r6;
    // 0x8005DE9C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005DEA0: nop

    // 0x8005DEA4: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x8005DEA8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005DEAC: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8005DEB0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8005DEB4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005DEB8: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x8005DEBC: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8005DEC0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8005DEC4: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x8005DEC8: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8005DECC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005DED0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005DED4: nop

    // 0x8005DED8: sw          $t4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r12;
    // 0x8005DEDC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005DEE0: nop

    // 0x8005DEE4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8005DEE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005DEEC: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x8005DEF0: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8005DEF4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8005DEF8: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x8005DEFC: nop

    // 0x8005DF00: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8005DF04: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005DF08: nop

    // 0x8005DF0C: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    // 0x8005DF10: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005DF14: lui         $t2, 0xF000
    ctx->r10 = S32(0XF000 << 16);
    // 0x8005DF18: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8005DF1C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005DF20: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8005DF24: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x8005DF28: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8005DF2C: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8005DF30: ori         $t4, $t4, 0xC000
    ctx->r12 = ctx->r12 | 0XC000;
    // 0x8005DF34: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8005DF38: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005DF3C: nop

    // 0x8005DF40: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8005DF44: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005DF48: nop

    // 0x8005DF4C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005DF50: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005DF54: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x8005DF58: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8005DF5C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8005DF60: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x8005DF64: nop

    // 0x8005DF68: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8005DF6C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005DF70: nop

    // 0x8005DF74: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x8005DF78: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005DF7C: nop

    // 0x8005DF80: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8005DF84: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005DF88: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8005DF8C: nop

    // 0x8005DF90: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005DF94: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x8005DF98: nop

    // 0x8005DF9C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_8005DFA0:
    // 0x8005DFA0: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8005DFA4: lbu         $t3, 0x168($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X168);
    // 0x8005DFA8: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8005DFAC: nop

    // 0x8005DFB0: bne         $t3, $t4, L_8005E018
    if (ctx->r11 != ctx->r12) {
        // 0x8005DFB4: nop
    
            goto L_8005E018;
    }
    // 0x8005DFB4: nop

    // 0x8005DFB8: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8005DFBC: lbu         $t5, 0x16C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X16C);
    // 0x8005DFC0: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x8005DFC4: nop

    // 0x8005DFC8: bne         $t5, $t6, L_8005E018
    if (ctx->r13 != ctx->r14) {
        // 0x8005DFCC: nop
    
            goto L_8005E018;
    }
    // 0x8005DFCC: nop

    // 0x8005DFD0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005DFD4: lbu         $t7, 0x170($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X170);
    // 0x8005DFD8: lw          $t8, 0x104($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X104);
    // 0x8005DFDC: nop

    // 0x8005DFE0: bne         $t7, $t8, L_8005E018
    if (ctx->r15 != ctx->r24) {
        // 0x8005DFE4: nop
    
            goto L_8005E018;
    }
    // 0x8005DFE4: nop

    // 0x8005DFE8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8005DFEC: lbu         $t9, 0x174($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X174);
    // 0x8005DFF0: lw          $t1, 0x108($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X108);
    // 0x8005DFF4: nop

    // 0x8005DFF8: bne         $t9, $t1, L_8005E018
    if (ctx->r25 != ctx->r9) {
        // 0x8005DFFC: nop
    
            goto L_8005E018;
    }
    // 0x8005DFFC: nop

    // 0x8005E000: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8005E004: lh          $t2, 0x164($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X164);
    // 0x8005E008: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x8005E00C: nop

    // 0x8005E010: beq         $t2, $t3, L_8005E1C4
    if (ctx->r10 == ctx->r11) {
        // 0x8005E014: nop
    
            goto L_8005E1C4;
    }
    // 0x8005E014: nop

L_8005E018:
    // 0x8005E018: lw          $t4, 0x108($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X108);
    // 0x8005E01C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005E020: bne         $t4, $at, L_8005E090
    if (ctx->r12 != ctx->r1) {
        // 0x8005E024: nop
    
            goto L_8005E090;
    }
    // 0x8005E024: nop

    // 0x8005E028: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x8005E02C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005E030: bne         $t5, $at, L_8005E090
    if (ctx->r13 != ctx->r1) {
        // 0x8005E034: nop
    
            goto L_8005E090;
    }
    // 0x8005E034: nop

    // 0x8005E038: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x8005E03C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005E040: bne         $t6, $at, L_8005E090
    if (ctx->r14 != ctx->r1) {
        // 0x8005E044: nop
    
            goto L_8005E090;
    }
    // 0x8005E044: nop

    // 0x8005E048: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x8005E04C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005E050: bne         $t7, $at, L_8005E090
    if (ctx->r15 != ctx->r1) {
        // 0x8005E054: nop
    
            goto L_8005E090;
    }
    // 0x8005E054: nop

    // 0x8005E058: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005E05C: lui         $t2, 0xFCFF
    ctx->r10 = S32(0XFCFF << 16);
    // 0x8005E060: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x8005E064: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005E068: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x8005E06C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8005E070: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005E074: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x8005E078: lui         $t4, 0xFFFC
    ctx->r12 = S32(0XFFFC << 16);
    // 0x8005E07C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8005E080: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x8005E084: ori         $t4, $t4, 0xF279
    ctx->r12 = ctx->r12 | 0XF279;
    // 0x8005E088: b           L_8005E194
    // 0x8005E08C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
        goto L_8005E194;
    // 0x8005E08C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
L_8005E090:
    // 0x8005E090: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8005E094: lbu         $t6, 0x168($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X168);
    // 0x8005E098: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005E09C: bne         $t6, $at, L_8005E0E0
    if (ctx->r14 != ctx->r1) {
        // 0x8005E0A0: nop
    
            goto L_8005E0E0;
    }
    // 0x8005E0A0: nop

    // 0x8005E0A4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005E0A8: lbu         $t7, 0x16C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X16C);
    // 0x8005E0AC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005E0B0: bne         $t7, $at, L_8005E0E0
    if (ctx->r15 != ctx->r1) {
        // 0x8005E0B4: nop
    
            goto L_8005E0E0;
    }
    // 0x8005E0B4: nop

    // 0x8005E0B8: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x8005E0BC: lbu         $t8, 0x170($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X170);
    // 0x8005E0C0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005E0C4: bne         $t8, $at, L_8005E0E0
    if (ctx->r24 != ctx->r1) {
        // 0x8005E0C8: nop
    
            goto L_8005E0E0;
    }
    // 0x8005E0C8: nop

    // 0x8005E0CC: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8005E0D0: lbu         $t9, 0x174($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X174);
    // 0x8005E0D4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005E0D8: beq         $t9, $at, L_8005E0F8
    if (ctx->r25 == ctx->r1) {
        // 0x8005E0DC: nop
    
            goto L_8005E0F8;
    }
    // 0x8005E0DC: nop

L_8005E0E0:
    // 0x8005E0E0: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8005E0E4: lh          $t1, 0x164($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X164);
    // 0x8005E0E8: lw          $t2, 0xDC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XDC);
    // 0x8005E0EC: nop

    // 0x8005E0F0: beq         $t1, $t2, L_8005E12C
    if (ctx->r9 == ctx->r10) {
        // 0x8005E0F4: nop
    
            goto L_8005E12C;
    }
    // 0x8005E0F4: nop

L_8005E0F8:
    // 0x8005E0F8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005E0FC: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x8005E100: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x8005E104: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E108: ori         $t6, $t6, 0x9623
    ctx->r14 = ctx->r14 | 0X9623;
    // 0x8005E10C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005E110: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005E114: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8005E118: lui         $t8, 0xFF2F
    ctx->r24 = S32(0XFF2F << 16);
    // 0x8005E11C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8005E120: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8005E124: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8005E128: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_8005E12C:
    // 0x8005E12C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005E130: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8005E134: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x8005E138: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005E13C: nop

    // 0x8005E140: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8005E144: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005E148: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8005E14C: nop

    // 0x8005E150: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005E154: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x8005E158: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x8005E15C: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x8005E160: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8005E164: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8005E168: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8005E16C: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8005E170: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x8005E174: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x8005E178: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8005E17C: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8005E180: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8005E184: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8005E188: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8005E18C: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x8005E190: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
L_8005E194:
    // 0x8005E194: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x8005E198: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E19C: lw          $t5, 0x100($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X100);
    // 0x8005E1A0: sb          $t4, 0x168($at)
    MEM_B(0X168, ctx->r1) = ctx->r12;
    // 0x8005E1A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E1A8: lw          $t3, 0x104($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X104);
    // 0x8005E1AC: sb          $t5, 0x16C($at)
    MEM_B(0X16C, ctx->r1) = ctx->r13;
    // 0x8005E1B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E1B4: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x8005E1B8: sb          $t3, 0x170($at)
    MEM_B(0X170, ctx->r1) = ctx->r11;
    // 0x8005E1BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E1C0: sb          $t6, 0x174($at)
    MEM_B(0X174, ctx->r1) = ctx->r14;
L_8005E1C4:
    // 0x8005E1C4: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x8005E1C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005E1CC: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8005E1D0: beq         $t0, $zero, L_8005E1FC
    if (ctx->r8 == 0) {
        // 0x8005E1D4: sh          $t9, 0x164($at)
        MEM_H(0X164, ctx->r1) = ctx->r25;
            goto L_8005E1FC;
    }
    // 0x8005E1D4: sh          $t9, 0x164($at)
    MEM_H(0X164, ctx->r1) = ctx->r25;
    // 0x8005E1D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E1DC: beq         $t0, $at, L_8005E3FC
    if (ctx->r8 == ctx->r1) {
        // 0x8005E1E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005E3FC;
    }
    // 0x8005E1E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E1E4: beq         $t0, $at, L_8005E600
    if (ctx->r8 == ctx->r1) {
        // 0x8005E1E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005E600;
    }
    // 0x8005E1E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005E1EC: beq         $t0, $at, L_8005E7F8
    if (ctx->r8 == ctx->r1) {
        // 0x8005E1F0: nop
    
            goto L_8005E7F8;
    }
    // 0x8005E1F0: nop

    // 0x8005E1F4: b           L_8005E9EC
    // 0x8005E1F8: nop

        goto L_8005E9EC;
    // 0x8005E1F8: nop

L_8005E1FC:
    // 0x8005E1FC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005E200: lui         $at, 0xFD10
    ctx->r1 = S32(0XFD10 << 16);
    // 0x8005E204: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    // 0x8005E208: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005E20C: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x8005E210: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x8005E214: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005E218: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E21C: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8005E220: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x8005E224: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x8005E228: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x8005E22C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8005E230: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8005E234: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005E238: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8005E23C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005E240: nop

    // 0x8005E244: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x8005E248: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005E24C: nop

    // 0x8005E250: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8005E254: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E258: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E25C: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8005E260: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8005E264: addiu       $t3, $t5, 0x7
    ctx->r11 = ADD32(ctx->r13, 0X7);
    // 0x8005E268: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8005E26C: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8005E270: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8005E274: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x8005E278: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8005E27C: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x8005E280: lui         $t2, 0x708
    ctx->r10 = S32(0X708 << 16);
    // 0x8005E284: ori         $t2, $t2, 0x200
    ctx->r10 = ctx->r10 | 0X200;
    // 0x8005E288: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8005E28C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005E290: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8005E294: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8005E298: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005E29C: lui         $t5, 0xF400
    ctx->r13 = S32(0XF400 << 16);
    // 0x8005E2A0: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x8005E2A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005E2A8: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8005E2AC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005E2B0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8005E2B4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8005E2B8: nop

    // 0x8005E2BC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8005E2C0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005E2C4: nop

    // 0x8005E2C8: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x8005E2CC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005E2D0: nop

    // 0x8005E2D4: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8005E2D8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005E2DC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8005E2E0: nop

    // 0x8005E2E4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8005E2E8: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E2EC: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8005E2F0: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8005E2F4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8005E2F8: andi        $t1, $t7, 0xFFF
    ctx->r9 = ctx->r15 & 0XFFF;
    // 0x8005E2FC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8005E300: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8005E304: sll         $t8, $t1, 12
    ctx->r24 = S32(ctx->r9 << 12);
    // 0x8005E308: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8005E30C: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x8005E310: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x8005E314: or          $t9, $t2, $t6
    ctx->r25 = ctx->r10 | ctx->r14;
    // 0x8005E318: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8005E31C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005E320: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8005E324: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8005E328: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005E32C: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8005E330: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x8005E334: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005E338: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8005E33C: nop

    // 0x8005E340: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8005E344: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8005E348: nop

    // 0x8005E34C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8005E350: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005E354: nop

    // 0x8005E358: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x8005E35C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005E360: nop

    // 0x8005E364: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8005E368: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005E36C: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E370: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8005E374: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x8005E378: addiu       $t4, $t8, 0x7
    ctx->r12 = ADD32(ctx->r24, 0X7);
    // 0x8005E37C: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8005E380: andi        $t3, $t5, 0x1FF
    ctx->r11 = ctx->r13 & 0X1FF;
    // 0x8005E384: sll         $t2, $t3, 9
    ctx->r10 = S32(ctx->r11 << 9);
    // 0x8005E388: or          $t6, $t2, $at
    ctx->r14 = ctx->r10 | ctx->r1;
    // 0x8005E38C: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8005E390: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E394: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8005E398: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8005E39C: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8005E3A0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005E3A4: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x8005E3A8: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x8005E3AC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E3B0: nop

    // 0x8005E3B4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8005E3B8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005E3BC: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8005E3C0: nop

    // 0x8005E3C4: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8005E3C8: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E3CC: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8005E3D0: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8005E3D4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8005E3D8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8005E3DC: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8005E3E0: andi        $t1, $t7, 0xFFF
    ctx->r9 = ctx->r15 & 0XFFF;
    // 0x8005E3E4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8005E3E8: sll         $t8, $t1, 12
    ctx->r24 = S32(ctx->r9 << 12);
    // 0x8005E3EC: andi        $t2, $t3, 0xFFF
    ctx->r10 = ctx->r11 & 0XFFF;
    // 0x8005E3F0: or          $t6, $t8, $t2
    ctx->r14 = ctx->r24 | ctx->r10;
    // 0x8005E3F4: b           L_8005E9EC
    // 0x8005E3F8: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
        goto L_8005E9EC;
    // 0x8005E3F8: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
L_8005E3FC:
    // 0x8005E3FC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005E400: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x8005E404: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x8005E408: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005E40C: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x8005E410: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x8005E414: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005E418: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E41C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8005E420: sra         $t3, $t5, 1
    ctx->r11 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8005E424: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x8005E428: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x8005E42C: or          $t6, $t2, $at
    ctx->r14 = ctx->r10 | ctx->r1;
    // 0x8005E430: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8005E434: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8005E438: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8005E43C: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8005E440: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E444: nop

    // 0x8005E448: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x8005E44C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005E450: nop

    // 0x8005E454: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x8005E458: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005E45C: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E460: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8005E464: sra         $t2, $t8, 1
    ctx->r10 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8005E468: addiu       $t6, $t2, 0x7
    ctx->r14 = ADD32(ctx->r10, 0X7);
    // 0x8005E46C: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8005E470: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8005E474: sll         $t1, $t7, 9
    ctx->r9 = S32(ctx->r15 << 9);
    // 0x8005E478: or          $t4, $t1, $at
    ctx->r12 = ctx->r9 | ctx->r1;
    // 0x8005E47C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005E480: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8005E484: lui         $t3, 0x708
    ctx->r11 = S32(0X708 << 16);
    // 0x8005E488: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x8005E48C: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8005E490: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005E494: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8005E498: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8005E49C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005E4A0: lui         $t2, 0xF400
    ctx->r10 = S32(0XF400 << 16);
    // 0x8005E4A4: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8005E4A8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005E4AC: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8005E4B0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005E4B4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8005E4B8: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8005E4BC: nop

    // 0x8005E4C0: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8005E4C4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005E4C8: nop

    // 0x8005E4CC: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x8005E4D0: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005E4D4: nop

    // 0x8005E4D8: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x8005E4DC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005E4E0: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8005E4E4: nop

    // 0x8005E4E8: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8005E4EC: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E4F0: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8005E4F4: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x8005E4F8: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x8005E4FC: andi        $t4, $t1, 0xFFF
    ctx->r12 = ctx->r9 & 0XFFF;
    // 0x8005E500: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x8005E504: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8005E508: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x8005E50C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8005E510: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x8005E514: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8005E518: or          $t7, $t3, $t9
    ctx->r15 = ctx->r11 | ctx->r25;
    // 0x8005E51C: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8005E520: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E524: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8005E528: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x8005E52C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005E530: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8005E534: addiu       $t8, $t5, 0x8
    ctx->r24 = ADD32(ctx->r13, 0X8);
    // 0x8005E538: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005E53C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8005E540: nop

    // 0x8005E544: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x8005E548: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8005E54C: nop

    // 0x8005E550: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8005E554: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005E558: nop

    // 0x8005E55C: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x8005E560: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005E564: nop

    // 0x8005E568: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x8005E56C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005E570: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E574: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8005E578: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8005E57C: addiu       $t8, $t5, 0x7
    ctx->r24 = ADD32(ctx->r13, 0X7);
    // 0x8005E580: sra         $t2, $t8, 3
    ctx->r10 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8005E584: andi        $t6, $t2, 0x1FF
    ctx->r14 = ctx->r10 & 0X1FF;
    // 0x8005E588: sll         $t3, $t6, 9
    ctx->r11 = S32(ctx->r14 << 9);
    // 0x8005E58C: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x8005E590: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8005E594: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8005E598: lui         $t1, 0x8
    ctx->r9 = S32(0X8 << 16);
    // 0x8005E59C: ori         $t1, $t1, 0x200
    ctx->r9 = ctx->r9 | 0X200;
    // 0x8005E5A0: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8005E5A4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005E5A8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8005E5AC: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x8005E5B0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005E5B4: nop

    // 0x8005E5B8: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8005E5BC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E5C0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8005E5C4: nop

    // 0x8005E5C8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8005E5CC: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E5D0: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8005E5D4: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x8005E5D8: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8005E5DC: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x8005E5E0: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8005E5E4: andi        $t4, $t1, 0xFFF
    ctx->r12 = ctx->r9 & 0XFFF;
    // 0x8005E5E8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8005E5EC: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x8005E5F0: andi        $t3, $t6, 0xFFF
    ctx->r11 = ctx->r14 & 0XFFF;
    // 0x8005E5F4: or          $t9, $t5, $t3
    ctx->r25 = ctx->r13 | ctx->r11;
    // 0x8005E5F8: b           L_8005E9EC
    // 0x8005E5FC: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
        goto L_8005E9EC;
    // 0x8005E5FC: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_8005E600:
    // 0x8005E600: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005E604: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x8005E608: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8005E60C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E610: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x8005E614: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x8005E618: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8005E61C: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E620: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8005E624: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8005E628: andi        $t5, $t6, 0xFFF
    ctx->r13 = ctx->r14 & 0XFFF;
    // 0x8005E62C: or          $t3, $t5, $at
    ctx->r11 = ctx->r13 | ctx->r1;
    // 0x8005E630: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8005E634: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8005E638: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005E63C: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8005E640: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E644: nop

    // 0x8005E648: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x8005E64C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005E650: nop

    // 0x8005E654: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8005E658: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E65C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E660: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8005E664: addiu       $t5, $t6, 0x7
    ctx->r13 = ADD32(ctx->r14, 0X7);
    // 0x8005E668: sra         $t3, $t5, 3
    ctx->r11 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8005E66C: andi        $t9, $t3, 0x1FF
    ctx->r25 = ctx->r11 & 0X1FF;
    // 0x8005E670: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8005E674: or          $t1, $t7, $at
    ctx->r9 = ctx->r15 | ctx->r1;
    // 0x8005E678: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x8005E67C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8005E680: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x8005E684: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8005E688: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8005E68C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005E690: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8005E694: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8005E698: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005E69C: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x8005E6A0: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x8005E6A4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005E6A8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8005E6AC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005E6B0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8005E6B4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8005E6B8: nop

    // 0x8005E6BC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8005E6C0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E6C4: nop

    // 0x8005E6C8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8005E6CC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005E6D0: nop

    // 0x8005E6D4: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x8005E6D8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E6DC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8005E6E0: nop

    // 0x8005E6E4: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8005E6E8: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E6EC: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x8005E6F0: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x8005E6F4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8005E6F8: andi        $t1, $t7, 0xFFF
    ctx->r9 = ctx->r15 & 0XFFF;
    // 0x8005E6FC: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8005E700: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8005E704: sll         $t4, $t1, 12
    ctx->r12 = S32(ctx->r9 << 12);
    // 0x8005E708: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8005E70C: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x8005E710: andi        $t3, $t5, 0xFFF
    ctx->r11 = ctx->r13 & 0XFFF;
    // 0x8005E714: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x8005E718: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8005E71C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005E720: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005E724: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8005E728: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E72C: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8005E730: addiu       $t2, $t4, 0x8
    ctx->r10 = ADD32(ctx->r12, 0X8);
    // 0x8005E734: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E738: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E73C: nop

    // 0x8005E740: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8005E744: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E748: nop

    // 0x8005E74C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8005E750: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005E754: nop

    // 0x8005E758: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8005E75C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005E760: nop

    // 0x8005E764: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8005E768: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005E76C: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E770: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005E774: addiu       $t4, $t1, 0x7
    ctx->r12 = ADD32(ctx->r9, 0X7);
    // 0x8005E778: sra         $t2, $t4, 3
    ctx->r10 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8005E77C: andi        $t6, $t2, 0x1FF
    ctx->r14 = ctx->r10 & 0X1FF;
    // 0x8005E780: sll         $t5, $t6, 9
    ctx->r13 = S32(ctx->r14 << 9);
    // 0x8005E784: or          $t8, $t5, $at
    ctx->r24 = ctx->r13 | ctx->r1;
    // 0x8005E788: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8005E78C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005E790: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8005E794: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x8005E798: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8005E79C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005E7A0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8005E7A4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8005E7A8: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E7AC: nop

    // 0x8005E7B0: addiu       $t2, $t4, 0x8
    ctx->r10 = ADD32(ctx->r12, 0X8);
    // 0x8005E7B4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E7B8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005E7BC: nop

    // 0x8005E7C0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8005E7C4: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E7C8: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8005E7CC: addiu       $t3, $t8, -0x1
    ctx->r11 = ADD32(ctx->r24, -0X1);
    // 0x8005E7D0: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8005E7D4: addiu       $t2, $t4, -0x1
    ctx->r10 = ADD32(ctx->r12, -0X1);
    // 0x8005E7D8: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8005E7DC: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8005E7E0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8005E7E4: sll         $t1, $t7, 12
    ctx->r9 = S32(ctx->r15 << 12);
    // 0x8005E7E8: andi        $t5, $t6, 0xFFF
    ctx->r13 = ctx->r14 & 0XFFF;
    // 0x8005E7EC: or          $t8, $t1, $t5
    ctx->r24 = ctx->r9 | ctx->r13;
    // 0x8005E7F0: b           L_8005E9EC
    // 0x8005E7F4: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
        goto L_8005E9EC;
    // 0x8005E7F4: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
L_8005E7F8:
    // 0x8005E7F8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005E7FC: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x8005E800: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8005E804: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005E808: addiu       $t3, $a1, 0x8
    ctx->r11 = ADD32(ctx->r5, 0X8);
    // 0x8005E80C: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x8005E810: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8005E814: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E818: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8005E81C: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8005E820: andi        $t1, $t6, 0xFFF
    ctx->r9 = ctx->r14 & 0XFFF;
    // 0x8005E824: or          $t5, $t1, $at
    ctx->r13 = ctx->r9 | ctx->r1;
    // 0x8005E828: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8005E82C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005E830: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005E834: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x8005E838: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005E83C: nop

    // 0x8005E840: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8005E844: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E848: nop

    // 0x8005E84C: addiu       $t2, $t4, 0x8
    ctx->r10 = ADD32(ctx->r12, 0X8);
    // 0x8005E850: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E854: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E858: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E85C: addiu       $t1, $t6, 0x7
    ctx->r9 = ADD32(ctx->r14, 0X7);
    // 0x8005E860: sra         $t5, $t1, 3
    ctx->r13 = S32(SIGNED(ctx->r9) >> 3);
    // 0x8005E864: andi        $t8, $t5, 0x1FF
    ctx->r24 = ctx->r13 & 0X1FF;
    // 0x8005E868: sll         $t3, $t8, 9
    ctx->r11 = S32(ctx->r24 << 9);
    // 0x8005E86C: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x8005E870: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8005E874: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E878: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x8005E87C: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x8005E880: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x8005E884: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005E888: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8005E88C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8005E890: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8005E894: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x8005E898: addiu       $t5, $t1, 0x8
    ctx->r13 = ADD32(ctx->r9, 0X8);
    // 0x8005E89C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8005E8A0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005E8A4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8005E8A8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8005E8AC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005E8B0: nop

    // 0x8005E8B4: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8005E8B8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005E8BC: nop

    // 0x8005E8C0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8005E8C4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005E8C8: nop

    // 0x8005E8CC: addiu       $t2, $t4, 0x8
    ctx->r10 = ADD32(ctx->r12, 0X8);
    // 0x8005E8D0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E8D4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8005E8D8: nop

    // 0x8005E8DC: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005E8E0: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E8E4: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x8005E8E8: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8005E8EC: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8005E8F0: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8005E8F4: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8005E8F8: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x8005E8FC: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8005E900: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005E904: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x8005E908: andi        $t5, $t1, 0xFFF
    ctx->r13 = ctx->r9 & 0XFFF;
    // 0x8005E90C: or          $t8, $t4, $t5
    ctx->r24 = ctx->r12 | ctx->r13;
    // 0x8005E910: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8005E914: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005E918: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005E91C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8005E920: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005E924: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8005E928: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x8005E92C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E930: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8005E934: nop

    // 0x8005E938: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005E93C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8005E940: nop

    // 0x8005E944: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8005E948: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005E94C: nop

    // 0x8005E950: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8005E954: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005E958: nop

    // 0x8005E95C: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x8005E960: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005E964: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E968: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E96C: addiu       $t7, $t9, 0x7
    ctx->r15 = ADD32(ctx->r25, 0X7);
    // 0x8005E970: sra         $t2, $t7, 3
    ctx->r10 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8005E974: andi        $t6, $t2, 0x1FF
    ctx->r14 = ctx->r10 & 0X1FF;
    // 0x8005E978: sll         $t1, $t6, 9
    ctx->r9 = S32(ctx->r14 << 9);
    // 0x8005E97C: or          $t4, $t1, $at
    ctx->r12 = ctx->r9 | ctx->r1;
    // 0x8005E980: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8005E984: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E988: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8005E98C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8005E990: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8005E994: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005E998: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8005E99C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8005E9A0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005E9A4: nop

    // 0x8005E9A8: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x8005E9AC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005E9B0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8005E9B4: nop

    // 0x8005E9B8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005E9BC: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E9C0: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x8005E9C4: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8005E9C8: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8005E9CC: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x8005E9D0: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8005E9D4: andi        $t3, $t8, 0xFFF
    ctx->r11 = ctx->r24 & 0XFFF;
    // 0x8005E9D8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8005E9DC: sll         $t9, $t3, 12
    ctx->r25 = S32(ctx->r11 << 12);
    // 0x8005E9E0: andi        $t1, $t6, 0xFFF
    ctx->r9 = ctx->r14 & 0XFFF;
    // 0x8005E9E4: or          $t4, $t9, $t1
    ctx->r12 = ctx->r25 | ctx->r9;
    // 0x8005E9E8: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
L_8005E9EC:
    // 0x8005E9EC: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x8005E9F0: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x8005E9F4: sll         $t3, $t8, 10
    ctx->r11 = S32(ctx->r24 << 10);
    // 0x8005E9F8: div         $zero, $t3, $t7
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r15)));
    // 0x8005E9FC: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8005EA00: lw          $t4, 0x110($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X110);
    // 0x8005EA04: sll         $t1, $t9, 10
    ctx->r9 = S32(ctx->r25 << 10);
    // 0x8005EA08: bne         $t7, $zero, L_8005EA14
    if (ctx->r15 != 0) {
        // 0x8005EA0C: nop
    
            goto L_8005EA14;
    }
    // 0x8005EA0C: nop

    // 0x8005EA10: break       7
    do_break(2147871248);
L_8005EA14:
    // 0x8005EA14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005EA18: bne         $t7, $at, L_8005EA2C
    if (ctx->r15 != ctx->r1) {
        // 0x8005EA1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005EA2C;
    }
    // 0x8005EA1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005EA20: bne         $t3, $at, L_8005EA2C
    if (ctx->r11 != ctx->r1) {
        // 0x8005EA24: nop
    
            goto L_8005EA2C;
    }
    // 0x8005EA24: nop

    // 0x8005EA28: break       6
    do_break(2147871272);
L_8005EA2C:
    // 0x8005EA2C: mflo        $t2
    ctx->r10 = lo;
    // 0x8005EA30: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8005EA34: sw          $t6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r14;
    // 0x8005EA38: div         $zero, $t1, $t4
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r12)));
    // 0x8005EA3C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8005EA40: bne         $t4, $zero, L_8005EA4C
    if (ctx->r12 != 0) {
        // 0x8005EA44: nop
    
            goto L_8005EA4C;
    }
    // 0x8005EA44: nop

    // 0x8005EA48: break       7
    do_break(2147871304);
L_8005EA4C:
    // 0x8005EA4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005EA50: bne         $t4, $at, L_8005EA64
    if (ctx->r12 != ctx->r1) {
        // 0x8005EA54: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005EA64;
    }
    // 0x8005EA54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005EA58: bne         $t1, $at, L_8005EA64
    if (ctx->r9 != ctx->r1) {
        // 0x8005EA5C: nop
    
            goto L_8005EA64;
    }
    // 0x8005EA5C: nop

    // 0x8005EA60: break       6
    do_break(2147871328);
L_8005EA64:
    // 0x8005EA64: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8005EA68: mflo        $t5
    ctx->r13 = lo;
    // 0x8005EA6C: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8005EA70: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
    // 0x8005EA74: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8005EA78: nop

    // 0x8005EA7C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8005EA80: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005EA84: nop

    // 0x8005EA88: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x8005EA8C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8005EA90: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8005EA94: nop

    // 0x8005EA98: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8005EA9C: lw          $t1, 0xD8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD8);
    // 0x8005EAA0: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x8005EAA4: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8005EAA8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8005EAAC: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8005EAB0: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8005EAB4: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x8005EAB8: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x8005EABC: sll         $t3, $t8, 12
    ctx->r11 = S32(ctx->r24 << 12);
    // 0x8005EAC0: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8005EAC4: or          $t1, $t3, $t9
    ctx->r9 = ctx->r11 | ctx->r25;
    // 0x8005EAC8: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x8005EACC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005EAD0: nop

    // 0x8005EAD4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005EAD8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005EADC: nop

    // 0x8005EAE0: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8005EAE4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005EAE8: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x8005EAEC: lw          $t5, 0xD8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD8);
    // 0x8005EAF0: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x8005EAF4: addu        $t8, $a3, $t5
    ctx->r24 = ADD32(ctx->r7, ctx->r13);
    // 0x8005EAF8: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x8005EAFC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8005EB00: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x8005EB04: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8005EB08: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8005EB0C: andi        $t6, $t2, 0xFFF
    ctx->r14 = ctx->r10 & 0XFFF;
    // 0x8005EB10: sll         $t3, $t6, 12
    ctx->r11 = S32(ctx->r14 << 12);
    // 0x8005EB14: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x8005EB18: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x8005EB1C: andi        $t4, $t1, 0xFFF
    ctx->r12 = ctx->r9 & 0XFFF;
    // 0x8005EB20: or          $t1, $t9, $t4
    ctx->r9 = ctx->r25 | ctx->r12;
    // 0x8005EB24: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
    // 0x8005EB28: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    // 0x8005EB2C: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8005EB30: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8005EB34: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8005EB38: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x8005EB3C: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8005EB40: sll         $t2, $t7, 12
    ctx->r10 = S32(ctx->r15 << 12);
    // 0x8005EB44: or          $t4, $t2, $t9
    ctx->r12 = ctx->r10 | ctx->r25;
    // 0x8005EB48: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8005EB4C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005EB50: lui         $t6, 0xE100
    ctx->r14 = S32(0XE100 << 16);
    // 0x8005EB54: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x8005EB58: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005EB5C: lui         $t5, 0xF100
    ctx->r13 = S32(0XF100 << 16);
    // 0x8005EB60: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8005EB64: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005EB68: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8005EB6C: nop

    // 0x8005EB70: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8005EB74: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8005EB78: nop

    // 0x8005EB7C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8005EB80: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005EB84: nop

    // 0x8005EB88: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8005EB8C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005EB90: nop

    // 0x8005EB94: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x8005EB98: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005EB9C: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8005EBA0: nop

    // 0x8005EBA4: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8005EBA8: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x8005EBAC: lw          $t2, 0x110($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X110);
    // 0x8005EBB0: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8005EBB4: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8005EBB8: sll         $t3, $t6, 16
    ctx->r11 = S32(ctx->r14 << 16);
    // 0x8005EBBC: andi        $t9, $t2, 0xFFFF
    ctx->r25 = ctx->r10 & 0XFFFF;
    // 0x8005EBC0: or          $t4, $t3, $t9
    ctx->r12 = ctx->r11 | ctx->r25;
    // 0x8005EBC4: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8005EBC8: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005EBCC: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8005EBD0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8005EBD4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8005EBD8: nop

    // 0x8005EBDC: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8005EBE0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005EBE4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBE8: nop

    // 0x8005EBEC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8005EBF0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8005EBF4: nop

    // 0x8005EBF8: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
L_8005EBFC:
    // 0x8005EBFC: jr          $ra
    // 0x8005EC00: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8005EC00: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x8005EC04: nop

    // 0x8005EC08: nop

    // 0x8005EC0C: nop

;}

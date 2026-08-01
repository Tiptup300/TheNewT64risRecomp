#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void PV_ClearAllPlayers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053538: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005353C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053540: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_80053544:
    // 0x80053544: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80053548: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005354C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80053550: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80053554: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80053558: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005355C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80053560: addiu       $t8, $t8, -0x10D0
    ctx->r24 = ADD32(ctx->r24, -0X10D0);
    // 0x80053564: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80053568: jal         0x800B7450
    // 0x8005356C: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    bzero_recomp(rdram, ctx);
        goto after_0;
    // 0x8005356C: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    after_0:
    // 0x80053570: lh          $t9, 0x1E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X1E);
    // 0x80053574: nop

    // 0x80053578: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005357C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80053580: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80053584: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80053588: bne         $at, $zero, L_80053544
    if (ctx->r1 != 0) {
        // 0x8005358C: sh          $t0, 0x1E($sp)
        MEM_H(0X1E, ctx->r29) = ctx->r8;
            goto L_80053544;
    }
    // 0x8005358C: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    // 0x80053590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053594: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80053598: jr          $ra
    // 0x8005359C: nop

    return;
    // 0x8005359C: nop

;}

RECOMP_FUNC void PV_set_controller_no(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800535A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800535A4: lw          $t6, -0xDF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XDF0);
    // 0x800535A8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800535AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800535B0: jr          $ra
    // 0x800535B4: sh          $a0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r4;
    return;
    // 0x800535B4: sh          $a0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r4;
;}

RECOMP_FUNC void PV_ResetPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800535B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800535BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800535C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800535C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800535C8: jal         0x80060CA0
    // 0x800535CC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    ControllerRepeat_Reset(rdram, ctx);
        goto after_0;
    // 0x800535CC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x800535D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800535D4: nop

    // 0x800535D8: sw          $zero, 0x24($t6)
    MEM_W(0X24, ctx->r14) = 0;
    // 0x800535DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800535E0: nop

    // 0x800535E4: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800535E8: nop

    // 0x800535EC: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800535F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800535F4: jal         0x800A3460
    // 0x800535F8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    Minos_Reset(rdram, ctx);
        goto after_1;
    // 0x800535F8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x800535FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053604: jr          $ra
    // 0x80053608: nop

    return;
    // 0x80053608: nop

;}

RECOMP_FUNC void PV_AssertValidCurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005360C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80053610: lw          $t7, -0xDF0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XDF0);
    // 0x80053614: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80053618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005361C: addiu       $t6, $t6, -0x10D0
    ctx->r14 = ADD32(ctx->r14, -0X10D0);
    // 0x80053620: beq         $t6, $t7, L_80053660
    if (ctx->r14 == ctx->r15) {
        // 0x80053624: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80053660;
    }
    // 0x80053624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053628: addiu       $t8, $t6, 0xB8
    ctx->r24 = ADD32(ctx->r14, 0XB8);
    // 0x8005362C: beq         $t8, $t7, L_80053660
    if (ctx->r24 == ctx->r15) {
        // 0x80053630: nop
    
            goto L_80053660;
    }
    // 0x80053630: nop

    // 0x80053634: addiu       $t9, $t6, 0x170
    ctx->r25 = ADD32(ctx->r14, 0X170);
    // 0x80053638: beq         $t9, $t7, L_80053660
    if (ctx->r25 == ctx->r15) {
        // 0x8005363C: nop
    
            goto L_80053660;
    }
    // 0x8005363C: nop

    // 0x80053640: addiu       $t0, $t6, 0x228
    ctx->r8 = ADD32(ctx->r14, 0X228);
    // 0x80053644: beq         $t0, $t7, L_80053660
    if (ctx->r8 == ctx->r15) {
        // 0x80053648: nop
    
            goto L_80053660;
    }
    // 0x80053648: nop

    // 0x8005364C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80053650: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80053654: addiu       $a1, $a1, -0x31F0
    ctx->r5 = ADD32(ctx->r5, -0X31F0);
    // 0x80053658: jal         0x80083560
    // 0x8005365C: addiu       $a0, $a0, -0x3220
    ctx->r4 = ADD32(ctx->r4, -0X3220);
    debug_print_reason_routine(rdram, ctx);
        goto after_0;
    // 0x8005365C: addiu       $a0, $a0, -0x3220
    ctx->r4 = ADD32(ctx->r4, -0X3220);
    after_0:
L_80053660:
    // 0x80053660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80053668: jr          $ra
    // 0x8005366C: nop

    return;
    // 0x8005366C: nop

;}

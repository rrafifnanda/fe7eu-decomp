	.syntax unified
	.thumb
	.global sub_801B528
	.thumb_func
sub_801B528: @ 0x0801B528
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0x81
_0801B52E:
	adds r0, r4, #0
	bl GetUnit
	adds r2, r0, #0
	cmp r2, #0
	beq _0801B562
	ldr r1, [r2]
	cmp r1, #0
	beq _0801B562
	ldr r0, [r2, #4]
	ldr r1, [r1, #0x28]
	ldr r0, [r0, #0x28]
	orrs r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r1, r0
	cmp r1, #0
	beq _0801B562
	movs r0, #0x10
	ldrsb r0, [r2, r0]
	movs r1, #0x11
	ldrsb r1, [r2, r1]
	movs r2, #0xa
	adds r3, r5, #0
	bl sub_801A7B8
_0801B562:
	adds r4, #1
	cmp r4, #0xbf
	ble _0801B52E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

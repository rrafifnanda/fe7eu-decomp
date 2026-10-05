	.syntax unified
	.thumb
	.global sub_803C540
	.thumb_func
sub_803C540: @ 0x0803C540
	push {r4, lr}
	adds r4, r0, #0
	bl GetUnitMovementCost
	bl sub_801A0C0
	ldr r0, _0803C578 @ =0x0202E3E4
	ldr r0, [r0]
	bl SetWorkingBmMap
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	movs r1, #0x11
	ldrsb r1, [r4, r1]
	movs r2, #0x1d
	ldrsb r2, [r4, r2]
	ldr r3, [r4, #4]
	ldrb r3, [r3, #0x12]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r2, r2, r3
	movs r3, #0xb
	ldrsb r3, [r4, r3]
	bl sub_801A0E0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803C578: .4byte 0x0202E3E4

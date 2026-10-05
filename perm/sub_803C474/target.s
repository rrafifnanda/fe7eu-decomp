	.syntax unified
	.thumb
	.global sub_803C474
	.thumb_func
sub_803C474: @ 0x0803C474
	push {r4, lr}
	adds r4, r0, #0
	bl GetUnitMovementCost
	movs r1, #0x1e
	bl sub_803C2F0
	ldr r0, _0803C4A4 @ =0x0202E3E4
	ldr r0, [r0]
	bl SetWorkingBmMap
	movs r0, #0x10
	ldrsb r0, [r4, r0]
	movs r1, #0x11
	ldrsb r1, [r4, r1]
	movs r3, #0xb
	ldrsb r3, [r4, r3]
	movs r2, #0x7c
	bl sub_801A0E0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803C4A4: .4byte 0x0202E3E4

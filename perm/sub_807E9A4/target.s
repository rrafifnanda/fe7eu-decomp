	.syntax unified
	.thumb
	.global sub_807E9A4
	.thumb_func
sub_807E9A4: @ 0x0807E9A4
	push {r4, lr}
	movs r0, #0x27
	bl GetUnitFromCharId
	adds r4, r0, #0
	movs r0, #0x8c
	bl MakeNewItem
	adds r1, r0, #0
	adds r0, r4, #0
	bl UnitAddItem
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

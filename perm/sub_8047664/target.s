	.syntax unified
	.thumb
	.global sub_8047664
	.thumb_func
sub_8047664: @ 0x08047664
	push {lr}
	bl sub_80455BC
	bl sub_804561C
	bl RefreshUnitSprites
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global sub_8046A74
	.thumb_func
sub_8046A74: @ 0x08046A74
	push {lr}
	bl EndAllMus
	bl EndAllMus
	bl sub_80455BC
	bl sub_804561C
	bl RefreshUnitSprites
	pop {r0}
	bx r0
	.align 2, 0

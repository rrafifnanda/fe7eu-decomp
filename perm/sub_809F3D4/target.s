	.syntax unified
	.thumb
	.global sub_809F3D4
	.thumb_func
sub_809F3D4: @ 0x0809F3D4
	push {r4, lr}
	adds r4, r0, #0
	bl sub_802EBCC
	adds r1, r4, #0
	movs r2, #0xc8
	bl WriteAndVerifySramFast
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

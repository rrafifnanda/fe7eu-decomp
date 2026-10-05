	.syntax unified
	.thumb
	.global sub_8047E0C
	.thumb_func
sub_8047E0C: @ 0x08047E0C
	push {lr}
	adds r1, r0, #0
	movs r0, #0x40
	bl sub_8047D80
	pop {r0}
	bx r0
	.align 2, 0

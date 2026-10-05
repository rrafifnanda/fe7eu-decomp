	.syntax unified
	.thumb
	.global sub_8014560
	.thumb_func
sub_8014560: @ 0x08014560
	push {lr}
	adds r1, r0, #0
	movs r0, #4
	bl sub_8014488
	pop {r0}
	bx r0
	.align 2, 0

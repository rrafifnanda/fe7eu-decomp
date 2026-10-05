	.syntax unified
	.thumb
	.global sub_8014540
	.thumb_func
sub_8014540: @ 0x08014540
	push {lr}
	adds r1, r0, #0
	movs r0, #4
	bl sub_8014470
	pop {r0}
	bx r0
	.align 2, 0

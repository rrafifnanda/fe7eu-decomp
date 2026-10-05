	.syntax unified
	.thumb
	.global sub_803157C
	.thumb_func
sub_803157C: @ 0x0803157C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	bl InitBgs
	adds r0, r4, #0
	bl EndAllProcChildren
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

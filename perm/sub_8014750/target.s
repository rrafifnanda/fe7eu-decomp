	.syntax unified
	.thumb
	.global sub_8014750
	.thumb_func
sub_8014750: @ 0x08014750
	push {lr}
	adds r2, r0, #0
	movs r0, #7
	movs r1, #0x10
	movs r3, #0
	bl StartFadeCore
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global sub_80146D4
	.thumb_func
sub_80146D4: @ 0x080146D4
	push {lr}
	adds r2, r0, #0
	movs r0, #2
	movs r1, #8
	movs r3, #0
	bl StartFadeCore
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global sub_8014778
	.thumb_func
sub_8014778: @ 0x08014778
	push {lr}
	adds r2, r0, #0
	movs r0, #4
	movs r1, #4
	movs r3, #0
	bl StartFadeCore
	pop {r0}
	bx r0
	.align 2, 0

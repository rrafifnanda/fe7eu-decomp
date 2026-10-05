	.syntax unified
	.thumb
	.global sub_8014714
	.thumb_func
sub_8014714: @ 0x08014714
	push {lr}
	adds r2, r0, #0
	movs r0, #2
	movs r1, #0x20
	movs r3, #0
	bl StartFadeCore
	pop {r0}
	bx r0
	.align 2, 0

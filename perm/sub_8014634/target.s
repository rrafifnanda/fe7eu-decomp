	.syntax unified
	.thumb
	.global sub_8014634
	.thumb_func
sub_8014634: @ 0x08014634
	push {lr}
	adds r2, r0, #0
	movs r0, #0
	movs r1, #0x40
	movs r3, #0
	bl StartFadeCore
	pop {r0}
	bx r0
	.align 2, 0

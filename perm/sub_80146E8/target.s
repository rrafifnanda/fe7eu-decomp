	.syntax unified
	.thumb
	.global sub_80146E8
	.thumb_func
sub_80146E8: @ 0x080146E8
	push {lr}
	adds r2, r0, #0
	movs r0, #2
	movs r1, #8
	movs r3, #0
	bl StartFadeCore
	bl sub_80148C0
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global sub_801478C
	.thumb_func
sub_801478C: @ 0x0801478C
	push {lr}
	adds r2, r0, #0
	movs r0, #4
	movs r1, #8
	movs r3, #0
	bl StartFadeCore
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global sub_801460C
	.thumb_func
sub_801460C: @ 0x0801460C
	push {lr}
	adds r2, r0, #0
	movs r0, #0
	movs r1, #0x10
	movs r3, #0
	bl StartFadeCore
	pop {r0}
	bx r0
	.align 2, 0

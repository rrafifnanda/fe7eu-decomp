	.syntax unified
	.thumb
	.global EndPrepItemScreenFace
	.thumb_func
EndPrepItemScreenFace: @ 0x080932B0
	push {lr}
	sub sp, #4
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0
	bl UpdatePrepItemScreenFace
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0

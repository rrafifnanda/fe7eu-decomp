	.syntax unified
	.thumb
	.global sub_802C03C
	.thumb_func
sub_802C03C: @ 0x0802C03C
	push {lr}
	sub sp, #0xc
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #0
	str r2, [sp, #8]
	movs r2, #6
	movs r3, #0
	bl sub_802BFB4
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global sub_802BFE4
	.thumb_func
sub_802BFE4: @ 0x0802BFE4
	push {lr}
	sub sp, #0xc
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #0xa
	str r2, [sp, #8]
	movs r2, #4
	movs r3, #0
	bl sub_802BFB4
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0

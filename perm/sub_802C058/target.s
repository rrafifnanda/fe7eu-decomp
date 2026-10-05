	.syntax unified
	.thumb
	.global sub_802C058
	.thumb_func
sub_802C058: @ 0x0802C058
	push {lr}
	movs r2, #8
	movs r3, #0
	bl sub_802BF8C
	pop {r0}
	bx r0
	.align 2, 0

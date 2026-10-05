	.syntax unified
	.thumb
	.global sub_802DFB8
	.thumb_func
sub_802DFB8: @ 0x0802DFB8
	push {lr}
	bl sub_802DEC4
	bl sub_802DF54
	pop {r0}
	bx r0
	.align 2, 0

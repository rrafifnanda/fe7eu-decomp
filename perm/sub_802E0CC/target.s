	.syntax unified
	.thumb
	.global sub_802E0CC
	.thumb_func
sub_802E0CC: @ 0x0802E0CC
	push {lr}
	bl sub_802DFC8
	bl sub_802E034
	pop {r0}
	bx r0
	.align 2, 0

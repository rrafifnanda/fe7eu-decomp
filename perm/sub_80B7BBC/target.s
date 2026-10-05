	.syntax unified
	.thumb
	.global sub_80B7BBC
	.thumb_func
sub_80B7BBC: @ 0x080B7BBC
	push {lr}
	bl sub_80B7A74
	bl sub_80B7B4C
	pop {r0}
	bx r0
	.align 2, 0

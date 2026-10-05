	.syntax unified
	.thumb
	.global sub_807A740
	.thumb_func
sub_807A740: @ 0x0807A740
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetUnitFromCharId
	bl sub_807A6D8
	pop {r0}
	bx r0
	.align 2, 0

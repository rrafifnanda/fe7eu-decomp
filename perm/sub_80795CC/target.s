	.syntax unified
	.thumb
	.global sub_80795CC
	.thumb_func
sub_80795CC: @ 0x080795CC
	push {lr}
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl sub_80793E4
	pop {r0}
	bx r0
	.align 2, 0

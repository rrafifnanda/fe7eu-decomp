	.syntax unified
	.thumb
	.global sub_8055CCC
	.thumb_func
sub_8055CCC: @ 0x08055CCC
	ldr r1, _08055CD4 @ =0x0203E0C8
	str r0, [r1]
	bx lr
	.align 2, 0
_08055CD4: .4byte 0x0203E0C8

	.syntax unified
	.thumb
	.global sub_802B908
	.thumb_func
sub_802B908: @ 0x0802B908
	push {lr}
	movs r0, #0
	bl EndFaceById
	movs r0, #1
	bl EndFaceById
	pop {r0}
	bx r0
	.align 2, 0

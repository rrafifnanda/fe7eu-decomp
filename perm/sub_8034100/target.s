	.syntax unified
	.thumb
	.global sub_8034100
	.thumb_func
sub_8034100: @ 0x08034100
	push {lr}
	movs r0, #1
	rsbs r0, r0, #0
	bl UnpackUiWindowFrameGraphics2
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global DoM4aSongNumStop
	.thumb_func
DoM4aSongNumStop: @ 0x08067E68
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStop
	pop {r0}
	bx r0
	.align 2, 0

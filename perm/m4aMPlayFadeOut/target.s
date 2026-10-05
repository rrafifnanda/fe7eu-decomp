	.syntax unified
	.thumb
	.global m4aMPlayFadeOut
	.thumb_func
m4aMPlayFadeOut: @ 0x080BF270
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl MPlayFadeOut
	pop {r0}
	bx r0
	.align 2, 0

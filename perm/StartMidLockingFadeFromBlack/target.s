	.syntax unified
	.thumb
	.global StartMidLockingFadeFromBlack
	.thumb_func
StartMidLockingFadeFromBlack: @ 0x08014500
	push {lr}
	adds r1, r0, #0
	movs r0, #0x10
	bl StartLockingFadeFromBlack
	pop {r0}
	bx r0
	.align 2, 0

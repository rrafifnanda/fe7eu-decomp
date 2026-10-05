	.syntax unified
	.thumb
	.global StartFastLockingFadeFromBlack
	.thumb_func
StartFastLockingFadeFromBlack: @ 0x08014520
	push {lr}
	adds r1, r0, #0
	movs r0, #0x40
	bl StartLockingFadeFromBlack
	pop {r0}
	bx r0
	.align 2, 0

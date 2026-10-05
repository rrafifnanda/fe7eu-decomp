	.syntax unified
	.thumb
	.global PopulateSaveBlockChecksum
	.thumb_func
PopulateSaveBlockChecksum: @ 0x080A2350
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r5, [r4, #0xa]
	ldrh r0, [r4, #8]
	bl SramOffsetToAddr
	adds r1, r5, #0
	bl SramChecksum32
	str r0, [r4, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

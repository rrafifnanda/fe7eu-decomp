	.syntax unified
	.thumb
	.global sub_8013B4C
	.thumb_func
sub_8013B4C: @ 0x08013B4C
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	bl SetPalFadeStClkEnd1
	adds r0, r4, #0
	bl SetPalFadeStClkEnd2
	adds r0, r5, #0
	bl SetPalFadeStClkEnd3
	pop {r4, r5}
	pop {r0}
	bx r0

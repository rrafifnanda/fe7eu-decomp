	.syntax unified
	.thumb
	.global sub_80BCACC
	.thumb_func
sub_80BCACC: @ 0x080BCACC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x2c]
	lsls r4, r0, #3
	movs r1, #0x80
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r0, #1
	str r0, [r5, #0x2c]
	adds r0, r4, #0
	adds r1, r4, #0
	adds r2, r4, #0
	movs r3, #1
	bl WriteFadedPaletteFromArchive
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r4, r0
	bne _080BCAF8
	adds r0, r5, #0
	bl Proc_Break
_080BCAF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

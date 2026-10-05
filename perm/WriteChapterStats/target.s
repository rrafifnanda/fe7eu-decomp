	.syntax unified
	.thumb
	.global WriteChapterStats
	.thumb_func
WriteChapterStats: @ 0x080A04DC
	push {lr}
	adds r1, r0, #0
	ldr r0, _080A04EC @ =0x0203EBD8
	movs r2, #0xc0
	bl WriteAndVerifySramFast
	pop {r0}
	bx r0
	.align 2, 0
_080A04EC: .4byte 0x0203EBD8

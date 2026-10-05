	.syntax unified
	.thumb
	.global WritePidStats
	.thumb_func
WritePidStats: @ 0x080A04B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A04D4 @ =0x0203E778
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r1, r4, #0
	bl WriteAndVerifySramFast
	ldr r0, _080A04D8 @ =0x0203E774
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A04D4: .4byte 0x0203E778
_080A04D8: .4byte 0x0203E774

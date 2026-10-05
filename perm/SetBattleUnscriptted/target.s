	.syntax unified
	.thumb
	.global SetBattleUnscriptted
	.thumb_func
SetBattleUnscriptted: @ 0x08053C1C
	ldr r1, _08053C24 @ =0x0203E0C4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08053C24: .4byte 0x0203E0C4

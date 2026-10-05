	.syntax unified
	.thumb
	.global PutNumberOrBlank
	.thumb_func
PutNumberOrBlank: @ 0x08006074
	push {lr}
	cmp r2, #0
	blt _0800607E
	cmp r2, #0xff
	bne _0800608A
_0800607E:
	subs r0, #2
	movs r2, #0x14
	movs r3, #0x14
	bl PutTwoSpecialChar
	b _0800608E
_0800608A:
	bl PutNumber
_0800608E:
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global sub_80141D4
	.thumb_func
sub_80141D4: @ 0x080141D4
	push {r4, lr}
	movs r4, #0
_080141D8:
	adds r0, r4, #0
	bl SetBlackPal
	adds r4, #1
	cmp r4, #0x1f
	ble _080141D8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global AddMapChangeTrap
	.thumb_func
AddMapChangeTrap: @ 0x0802C294
	push {lr}
	adds r3, r0, #0
	movs r0, #0
	movs r1, #0
	movs r2, #3
	bl sub_802BF8C
	pop {r0}
	bx r0
	.align 2, 0

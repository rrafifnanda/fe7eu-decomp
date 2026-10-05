	.syntax unified
	.thumb
	.global NewEfxRestWINH_
	.thumb_func
NewEfxRestWINH_: @ 0x080565FC
	push {lr}
	adds r3, r2, #0
	movs r2, #0
	bl NewEfxRestWINH
	pop {r0}
	bx r0
	.align 2, 0

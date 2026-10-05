	.syntax unified
	.thumb
	.global sub_806B88C
	.thumb_func
sub_806B88C: @ 0x0806B88C
	push {lr}
	movs r0, #0xdf
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
	pop {r0}
	bx r0
	.align 2, 0

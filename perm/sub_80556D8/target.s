	.syntax unified
	.thumb
	.global sub_80556D8
	.thumb_func
sub_80556D8: @ 0x080556D8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x14]
	bl AnimDelete
	ldr r0, [r4, #0x18]
	bl AnimDelete
	movs r0, #0
	str r0, [r4, #0x14]
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x34]
	bl Proc_End
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global sub_80647F8
	.thumb_func
sub_80647F8: @ 0x080647F8
	push {r4, lr}
	ldr r4, _08064810 @ =0x0203E0D0
	ldr r0, [r4]
	cmp r0, #0
	beq _0806480A
	bl Proc_End
	movs r0, #0
	str r0, [r4]
_0806480A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08064810: .4byte 0x0203E0D0

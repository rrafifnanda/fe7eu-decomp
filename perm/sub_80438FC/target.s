	.syntax unified
	.thumb
	.global sub_80438FC
	.thumb_func
sub_80438FC: @ 0x080438FC
	push {r4, lr}
	adds r4, r0, #0
	bl GetTalkChoiceResult
	cmp r0, #1
	beq _08043910
	adds r0, r4, #0
	movs r1, #1
	bl sub_800D384
_08043910:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

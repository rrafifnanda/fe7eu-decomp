	.syntax unified
	.thumb
	.global sub_8021A8C
	.thumb_func
sub_8021A8C: @ 0x08021A8C
	push {r4, lr}
	adds r4, r0, #0
	bl GetTalkChoiceResult
	cmp r0, #1
	beq _08021AA0
	adds r0, r4, #0
	movs r1, #0x63
	bl sub_800D384
_08021AA0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

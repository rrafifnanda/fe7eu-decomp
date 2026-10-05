	.syntax unified
	.thumb
	.global sub_800ACE8
	.thumb_func
sub_800ACE8: @ 0x0800ACE8
	push {r4, r5, lr}
	sub sp, #8
	movs r5, #0x90
	lsls r5, r5, #2
	movs r4, #4
	str r4, [sp]
	str r3, [sp, #4]
	adds r3, r5, #0
	bl sub_800AD04
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1

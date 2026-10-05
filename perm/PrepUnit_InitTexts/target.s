	.syntax unified
	.thumb
	.global PrepUnit_InitTexts
	.thumb_func
PrepUnit_InitTexts: @ 0x08093AB4
	push {r4, r5, lr}
	bl ResetText
	ldr r5, _08093B08 @ =gPrepUnitTexts
	movs r4, #0xd
_08093ABE:
	adds r0, r5, #0
	movs r1, #5
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge _08093ABE
	ldr r5, _08093B0C @ =gPrepUnitTexts + 14 * 8
	movs r4, #4
_08093AD2:
	adds r0, r5, #0
	movs r1, #7
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge _08093AD2
	ldr r4, _08093B10 @ =gPrepUnitTexts + 19 * 8
	adds r0, r4, #0
	movs r1, #7
	bl InitText
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0xa
	bl InitText
	adds r4, #0x10
	adds r0, r4, #0
	movs r1, #0xb
	bl InitText
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093B08: .4byte gPrepUnitTexts
_08093B0C: .4byte gPrepUnitTexts + 14 * 8
_08093B10: .4byte gPrepUnitTexts + 19 * 8

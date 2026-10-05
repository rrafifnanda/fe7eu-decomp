	.syntax unified
	.thumb
	.global sub_8036BC8
	.thumb_func
sub_8036BC8: @ 0x08036BC8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl GetUnitPower
	cmp r0, #0x14
	bgt _08036BDE
	adds r0, r4, #0
	bl GetUnitPower
	adds r7, r0, #0
	b _08036BE0
_08036BDE:
	movs r7, #0x14
_08036BE0:
	adds r0, r4, #0
	bl RevertMapChange
	ldr r0, _08036C3C @ =0x0202E3E4
	ldr r0, [r0]
	movs r1, #0
	bl BmMapFillg
	ldr r0, _08036C40 @ =gBmMapSize
	movs r1, #2
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _08036C34
_08036BFC:
	ldr r0, _08036C40 @ =gBmMapSize
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r4, r0, #1
	subs r6, r5, #1
	cmp r4, #0
	blt _08036C2E
_08036C0A:
	ldr r0, _08036C44 @ =gBmMapMovement
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x78
	bhi _08036C28
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	movs r3, #1
	bl sub_801A6B4
_08036C28:
	subs r4, #1
	cmp r4, #0
	bge _08036C0A
_08036C2E:
	adds r5, r6, #0
	cmp r5, #0
	bge _08036BFC
_08036C34:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036C3C: .4byte 0x0202E3E4
_08036C40: .4byte gBmMapSize
_08036C44: .4byte gBmMapMovement

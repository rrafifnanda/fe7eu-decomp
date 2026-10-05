	.syntax unified
	.thumb
	.global sub_80455BC
	.thumb_func
sub_80455BC: @ 0x080455BC
	push {r4, lr}
	ldr r0, _08045614 @ =gBmMapUnit
	ldr r0, [r0]
	movs r1, #0
	bl BmMapFillg
	ldr r0, _08045618 @ =0x0202E3E8
	ldr r0, [r0]
	movs r1, #1
	bl BmMapFillg
	movs r4, #1
_080455D4:
	adds r0, r4, #0
	bl GetUnit
	adds r2, r0, #0
	cmp r2, #0
	beq _08045608
	ldr r0, [r2]
	cmp r0, #0
	beq _08045608
	ldr r0, [r2, #0xc]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08045608
	movs r1, #0x11
	ldrsb r1, [r2, r1]
	ldr r0, _08045614 @ =gBmMapUnit
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r2, [r2, #0x10]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	ldr r0, [r1]
	adds r0, r0, r2
	strb r4, [r0]
_08045608:
	adds r4, #1
	cmp r4, #0xc5
	ble _080455D4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08045614: .4byte gBmMapUnit
_08045618: .4byte 0x0202E3E8

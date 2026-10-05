	.syntax unified
	.thumb
	.global sub_8053438
	.thumb_func
sub_8053438: @ 0x08053438
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, r2, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIndex
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0805345E
	movs r0, #0
	strh r0, [r4]
_0805345E:
	ldr r0, _08053480 @ =gEkrInitialHitSide
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r5
	beq _08053478
	cmp r2, #0x53
	blt _08053478
	cmp r2, #0x55
	ble _08053474
	cmp r2, #0x57
	bne _08053478
_08053474:
	movs r0, #0
	strh r0, [r4]
_08053478:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08053480: .4byte gEkrInitialHitSide

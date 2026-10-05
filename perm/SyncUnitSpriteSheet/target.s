	.syntax unified
	.thumb
	.global SyncUnitSpriteSheet
	.thumb_func
SyncUnitSpriteSheet: @ 0x080259A4
	push {r4, r5, lr}
	bl GetGameTime
	movs r1, #0x48
	bl __umodsi3
	adds r4, r0, #0
	adds r5, r4, #0
	cmp r4, #0
	bne _080259C4
	ldr r0, _080259FC @ =0x02033F10
	ldr r1, _08025A00 @ =0x06011000
	movs r2, #0x80
	lsls r2, r2, #4
	bl CpuFastSet
_080259C4:
	cmp r4, #0x20
	bne _080259D4
	ldr r0, _08025A04 @ =0x02035F10
	ldr r1, _08025A00 @ =0x06011000
	movs r2, #0x80
	lsls r2, r2, #4
	bl CpuFastSet
_080259D4:
	cmp r4, #0x24
	bne _080259E4
	ldr r0, _08025A08 @ =0x02037F10
	ldr r1, _08025A00 @ =0x06011000
	movs r2, #0x80
	lsls r2, r2, #4
	bl CpuFastSet
_080259E4:
	cmp r5, #0x44
	bne _080259F4
	ldr r0, _08025A04 @ =0x02035F10
	ldr r1, _08025A00 @ =0x06011000
	movs r2, #0x80
	lsls r2, r2, #4
	bl CpuFastSet
_080259F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080259FC: .4byte 0x02033F10
_08025A00: .4byte 0x06011000
_08025A04: .4byte 0x02035F10
_08025A08: .4byte 0x02037F10

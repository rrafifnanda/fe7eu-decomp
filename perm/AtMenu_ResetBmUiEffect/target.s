	.syntax unified
	.thumb
	.global AtMenu_ResetBmUiEffect
	.thumb_func
AtMenu_ResetBmUiEffect: @ 0x0808F670
	push {r4, lr}
	adds r4, r0, #0
	bl ReorderPlayerUnitsBasedOnDeployment
	adds r4, #0x36
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808F686
	bl EndPrepScreen
	b _0808F694
_0808F686:
	bl CheckInLinkArena
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808F694
	bl sub_803DED4
_0808F694:
	bl sub_800F070
	bl ResetUnitSprites
	bl RefreshEntityMaps
	bl RefreshUnitSprites
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

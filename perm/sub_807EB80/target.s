	.syntax unified
	.thumb
	.global sub_807EB80
	.thumb_func
sub_807EB80: @ 0x0807EB80
	push {lr}
	bl sub_800EFD4
	bl sub_800F070
	bl RefreshEntityMaps
	bl RefreshUnitSprites
	bl RenderMap
	pop {r0}
	bx r0
	.align 2, 0

	.syntax unified
	.thumb
	.global sub_80438E0
	.thumb_func
sub_80438E0: @ 0x080438E0
	push {lr}
	bl sub_803E080
	bl sub_8040D1C
	bl sub_8040D40
	bl sub_803C8C8
	bl LoadAndVerfySuspendSave
	pop {r0}
	bx r0
	.align 2, 0

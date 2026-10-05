	.syntax unified
	.thumb
	.global PutBuildInfo
	.thumb_func
PutBuildInfo: @ 0x08000AF4
	sub sp, #0x10
	push {r4, lr}
	add r4, sp, #0x18
	str r4, [sp, #0xc]
	mov r4, pc
	str r4, [sp, #0x14]
	mov r4, fp
	str r4, [sp, #8]
	mov r4, lr
	str r4, [sp, #0x10]
	add r4, sp, #0x14
	mov fp, r4
	adds r4, r0, #0
	ldr r1, _08000B28 @ =gUnk_080C0C50
	bl sub_8004E4C
	subs r4, #0x40
	ldr r1, _08000B2C @ =gUnk_080C0C6C
	adds r0, r4, #0
	bl sub_8004E4C
	pop {r4}
	pop {r0, r1, r2}
	mov fp, r1
	mov sp, r2
	bx r0
	.align 2, 0
_08000B28: .4byte gUnk_080C0C50
_08000B2C: .4byte gUnk_080C0C6C

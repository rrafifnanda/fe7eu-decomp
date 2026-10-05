	.syntax unified
	.thumb
	.global PutNumberExt
	.thumb_func
PutNumberExt: @ 0x08006028
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	adds r6, r3, #0
	cmp r4, #0
	bne _0800603E
	adds r2, r6, #0
	bl PutSpecialChar
	b _08006062
_0800603E:
	adds r0, r4, #0
	movs r1, #0xa
	bl __modsi3
	adds r2, r0, #0
	adds r2, r2, r6
	adds r0, r5, #0
	adds r1, r7, #0
	bl PutSpecialChar
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	adds r4, r0, #0
	subs r5, #2
	cmp r4, #0
	bne _0800603E
_08006062:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

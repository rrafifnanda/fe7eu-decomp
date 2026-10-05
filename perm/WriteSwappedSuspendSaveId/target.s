	.syntax unified
	.thumb
	.global WriteSwappedSuspendSaveId
	.thumb_func
WriteSwappedSuspendSaveId: @ 0x080A22DC
	push {lr}
	sub sp, #0x64
	mov r0, sp
	bl ReadGlobalSaveInfo
	movs r2, #0
	mov r1, sp
	adds r1, #0x63
	ldrb r0, [r1]
	cmp r0, #0
	bne _080A22F4
	movs r2, #1
_080A22F4:
	strb r2, [r1]
	mov r0, sp
	bl WriteGlobalSaveInfoNoChecksum
	add sp, #0x64
	pop {r0}
	bx r0
	.align 2, 0

;/*
; * FreeRTOS Kernel V10.4.3
; * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
; *
; * Permission is hereby granted, free of charge, to any person obtaining a copy of
; * this software and associated documentation files (the "Software"), to deal in
; * the Software without restriction, including without limitation the rights to
; * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
; * the Software, and to permit persons to whom the Software is furnished to do so,
; * subject to the following conditions:
; *
; * The above copyright notice and this permission notice shall be included in all
; * copies or substantial portions of the Software.
; *
; * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
; * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
; * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
; * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
; * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
; *
; * https://www.FreeRTOS.org
; * https://github.com/FreeRTOS
; *
; * 1 tab == 4 spaces!
; */

;$include "FreeRTOSConfig.h"
$include "ISR_Support.h"

	.PUBLIC    _vPortYield
	.PUBLIC    _vPortStartFirstTask
	.PUBLIC    _vPortTickISR

	.EXTERN    _vTaskSwitchContext
	.EXTERN    _xTaskIncrementTick

	.extern    _Clear_ITLSFlag

;/* FreeRTOS yield handler.  This is installed as the BRK software interrupt handler. */
	.SECTION .text,TEXT
_vPortYield:
;	/* Save the context of the current task. */
	portSAVE_CONTEXT
;	/* Start multiple interrupts (allow only priority level 0) */
;	clr1 psw.1
;	set1 psw.2
;	ei
;	/* Call the scheduler to select the next task. */
	call      !!_vTaskSwitchContext
;	/* Stop multiple interrupts (priority level set to default) */
;	di
;	set1 psw.1
;	set1 psw.2
;	/* Restore the context of the next task to run. */
	portRESTORE_CONTEXT
	retb


;/* Starts the scheduler by restoring the context of the task that will execute first. */
	.SECTION .text,TEXT
_vPortStartFirstTask:
;	/* Restore the context of whichever task will execute first. */
	portRESTORE_CONTEXT
;	/* An interrupt stack frame is used so the task is started using RETI. */
	reti

;/* FreeRTOS tick handler.  This is installed as the interval timer interrupt handler. */
	.SECTION .text,TEXT
_vPortTickISR:
;	/* Clear the status flag of the interval timer */
	push AX
	mov a, #0xFE
	and a, !0x036B
	mov !0x036B, a
	pop  AX
;	/* Save the context of the currently executing task. */
	portSAVE_CONTEXT
;	/* Start multiple interrupts (allow only priority level 0) */
;	clr1 psw.1
;	set1 psw.2
;	ei
;	/* Call the RTOS tick function. */
	call      !!_xTaskIncrementTick
	cmpw	ax, #0x00
	skz
	call      !!_vTaskSwitchContext
;	/* Stop multiple interrupts (priority level set to default) */
;	di
;	set1 psw.1
;	set1 psw.2
;	/* Retore the context of whichever task will run next. */
	portRESTORE_CONTEXT
	reti

;/* Install the interrupt handlers */

;	/* 32bit interval timer */
	_vPortTickISR	.VECTOR	0x38

;	/* brk */
	_vPortYield		.VECTOR 0x7E


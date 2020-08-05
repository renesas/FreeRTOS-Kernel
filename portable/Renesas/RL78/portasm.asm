;/*
; * FreeRTOS Kernel V10.2.1
; * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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
; * http://www.FreeRTOS.org
; * http://aws.amazon.com/freertos
; *
; * 1 tab == 4 spaces!
; */

$include "ISR_Support.h"

;;	CS    .SET                  0xFFFFC
;;	ES    .SET                  0xFFFFD

	.PUBLIC    _vPortYield
	.PUBLIC    _vPortStartFirstTask
	.PUBLIC    _vPortTickISR
;;	.PUBLIC    _vPortFreeRTOSInterruptCommonHandler_C

	.EXTERN    _vTaskSwitchContext
	.EXTERN    _xTaskIncrementTick

; FreeRTOS yield handler.  This is installed as the BRK software interrupt
; handler.
	.SECTION .text,TEXT
_vPortYield:
	portSAVE_CONTEXT		        ; Save the context of the current task.
	call@      _vTaskSwitchContext  ; Call the scheduler to select the next task.
	portRESTORE_CONTEXT		        ; Restore the context of the next task to run.
	retb


; Starts the scheduler by restoring the context of the task that will execute
; first.
	.SECTION .text,TEXT
_vPortStartFirstTask:
	portRESTORE_CONTEXT	            ; Restore the context of whichever task the ...
	reti					        ; An interrupt stack frame is used so the task
                                    ; is started using a RETI instruction.

; FreeRTOS tick handler.  This is installed as the interval timer interrupt
; handler.
	.SECTION .text,TEXT
_vPortTickISR:
	portSAVE_CONTEXT		       ; Save the context of the current task.
	call@	_xTaskIncrementTick    ; Call the timer tick function.
	cmpw	ax, #0x00
	skz
	call@	_vTaskSwitchContext    ; Call the scheduler to select the next task.
	portRESTORE_CONTEXT		       ; Restore the context of the next task to run.
	reti


; Common interrupt handler.
;;	.SECTION .text,TEXT
;;_vPortFreeRTOSInterruptCommonHandler_C:
	; Argument: BC is the target interrupt handler address.
;;	portSAVE_CONTEXT_C		       ; Save the context of the current task.
;;	clrb	a
;;	mov		cs, a
;;	call	bc					   ; Call the target interrupt handler.
;;	portRESTORE_CONTEXT		       ; Restore the context of the next task to run.
;;	reti


; Install the interrupt handlers

	_vPortTickISR    .VECTOR    0x38
;;	_vPortTickISR    .VECTOR    0x3C

	_vPortYield      .VECTOR    0x7E


; Somehow CS+ debugger needs more lines at least this file >= ISR_Support.h.





































; Here.

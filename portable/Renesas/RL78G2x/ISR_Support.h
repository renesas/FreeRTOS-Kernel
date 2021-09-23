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

;/* Variables used by scheduler */
    .EXTERN    _pxCurrentTCB
    .EXTERN    _usCriticalNesting

;/*
; * portSAVE_CONTEXT MACRO
; * Saves the context of the general purpose registers, CS and ES (only in far
; * memory mode) registers the usCriticalNesting Value and the Stack Pointer
; * of the active Task onto the task stack
; */
portSAVE_CONTEXT .MACRO
;   /* Save AX Register to stack. */
    PUSH    AX
    PUSH    HL
;   /* Save CS register. */
    MOV     A, CS
    XCH     A, X
;   /* Save ES register. */
    MOV     A, ES
    PUSH    AX
;   /* Save the remaining general purpose registers from bank 0. */
    PUSH    DE
    PUSH    BC
;   /* Save the usCriticalNesting value. */
    MOVW    AX, !_usCriticalNesting
    PUSH    AX
;   /* Save the Stack pointer. */
    MOVW    AX, !_pxCurrentTCB
    MOVW    HL, AX
    MOVW    AX, SP
    MOVW    [HL], AX
;   /* Switch stack pointers. */
;   MOVW    SP, #LOWW(__STACK_ADDR_START)

    .ENDM


;/*
; * portRESTORE_CONTEXT MACRO
; * Restores the task Stack Pointer then use this to restore usCriticalNesting,
; * general purpose registers and the CS and ES (only in far memory mode)
; * of the selected task from the task stack
; */
portRESTORE_CONTEXT .MACRO
;   /* Restore the Stack pointer. */
    MOVW    AX, !_pxCurrentTCB
    MOVW    HL, AX
    MOVW    AX, [HL]
    MOVW	SP, AX
;   /* Restore usCriticalNesting value. */
    POP     AX
    MOVW    !_usCriticalNesting, AX
;   /* Restore the necessary general purpose registers. */
    POP     BC
    POP     DE
;   /* Restore the ES register. */
    POP     AX
    MOV     ES, A
;   /* Restore the CS register. */
    XCH     A, X
    MOV     CS, A
;   /* Restore general purpose register HL. */
    POP     HL
;   /* Restore AX. */
    POP     AX

    .ENDM


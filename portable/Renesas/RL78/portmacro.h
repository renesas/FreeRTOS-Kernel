/*
 * FreeRTOS Kernel V11.1.0
 * Copyright (C) 2024 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 * 1 tab == 4 spaces!
 */

#ifndef PORTMACRO_H
#define PORTMACRO_H

/*-----------------------------------------------------------
 * Port specific definitions.
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions - these are a bit legacy and not really used now */
#define portCHAR                 char
#define portFLOAT                float
#define portDOUBLE               double
#define portLONG                 long
#define portSHORT                short
#define portSTACK_TYPE           uint16_t
#define portBASE_TYPE            short

#define portSTACK_GROWTH         ( -1 )
#define portBYTE_ALIGNMENT       2
#define portPOINTER_SIZE_TYPE    uint16_t
typedef portSTACK_TYPE   StackType_t;
typedef short               BaseType_t;
typedef unsigned short   UBaseType_t;

#if ( configTICK_TYPE_WIDTH_IN_BITS == TICK_TYPE_WIDTH_16_BITS )
    typedef uint16_t     TickType_t;
    #define portMAX_DELAY    ( TickType_t ) 0xffff
#elif ( configTICK_TYPE_WIDTH_IN_BITS == TICK_TYPE_WIDTH_32_BITS )
    typedef uint32_t     TickType_t;
    #define portMAX_DELAY    ( TickType_t ) 0xffffffffUL
#elif ( configTICK_TYPE_WIDTH_IN_BITS == TICK_TYPE_WIDTH_64_BITS )
    typedef uint64_t     TickType_t;
    #define portMAX_DELAY    ( TickType_t ) 0xffffffffffffffffU
#else
    #error configTICK_TYPE_WIDTH_IN_BITS set to unsupported tick type width.
#endif
/*-----------------------------------------------------------*/

/* Disable the interrupts */
#define portDISABLE_INTERRUPTS()    __DI()

/* Enable the interrupts */
#define portENABLE_INTERRUPTS()     __EI()

/* preserve current interrupt state and then disable interrupts */
#define portENTER_CRITICAL()    do {                                                \
    extern volatile uint16_t usCriticalNesting;                                     \
                                                                                    \
        portDISABLE_INTERRUPTS();                                                   \
                                                                                    \
        /* Now interrupts are disabled ulCriticalNesting can be accessed */         \
        /* directly.  Increment ulCriticalNesting to keep a count of how many */    \
        /* times portENTER_CRITICAL() has been called. */                           \
        usCriticalNesting++;                                                        \
    } while( 0 )

/* restore previously preserved interrupt state */
#define portEXIT_CRITICAL()     do {                                                \
        extern volatile uint16_t usCriticalNesting;                                 \
        if( usCriticalNesting > portNO_CRITICAL_SECTION_NESTING )                   \
        {                                                                           \
            /* Decrement the nesting count as we are leaving a critical section. */ \
            usCriticalNesting--;                                                    \
            /* If the nesting level has reached zero then interrupts should be */   \
            /* re-enabled. */                                                       \
            if( usCriticalNesting == portNO_CRITICAL_SECTION_NESTING )              \
            {                                                                       \
                portENABLE_INTERRUPTS();                                            \
            }                                                                       \
        }                                                                            \
    } while( 0 )

/* Task utilities. */
#define portYIELD()                                           __brk()
#define portYIELD_FROM_ISR( xHigherPriorityTaskWoken ) if( xHigherPriorityTaskWoken ) vTaskSwitchContext()
#define portNOP()                                             __nop()

/* Task function macros as described on the FreeRTOS.org WEB site. */
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters )    void vFunction( void * pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters )          void vFunction( void * pvParameters )

/* Critical section control macros. */
#define portNO_CRITICAL_SECTION_NESTING        ( ( uint16_t ) 0 )

/* Hardwware specifics. */
#define portTICK_PERIOD_MS    ( ( TickType_t ) 1000 / configTICK_RATE_HZ )

#endif /* PORTMACRO_H */

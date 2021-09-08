/*
 * FreeRTOS Kernel V10.4.3
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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

/* Board Support includes */
#include "r_smc_entry.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* The critical nesting value is initialised to a non zero value to ensure
 interrupts don't accidentally become enabled before the scheduler is started. */
#define portINITIAL_CRITICAL_NESTING  ( ( uint16_t ) 10 )

/* Initial PSW value allocated to a newly created task.
 *   11000110
 *   ||||||||-------------- Fill byte
 *   |||||||--------------- Carry Flag cleared
 *   |||||----------------- In-service priority Flags set to low level
 *   ||||------------------ Register bank Select 0 Flag cleared
 *   |||------------------- Auxiliary Carry Flag cleared
 *   ||-------------------- Register bank Select 1 Flag cleared
 *   |--------------------- Zero Flag set
 *   ---------------------- Global Interrupt Flag set (enabled)
 */
#define portPSW		  ( 0xc6UL )

/* Each task maintains a count of the critical section nesting depth.  Each time
 a critical section is entered the count is incremented.  Each time a critical
 section is exited the count is decremented - with interrupts only being
 re-enabled if the count is zero.

 usCriticalNesting will get set to zero when the scheduler starts, but must
 not be initialised to zero as that could cause problems during the startup
 sequence. */
volatile uint16_t usCriticalNesting = portINITIAL_CRITICAL_NESTING;

/*-----------------------------------------------------------*/

/*
 * Sets up the periodic ISR used for the RTOS tick.
 */
extern void vApplicationSetupTimerInterrupt(void);

/*
 * Starts the scheduler by loading the context of the first task to run.
 * (defined in portasm.S).
 */
extern void vPortStartFirstTask(void);

/*
 * Used to catch tasks that attempt to return from their implementing function.
 */
static void prvTaskExitError(void);

/*-----------------------------------------------------------*/

/*
 * Initialise the stack of a task to look exactly as if a call to
 * portSAVE_CONTEXT had been called.
 *
 * See the header file portable.h.
 */
StackType_t* pxPortInitialiseStack(StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters)
{
    uint32_t *pulLocal;

    /* Stack type and pointers to the stack type are both 2 bytes. */

    /* Parameters are passed in on the stack, and written using a 32-bit value
     * hence a space is left for the second two bytes. */
    pxTopOfStack--;

    /* The return address, leaving space for the first two bytes of	the
     * 32-bit value.  See the comments above the prvTaskExitError() prototype
     * at the top of this file. */
    pxTopOfStack--;
    pulLocal = ( uint32_t * ) pxTopOfStack;
    *pulLocal = ( uint32_t ) prvTaskExitError;
    pxTopOfStack--;

    /* The start address / PSW value is also written in as a 32-bit value,
     * so leave a space for the second two bytes. */
    pxTopOfStack--;

    /* Task function start address combined with the PSW. */
    pulLocal = ( uint32_t * ) pxTopOfStack;
    *pulLocal = ( ( ( uint32_t ) pxCode ) | ( portPSW << 24UL ) );
    pxTopOfStack--;

    /* An initial value for the AX register. */
    *pxTopOfStack = ( StackType_t ) pvParameters;
    pxTopOfStack--;

    /* An initial value for the HL register. */
    *pxTopOfStack = ( StackType_t ) 0x2222;
    pxTopOfStack--;

    /* CS and ES registers. */
    *pxTopOfStack = ( StackType_t ) 0x0F00;
    pxTopOfStack--;

    /* The remaining general purpose registers DE and BC */
    *pxTopOfStack = ( StackType_t ) 0xDEDE;
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0xBCBC;
    pxTopOfStack--;

    /* Finally the critical section nesting count is set to zero when the task
     first starts. */
    *pxTopOfStack = ( StackType_t ) portNO_CRITICAL_SECTION_NESTING;

    /* Return a pointer to the top of the stack that has beene generated so it
     can	be stored in the task control block for the task. */
    return pxTopOfStack;
}
/*-----------------------------------------------------------*/

static void prvTaskExitError(void)
{
    /* A function that implements a task must not exit or attempt to return to
     its caller as there is nothing to return to.  If a task wants to exit it
     should instead call vTaskDelete( NULL ).

     Artificially force an assert() to be triggered if configASSERT() is
     defined, then stop here so application writers can catch the error. */
    configASSERT(usCriticalNesting == ~0U);
    portDISABLE_INTERRUPTS();
    for (;;)
        ;
}
/*-----------------------------------------------------------*/

portBASE_TYPE xPortStartScheduler(void)
{
    /* Setup the hardware to generate the tick.  Interrupts are disabled when
     this function is called. */
    vApplicationSetupTimerInterrupt ();

    /* Restore the context of the first task that is going to run. */
    vPortStartFirstTask ();

    /* Execution should not reach here as the tasks are now running! */
    return pdTRUE;
}
/*-----------------------------------------------------------*/

void vPortEndScheduler(void)
{
    /* It is unlikely that the RL78 port will get stopped. */
}
/*-----------------------------------------------------------*/

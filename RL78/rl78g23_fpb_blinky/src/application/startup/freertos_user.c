/*
* Copyright (C) 2025 Renesas Electronics Corporation. All rights reserved.
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
*/
/**********************************************************************************************************************
* File Name    : freertos_user.c
* Description  : Contains user-defined functions.
**********************************************************************************************************************/
/**********************************************************************************************************************
* History      : DD.MM.YYYY Version Description
*              : 22.12.2025 1.00    First Release
**********************************************************************************************************************/

/**********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
**********************************************************************************************************************/
#include <stdio.h>
#include "platform.h"
#include "r_smc_entry.h"
#include "FreeRTOS.h"
#include "task.h"

/**********************************************************************************************************************
Macro definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
Typedef definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
External functions
**********************************************************************************************************************/
extern void main_task (void *pvParameters);

TaskHandle_t main_task_handle;

/**********************************************************************************************************************
Private global variables and functions
**********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: vApplicationSetupTimerInterrupt
 * Description  : Initialize system timer for FreeRTOS with tick interrupt 1ms.
 * Arguments    : None.
 * Return Value : None.
 *********************************************************************************************************************/
void vApplicationSetupTimerInterrupt(void)
{
    /* Start Interval timer */
    R_ITL_Start_Interrupt();
    R_Config_ITL_Start();
} /* End of function vApplicationSetupTimerInterrupt() */
/*-----------------------------------------------------------*/
/**********************************************************************************************************************
 * Function Name: vAssertCalled
 * Description  : This function is used to validate the input parameters.
 * Arguments    : None.
 * Return Value : None.
 *********************************************************************************************************************/
void vAssertCalled(void)
{
    volatile unsigned long ul = 0;

    taskENTER_CRITICAL();
    {
        /* Use the debugger to set ul to a non-zero value in order to step out
        of this function to determine why it was called. */
        while( 0 == ul )
        {
            portNOP();
        }
    }
    taskEXIT_CRITICAL();

} /* End of function vAssertCalled() */
/*-----------------------------------------------------------*/
/**********************************************************************************************************************
 * Function Name : Processing_Before_Start_Kernel
 * Description   : Create a main task, FreeRTOS's objects (e.g. mailbox, task, semaphore, mutex...) if required.
 * Arguments     : None.
 * Return value  : None.
 *********************************************************************************************************************/
void Processing_Before_Start_Kernel(void)
{
    /*
     * task creation
     */
    if (pdPASS != xTaskCreate(main_task, "MAIN_TASK", 512, NULL, configMAX_PRIORITIES - 1, &main_task_handle))
    {
        while(1)
        {
            /* Failed! Task can not be created. */
        }
    }
} /* End of function Processing_Before_Start_Kernel() */
/*-----------------------------------------------------------*/

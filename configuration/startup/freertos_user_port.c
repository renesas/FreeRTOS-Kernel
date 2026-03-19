/*
* Copyright (C) 2026 Renesas Electronics Corporation. All rights reserved.
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
* File Name    : freertos_user_port.c
* Description  : Defines the user-defined functions which depends on the Renesas RX port implementation.
**********************************************************************************************************************/
/**********************************************************************************************************************
* History      : DD.MM.YYYY Version Description
*              : 07.04.2026 1.00    First Release
**********************************************************************************************************************/

/**********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
**********************************************************************************************************************/
#include <stdio.h>
#include "platform.h"
#include "r_smc_entry.h"
#include "FreeRTOS.h"
#include "task.h"

#if (BSP_CFG_RTOS_USED == 1)

/**********************************************************************************************************************
Macro definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
Typedef definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
External functions
**********************************************************************************************************************/
/* Main task. */
extern void main_task(void *pvParameters);

TaskHandle_t main_task_handle;

/**********************************************************************************************************************
Private global variables and functions
**********************************************************************************************************************/

/************* semaphore initialization *****************/

/**********************************************************************************************************************
 * Function Name: vApplicationSetupTimerInterrupt
 * Description  : Initialize system timer for FreeRTOS with tick interrupt 1ms.
 * Arguments    : None.
 * Return Value : None.
 *********************************************************************************************************************/
void vApplicationSetupTimerInterrupt(void)
{
	/* CMT channel 0 is configured as RTOS's system timer. */
#if (BSP_CFG_RTOS_SYSTEM_TIMER == 0)
    /* Protect off. */
    SYSTEM.PRCR.WORD = 0xA502;

    /* Enable compare match timer 0. */
    MSTP( CMT0 ) = 0;

    /* Stop counter. */
    CMT.CMSTR0.BIT.STR0 = 0;

    /* Protect on. */
    SYSTEM.PRCR.WORD = 0xA500;

    /* Enable interrupt on compare match.
     * Divide the PCLK by 8. */
    CMT0.CMCR.WORD = 0x00C0; // CKS=00b,CMIE=1; PCLK/8,Compare match interrupt (CMIn) enabled @60MHz

    /* Set the compare match value. */
    CMT0.CMCOR = ( unsigned short ) ( ( ( configPERIPHERAL_CLOCK_HZ / configTICK_RATE_HZ )) / 8 - 1);

    /* Clear counter. */
    CMT0.CMCNT = 0;

    /* Clear any previously pending interrupts. */
    IR(CMT0, CMI0)  = 0;

    /* Enable the interrupt. */
    IEN(CMT0, CMI0) = 1;

    /* Set its priority to the application defined kernel priority. */
    IPR(CMT0, CMI0) = configKERNEL_INTERRUPT_PRIORITY;

    /* Start the timer 0. */
    CMT.CMSTR0.BIT.STR0 = 1;
#endif /* (BSP_CFG_RTOS_SYSTEM_TIMER == 0) */

    /* CMT channel 1 is configured as RTOS's system timer. */
#if (BSP_CFG_RTOS_SYSTEM_TIMER == 1)
    /* Protect off. */
    SYSTEM.PRCR.WORD = 0xA502;

    /* Enable compare match timer 1. */
    MSTP( CMT1 ) = 0;

    /* Stop counter. */
    CMT.CMSTR0.BIT.STR1 = 0;

    /* Protect on. */
    SYSTEM.PRCR.WORD = 0xA500;

    /* Enable interrupt on compare match.
     * Divide the PCLK by 8. */
    CMT1.CMCR.WORD = 0x00C0; // CKS=00b,CMIE=1; PCLK/8,Compare match interrupt (CMIn) enabled @60MHz

    /* Set the compare match value. */
    CMT1.CMCOR = ( unsigned short ) ( ( ( configPERIPHERAL_CLOCK_HZ / configTICK_RATE_HZ )) / 8 - 1);

    /* Clear counter. */
    CMT1.CMCNT = 0;

    /* Clear any previously pending interrupts. */
    IR(CMT1, CMI1)  = 0;

    /* Enable the interrupt. */
    IEN(CMT1, CMI1) = 1;

    /* Set its priority to the application defined kernel priority. */
    IPR(CMT1, CMI1) = configKERNEL_INTERRUPT_PRIORITY;

    /* Start the timer 1. */
    CMT.CMSTR0.BIT.STR1 = 1;
#endif /* (BSP_CFG_RTOS_SYSTEM_TIMER == 1) */

    /* CMT channel 2 is configured as RTOS's system timer. */
#if (BSP_CFG_RTOS_SYSTEM_TIMER == 2)
    /* Protect off. */
    SYSTEM.PRCR.WORD = 0xA502;

    /* Enable compare match timer 2. */
    MSTP( CMT2 ) = 0;

    /* Stop counter. */
    CMT.CMSTR1.BIT.STR2 = 0;

    /* Protect on. */
    SYSTEM.PRCR.WORD = 0xA500;

    /* Enable interrupt on compare match.
     * Divide the PCLK by 8. */
    CMT2.CMCR.WORD = 0x00C0; // CKS=00b,CMIE=1; PCLK/8,Compare match interrupt (CMIn) enabled @60MHz

    /* Set the compare match value. */
    CMT2.CMCOR = ( unsigned short ) ( ( ( configPERIPHERAL_CLOCK_HZ / configTICK_RATE_HZ )) / 8 - 1);

    /* Clear counter. */
    CMT2.CMCNT = 0;

    /* Clear any previously pending interrupts. */
    IR(CMT2, CMI2)  = 0;

    /* Enable the interrupt. */
    IEN(CMT2, CMI2) = 1;

    /* Set its priority to the application defined kernel priority. */
    IPR(CMT2, CMI2) = configKERNEL_INTERRUPT_PRIORITY;

    /* Start the timer 2. */
    CMT.CMSTR1.BIT.STR2 = 1;
#endif /* (BSP_CFG_RTOS_SYSTEM_TIMER == 2) */

    /* CMT channel 3 is configured as RTOS's system timer. */
#if (BSP_CFG_RTOS_SYSTEM_TIMER == 3)
    /* Protect off. */
    SYSTEM.PRCR.WORD = 0xA502;

    /* Enable compare match timer 3. */
    MSTP( CMT3 ) = 0;

    /* Stop counter. */
    CMT.CMSTR1.BIT.STR3 = 0;

    /* Protect on. */
    SYSTEM.PRCR.WORD = 0xA500;

    /* Enable interrupt on compare match.
     * Divide the PCLK by 8. */
    CMT3.CMCR.WORD = 0x00C0; // CKS=00b,CMIE=1; PCLK/8,Compare match interrupt (CMIn) enabled @60MHz

    /* Set the compare match value. */
    CMT3.CMCOR = ( unsigned short ) ( ( ( configPERIPHERAL_CLOCK_HZ / configTICK_RATE_HZ )) / 8 - 1);

    /* Clear counter. */
    CMT3.CMCNT = 0;

    /* Clear any previously pending interrupts. */
    IR(CMT3, CMI3)  = 0;

    /* Enable the interrupt. */
    IEN(CMT3, CMI3) = 1;

    /* Set its priority to the application defined kernel priority. */
    IPR(CMT3, CMI3) = configKERNEL_INTERRUPT_PRIORITY;

    /* Start the timer 3. */
    CMT.CMSTR1.BIT.STR3 = 1;
#endif /* (BSP_CFG_RTOS_SYSTEM_TIMER == 3) */

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
    BaseType_t ret;

    /************** semaphore creation ***********************/



    /************** mutex creation ***************************/


    /************** queues creation **************************/


    /************** event groups creation ********************/


    /************** mailbox creation *************************/


    /************** memory pool creation *********************/

    Kernel_Object_init();

    /************** task creation ****************************/
    /* Main task. */
    ret = xTaskCreate(main_task, "MAIN_TASK", 512, NULL, 3, NULL);
    if (pdPASS != ret)
    {
        while(1)
        {
            /* Failed! Task can not be created. */
        }
    }

} /* End of function Processing_Before_Start_Kernel() */

#endif /* (BSP_CFG_RTOS_USED == 1) */

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
* File Name    : freertos_helper.c
* Description  : Defines the user-defined functions which depends on the common FreeRTOS kernel specification.
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

/**********************************************************************************************************************
Private global variables and functions
**********************************************************************************************************************/
/************* semaphore initialization *****************/

#if ( configUSE_IDLE_HOOK == 1 )
/**********************************************************************************************************************
 * Function Name: vApplicationIdleHook
 * Description  : This function will be called on each cycle of the idle task.
 *                NOTE: vApplicationIdleHook() MUST NOT CALL A FUNCTION
 *                      THAT MIGHT BLOCK UNDER ANY CIRCUMSTANCES.
 * Arguments    : None.
 * Return Value : None.
 *********************************************************************************************************************/
void vApplicationIdleHook(void)
{
    /* Implement user-code for user own purpose. */
}
#endif /* #if configUSE_IDLE_HOOK == 1 */
/*-----------------------------------------------------------*/

#if ( configUSE_TICK_HOOK == 1 )
/**********************************************************************************************************************
 * Function Name: vApplicationTickHook
 * Description  : This function will be called every tick interrupt.
 *                NOTE: vApplicationTickHook() EXECUTES FROM WITHIN AN ISR,
 *                      SO MUST BE VERY SHORT AND NOT USE MUCH STACK.
 *                      IN ADDITION, NOT CALL ANY APIs WITHOUT "FromISR" OR "FROM_ISR" AT THE END.
 * Arguments    : None.
 * Return Value : None.
 *********************************************************************************************************************/
void vApplicationTickHook(void)
{
    /* Implement user-code for user own purpose. */
}
#endif /* #if vApplicationTickHook == 1 */
/*-----------------------------------------------------------*/

#if ( configSUPPORT_STATIC_ALLOCATION == 1 )
/**********************************************************************************************************************
 * Function Name: vApplicationGetIdleTaskMemory
 * Description  : This function is to provide the memory for use by the RTOS Idle task.
 * Arguments    : ppxIdleTaskTCBBuffer   - Pointer of TCB buffer
 *                ppxIdleTaskStackBuffer - Pointer of Task stack buffer
 *                pulIdleTaskStackSize   - Pointer of Idle task stack size
 * Return Value : None.
 *********************************************************************************************************************/
void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
                                    StackType_t ** ppxIdleTaskStackBuffer,
                                    configSTACK_DEPTH_TYPE * pulIdleTaskStackSize )
{
    /* If the buffers to be provided to the Idle task are declared inside this
     * function then they must be declared static - otherwise they will be allocated on
     * the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle
     * task's state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
     * Note that, as the array is necessarily of type StackType_t,
     * configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}
/*-----------------------------------------------------------*/

/**********************************************************************************************************************
 * Function Name: vApplicationGetTimerTaskMemory
 * Description  : This function is to provide the memory for use by the RTOS Timer task.
 * Arguments    : ppxIdleTaskTCBBuffer   - Pointer of TCB buffer
 *                ppxIdleTaskStackBuffer - Pointer of Task stack buffer
 *                pulIdleTaskStackSize   - Pointer of Timer task stack size
 * Return Value : None.
 *********************************************************************************************************************/
void vApplicationGetTimerTaskMemory( StaticTask_t ** ppxTimerTaskTCBBuffer,
                                     StackType_t ** ppxTimerTaskStackBuffer,
                                     configSTACK_DEPTH_TYPE * pulTimerTaskStackSize )
{
    /* If the buffers to be provided to the Timer task are declared inside this
     * function then they must be declared static - otherwise they will be allocated on
     * the stack and so not exists after this function exits. */
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle
     * task's state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task's stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
     * Note that, as the array is necessarily of type StackType_t,
     * configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}
/*-----------------------------------------------------------*/
#endif /* #if configSUPPORT_DYNAMIC_ALLOCATION == 1 */

#if ( configUSE_MALLOC_FAILED_HOOK == 1 )
/**********************************************************************************************************************
 * Function Name: vApplicationMallocFailedHook
 * Description  : This function is to capture the failure while memory allocation.
 * Arguments    : None.
 * Return Value : None.
 *********************************************************************************************************************/
void vApplicationMallocFailedHook( void )
{
    taskDISABLE_INTERRUPTS();

    /* Loop forever */
    while(1)
    {
        R_BSP_NOP();
    }
}
#endif /* #if configUSE_MALLOC_FAILED_HOOK == 1 */
/*-----------------------------------------------------------*/

#if ( configCHECK_FOR_STACK_OVERFLOW > 0 )
/**********************************************************************************************************************
 * Function Name: vApplicationStackOverflowHook
 * Description  : Hook function is to capture the failure when the stack size is insufficient for processing.
 * Arguments    : pxTask     - Task handler
 *                pcTaskName - Pointer of where to store the task's name
 * Return Value : None.
 *********************************************************************************************************************/
void vApplicationStackOverflowHook( TaskHandle_t xTask, char * pcTaskName )
{
    portDISABLE_INTERRUPTS();

    /* Unused Parameters */
    ( void ) xTask;
    ( void ) pcTaskName;

    /* Loop forever */
    while(1)
    {
        R_BSP_NOP();
    }
}
#endif /* #if configCHECK_FOR_STACK_OVERFLOW != 0 */
/*-----------------------------------------------------------*/

#if ( configUSE_DAEMON_TASK_STARTUP_HOOK == 1 )
/**********************************************************************************************************************
 * Function Name: vApplicationDaemonTaskStartupHook
 * Description  : This function will be called as soon as the Daemon Task starts executing for the first time. 
 * Arguments    : None.
 * Return Value : None.
 *********************************************************************************************************************/
void vApplicationDaemonTaskStartupHook( void )
{
    /* Implement user-code for user own purpose. */
}
#endif /* #if configUSE_DAEMON_TASK_STARTUP_HOOK == 1 */
/*-----------------------------------------------------------*/

#endif /* (BSP_CFG_RTOS_USED == 1) */

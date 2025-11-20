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
* File Name    : user_task.c
* Description  : Contains user-defined tasks.
**********************************************************************************************************************/
/**********************************************************************************************************************
* History      : DD.MM.YYYY Version Description
*              : 22.12.2025 1.00    First Release
**********************************************************************************************************************/

/**********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
**********************************************************************************************************************/
#include "user_task.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Local Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Private (static) variables and functions
 *********************************************************************************************************************/
TaskHandle_t tskhdl_user_task1;
TaskHandle_t tskhdl_user_task2;

/**********************************************************************************************************************
 Functions
 *********************************************************************************************************************/
void user_task_start(void)
{
    xTaskCreate (vUserTask1, "UserTask1", 256, NULL, CFG_TSKPRI_USER_TASK1, &tskhdl_user_task1);
    xTaskCreate (vUserTask2, "UserTask2", 256, NULL, CFG_TSKPRI_USER_TASK2, &tskhdl_user_task2);
}

void vUserTask1(void *pvParameters)
{
    (void)pvParameters;

    /* Block for 1000ms. */
    const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;

    while(1)
    {
        /* LED0 */
        P4_bit.no3 ^= 1;
        vTaskDelay(xDelay);
    }
}

void vUserTask2(void *pvParameters)
{
    (void)pvParameters;

    /* Block for 2000ms. */
    const TickType_t xDelay = 2000 / portTICK_PERIOD_MS;

    while(1)
    {
        /* LED1 */
        P4_bit.no4 ^= 1;
        vTaskDelay(xDelay);
    }
}
/*-----------------------------------------------------------*/

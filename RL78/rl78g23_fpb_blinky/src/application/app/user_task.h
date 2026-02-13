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
* File Name    : user_task.h
* Description  : User-defined task header file.
**********************************************************************************************************************/
/**********************************************************************************************************************
* History      : DD.MM.YYYY Version Description
*              : 22.12.2025 1.00    First Release
**********************************************************************************************************************/
#ifndef USER_TASK_H_
#define USER_TASK_H_

/**********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
**********************************************************************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "r_cg_userdefine.h"
#include "Pin.h"
#include "platform.h"

/**********************************************************************************************************************
Macro definitions
**********************************************************************************************************************/
#define CFG_TSKPRI_USER_TASK1              (configMAX_PRIORITIES - 1)
#define CFG_TSKPRI_USER_TASK2              (configMAX_PRIORITIES - 1)

/**********************************************************************************************************************
External global variables
**********************************************************************************************************************/

/**********************************************************************************************************************
Exported global functions
**********************************************************************************************************************/
void user_task_start(void);
void vUserTask1(void *pvParameters);
void vUserTask2(void *pvParameters);

#endif /* USER_TASK_H_ */

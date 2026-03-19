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
* File Name    : freertos_user_port.h
* Description  : Header file for user-defined functions which depends on the Renesas RX port implementation.
**********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version Description
*           07.04.2026 1.00    First Release
**********************************************************************************************************************/
#ifndef FREERTOS_USER_PORT_H_
#define FREERTOS_USER_PORT_H_

/**********************************************************************************************************************
Macro definitions
**********************************************************************************************************************/
#include "freertos_helper.h"

/**********************************************************************************************************************
 Macro definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
 Global Typedef definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
 External global variables
**********************************************************************************************************************/

/**********************************************************************************************************************
 Exported global functions
**********************************************************************************************************************/
void vApplicationSetupTimerInterrupt(void);
void vAssertCalled(void);
void Processing_Before_Start_Kernel(void);

#endif /* FREERTOS_USER_PORT_H_ */

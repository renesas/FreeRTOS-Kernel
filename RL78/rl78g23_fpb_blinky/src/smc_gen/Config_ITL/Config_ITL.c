/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2025 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_ITL.c
* Component Version: 1.8.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for Config_ITL.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_ITL.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ITL_Create
* Description  : This function initializes the ITL000_ITL001_ITL012_ITL013 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ITL_Create(void)
{
    uint8_t temp = ITLCSEL0;

    /* Stop 32-bit interval timer */
    ITLCTL0 = 0x00U;
    /* Mask INTITL interrupt */
    ITLMKF0 |= _01_ITL_CHANNEL0_COUNT_MATCH_MASK;
    ITLS0 &= (uint8_t)~_01_ITL_CHANNEL0_COUNT_MATCH_DETECTE;
    ITLMK = 1U;    /* disable INTITL interrupt */
    ITLIF = 0U;    /* clear INTITL interrupt flag */
    /* Set INTITL low priority */
    ITLPR1 = 1U;
    ITLPR0 = 1U;
    /* 32-bit interval timer used as 32-bit timer */
    ITLCTL0 = _80_ITL_MODE_32BIT;
    temp &= _F8_ITL_CLOCK_FITL0_CLEAR;
    temp |= _01_ITL_CLOCK_FITL0_FIHP;
    ITLCSEL0 = temp;
    temp = ITLFDIV00;
    temp &= _F8_ITL_ITL000_FITL0_CLEAR;
    temp |= _00_ITL_ITL000_FITL0_1;
    ITLFDIV00 = temp;
    ITLCMP00 = _7CFF_ITL_ITLCMP00_VALUE;
    ITLCMP01 = _0000_ITL_ITLCMP01_VALUE;
    
    R_Config_ITL_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_ITL_Start
* Description  : This function starts the ITL000_ITL001_ITL012_ITL013 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ITL_Start(void)
{
    ITLS0 &= (uint8_t)~_01_ITL_CHANNEL0_COUNT_MATCH_DETECTE;
    ITLMKF0 &= (uint8_t)~_01_ITL_CHANNEL0_COUNT_MATCH_MASK;
    ITLEN00 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ITL_Stop
* Description  : This function stops the ITL000_ITL001_ITL012_ITL013 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ITL_Stop(void)
{
    ITLMKF0 |= _01_ITL_CHANNEL0_COUNT_MATCH_MASK;
    ITLS0 &= (uint8_t)~_01_ITL_CHANNEL0_COUNT_MATCH_DETECTE;
    ITLEN00 = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ITL_Set_OperationMode
* Description  : This function is used to stop counter and clear interrupt flag before changing operation mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ITL_Set_OperationMode(void)
{
    ITLMKF0 |= _01_ITL_CHANNEL0_COUNT_MATCH_MASK;
    ITLS0 &= (uint8_t)~_01_ITL_CHANNEL0_COUNT_MATCH_DETECTE;
    /* Stop 32-bit interval timer */
    ITLCTL0 &= 0xF0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

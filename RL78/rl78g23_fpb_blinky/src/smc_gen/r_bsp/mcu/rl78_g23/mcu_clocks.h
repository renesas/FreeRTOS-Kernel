/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : mcu_clocks.h
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.03.2021 1.00     First Release
*         : 28.02.2022 1.20     Added the following function.
*                               - change_clock_setting
*                               Changed to enable/disable for each API function.

***********************************************************************************************************************/

/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/

/*************************************************
 * Macro definitions
 *************************************************/
/* Multiple inclusion prevention macro */
#ifndef MCU_CLOCKS_H
#define MCU_CLOCKS_H

/*************************************************
 * Function declaration
 *************************************************/
#if BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t start_clock (e_clock_mode_t mode);
e_bsp_err_t stop_clock (e_clock_mode_t mode);
#endif

#if BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t set_fclk_clock_source (e_clock_mode_t mode);
#endif

#if BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE == 0
uint32_t get_fclk_freq_hz (void);
#endif

#if BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t change_clock_setting (e_clock_mode_t mode, uint8_t * set_values);
#endif

void mcu_clock_setup (void);

#endif /* #ifndef MCU_CLOCKS_H */

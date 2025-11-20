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
* File Name    : r_bsp_common.c
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.03.2021 1.00     First Release
*         : 28.02.2022 1.20     Added the following function.
*                                - R_BSP_ChangeClockSetting
*                               Changed to enable/disable for each API function.
*         : 31.05.2022 1.30     Added the following function.
*                                - R_BSP_SoftwareDelay
*         : 11.11.2022 1.40     Renamed Delay time definition table from bsp_delay_time to g_bsp_delay_time.
*                               Renamed data type from unsigned long long to uint64_t.
*                               Added comment to #endif.
*                               Changed the description of the return value BSP_ERROR1 of
*                               the R_BSP_ChangeClockSetting function.
*                               Removed description of return value BSP_ERROR3 of R_BSP_ChangeClockSetting function.
*         : 07.06.2024 1.70     Changed the number of overhead cycles of
*                               the R_BSP_SoftwareDelay function from 1000 to 2.
***********************************************************************************************************************/

/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
#include "platform.h"

/*************************************************
 * Macro definitions
 *************************************************/
#define BSP_PRV_OVERHEAD_CYCLES    (2U)    /* R_BSP_SoftwareDelay() overhead per call */
#define BSP_PRV_OVERHEAD_CYCLES_64 (2U)    /* R_BSP_SoftwareDelay() overhead per call using 64-bit ints */
#define BSP_CPU_CYCLES_PER_LOOP    (6U)

/*************************************************
 * Private global variables and functions
 *************************************************/
/* Delay time definition table */
#if BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE == 0
const uint64_t g_bsp_delay_time[] = {
    1,
    1000,
    1000000
};
#endif

/*************************************************
 * Function definition
 *************************************************/
extern void delay_wait (uint32_t count);

/**********************************************************************************************************************
 * Function Name: R_BSP_StartClock
 ******************************************************************************************************************//**
 * @brief Start the specified clock and return.
 * @param[in] mode Clock to start.
 * @retval BSP_OK BSP_OK if the specified clock is started.
 * @retval BSP_ARG_ERROR BSP_ARG_ERROR if the specified clock is incorrect.
 * @details This function starts the specified clock.
 * Specify one of the following for mode.
 * HIOCLK : High-speed on-chip oscillator
 * SYSCLK : High-speed system clock
 * SXCLK  : Subsystem clock
 * MIOCLK : Middle-speed on-chip oscillator
 * LOCLK  : Low-speed on-chip oscillator
 */
#if BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t R_BSP_StartClock(e_clock_mode_t mode)
{
    return (start_clock(mode));
} /* End of function R_BSP_StartClock() */
#endif

/**********************************************************************************************************************
 * Function Name: R_BSP_StopClock
 ******************************************************************************************************************//**
 * @brief Stop the specified clock and return.
 * @param[in] mode Clock to stop.
 * @retval BSP_OK BSP_OK if the specified clock is stopped.
 * @retval BSP_ARG_ERROR BSP_ARG_ERROR if the specified clock is incorrect.
 * @details This function stops the specified clock.
 * Specify one of the following for mode.
 * HIOCLK : High-speed on-chip oscillator
 * SYSCLK : High-speed system clock
 * SXCLK  : Subsystem clock
 * MIOCLK : Middle-speed on-chip oscillator
 * LOCLK  : Low-speed on-chip oscillator
 */
#if BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t R_BSP_StopClock(e_clock_mode_t mode)
{
    return (stop_clock(mode));
} /* End of function R_BSP_StopClock() */
#endif

/**********************************************************************************************************************
 * Function Name: R_BSP_SetClockSource
 ******************************************************************************************************************//**
 * @brief Switch CPU/peripheral hardware clock(fCLK) clock source and return.
 * @param[in] mode Clock to switch.
 * @retval BSP_OK BSP_OK when switching to the specified clock.
 * @retval BSP_ERROR1 When HIOCLK is specified, but high-speed on-chip oscillator is stopped.
 * @retval BSP_ERROR2 When SYSCLK is specified, but high-speed system clock is stopped.
 * @retval BSP_ERROR3 When SXCLK is specified, but Subsystem clock is stopped.
 * @retval BSP_ERROR4 When MIOCLK is specified, but middle-speed on-chip oscillator is stopped.
 * @retval BSP_ARG_ERROR BSP_ARG_ERROR if the specified clock is incorrect.
 * @details This function switches the specified clock.
 * Specify one of the following for mode.
 * HIOCLK : High-speed on-chip oscillator
 * SYSCLK : High-speed system clock
 * SXCLK  : Subsystem clock
 * MIOCLK : Middle-speed on-chip oscillator
 * LOCLK  : Low-speed on-chip oscillator
 */
#if BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t R_BSP_SetClockSource(e_clock_mode_t mode)
{
    return (set_fclk_clock_source(mode));
} /* End of function R_BSP_SetClockSource() */
#endif

/**********************************************************************************************************************
 * Function Name: R_BSP_GetFclkFreqHz
 ******************************************************************************************************************//**
 * @brief Returns CPU/peripheral hardware clock(fCLK) frequency.
 * @return CPU/peripheral hardware clock(fCLK) frequency specified by the r_bsp.
 * @details This function returns the CPU/peripheral hardware clock(fCLK) frequency.
 * For example, when the CPU/peripheral hardware clock(fCLK) is set to 20 MHz in r_bsp_config.h
 * and the r_bsp has completed to specify the clock setting, then even if the user changed the
 * CPU/peripheral hardware clock(fCLK) frequency to 10 MHz, the return value is '10000000'.
 */
#if BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE == 0
uint32_t R_BSP_GetFclkFreqHz(void)
{
    return (get_fclk_freq_hz());
} /* End of function R_BSP_GetFclkFreqHz() */
#endif

/**********************************************************************************************************************
 * Function Name: R_BSP_ChangeClockSetting
 ******************************************************************************************************************//**
 * @brief Change the specified clock setting and return.
 * @param[in] mode Clock to change settings.
 * @param[in] set_values Value to set for the specified clock.
 * @retval BSP_OK BSP_OK if the specified clock setting is changed.
 * @retval BSP_ERRPR1 When the specified clock is in the setting change prohibited state.
 * @retval            Refer to the Application Note.
 * @retval BSP_ARG_ERROR BSP_ARG_ERROR if the specified clock is incorrect.
 * @details This function changes the specified clock setting.
 * Specify one of the following for mode.
 * HIOCLK : High-speed on-chip oscillator
 * MIOCLK : Middle-speed on-chip oscillator
 * PLLCLK : PLL clock
 */
#if BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t R_BSP_ChangeClockSetting(e_clock_mode_t mode, uint8_t * set_values)
{
    return (change_clock_setting(mode, set_values));
} /* End of function R_BSP_ChangeClockSetting() */
#endif

/**********************************************************************************************************************
 * Function Name: R_BSP_SoftwareDelay
 ******************************************************************************************************************//**
 * @brief Delay the specified duration in units and return.
 * @param[in] delay The number of 'units' to delay.
 * @param[in] units The 'base' for the unitsspecified.
 * @retval BSP_OK BSP_OK if delay executed.
 * @retval BSP_ERRPR1 BSP_ERROR1 if delay/units combination resulted in overflow/underflow.
 * @details This is function that may be called for all MCU targets to implement a specific wait time.
 * The actual delay time is plus the overhead at a specified duration. The overhead changes under the influence of
 * the compiler, operating frequency and ROM cache. When the operating frequency is low, or the specified duration in
 * units of microsecond level, please note that the error becomes large.
 */
#if BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t R_BSP_SoftwareDelay(uint32_t delay, e_bsp_delay_units_t units)
{
    volatile uint32_t fclk_rate;
    volatile uint32_t delay_cycles;
    volatile uint32_t loop_cnt;
    volatile uint64_t loop_cnt_64;
    volatile uint64_t delay_cycles_64;

    fclk_rate = R_BSP_GetFclkFreqHz();    /* Get the current ICLK frequency. */

    /*
     * In order to handle all possible combinations of delay/ICLK it is necessary to use 64-bit
     * integers (not all MCUs have floating point support). However, there is no native hw support
     * for 64 bitintegers so it requires many more clock cycles. This is not an issue if the
     * requested delay is long enough and the ICLK is fast, but for delays in the low microseconds
     * and/or a slow ICLK we use 32 bit integers to reduce the overhead cycles of this function
     * by approximately a third and stand the best chance of achieving the requested delay.
     */
    if ((BSP_DELAY_MICROSECS == units) &&
        (delay <= (0xFFFFFFFFUL / fclk_rate)))    /* Ensure (fclk_rate * delay) will not exceed 32 bits. */
    {
        delay_cycles = ((fclk_rate * delay) / g_bsp_delay_time[units]);

        if (delay_cycles > BSP_PRV_OVERHEAD_CYCLES)
        {
            delay_cycles -= BSP_PRV_OVERHEAD_CYCLES;
        }
        else
        {
            delay_cycles = 0U;
        }

        loop_cnt = delay_cycles / BSP_CPU_CYCLES_PER_LOOP;

        if (0U == loop_cnt)
        {
            /* The requested delay is too large/small for the current ICLK. Return BSP_ERROR1 which
             * also results in the minimum possible delay. */
            return BSP_ERROR1;
        }
    }
    else
    {
        /* Casting is valid because it matches the type to the right side or argument. */
        delay_cycles_64 = (((uint64_t)fclk_rate * (uint64_t)delay) / g_bsp_delay_time[units]);

        if (delay_cycles_64 > BSP_PRV_OVERHEAD_CYCLES_64)
        {
            delay_cycles_64 -= BSP_PRV_OVERHEAD_CYCLES_64;
        }
        else
        {
            delay_cycles = 0U;
        }

        loop_cnt_64 = delay_cycles_64 / BSP_CPU_CYCLES_PER_LOOP;

        if ((loop_cnt_64 > 0xFFFFFFFFUL) || (0U == loop_cnt_64))
        {
            /* The requested delay is too large/small for the current ICLK. Return BSP_ERROR1 which
             * also results in the minimum possible delay. */
            return BSP_ERROR1;
        }

        /* Casting is valid because it matches the type to the right side or argument. */
        loop_cnt = (uint32_t)loop_cnt_64;
    }

    delay_wait (loop_cnt);

    return BSP_OK;
} /* End of function R_BSP_SoftwareDelay() */
#endif /* BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE == 0 */

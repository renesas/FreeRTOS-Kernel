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
* File Name    : fsp_common_api.h
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.09.2021 1.00     First Release
*         : 28.02.2022 1.20     Added the following common error codes.
*                               - FSP_ERR_CTSU_SCANNING
*                               - FSP_ERR_CTSU_NOT_GET_DATA
*                               - FSP_ERR_CTSU_INCOMPLETE_TUNING
*                               - FSP_ERR_CTSU_DIAG_NOT_YET
*                               - FSP_ERR_CTSU_DIAG_LDO_OVER_VOLTAGE
*                               - FSP_ERR_CTSU_DIAG_CCO_HIGH
*                               - FSP_ERR_CTSU_DIAG_CCO_LOW
*                               - FSP_ERR_CTSU_DIAG_SSCG
*                               - FSP_ERR_CTSU_DIAG_DAC
*                               - FSP_ERR_CTSU_DIAG_OUTPUT_VOLTAGE
*                               - FSP_ERR_CTSU_DIAG_OVER_VOLTAGE
*                               - FSP_ERR_CTSU_DIAG_OVER_CURRENT
*                               - FSP_ERR_CTSU_DIAG_LOAD_RESISTANCE
*                               - FSP_ERR_CTSU_DIAG_CURRENT_SOURCE
*                               - FSP_ERR_CTSU_DIAG_SENSCLK_GAIN
*                               - FSP_ERR_CTSU_DIAG_SUCLK_GAIN
*                               - FSP_ERR_CTSU_DIAG_CLOCK_RECOVERY
*                               - FSP_ERR_CTSU_DIAG_CFC_GAIN
***********************************************************************************************************************/

/* ${REA_DISCLAIMER_PLACEHOLDER} */

#ifndef FSP_COMMON_API_H
#define FSP_COMMON_API_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include <assert.h>
#include <stdint.h>

/*******************************************************************************************************************//**
 * @ingroup RENESAS_COMMON
 * @defgroup RENESAS_ERROR_CODES Common Error Codes
 * All FSP modules share these common error codes.
 * @{
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/** This macro is used to suppress compiler messages about a parameter not being used in a function. The nice thing
 * about using this implementation is that it does not take any extra RAM or ROM. */

#define FSP_PARAMETER_NOT_USED(p)    (void) ((p))

/** Determine if a C++ compiler is being used.
 * If so, ensure that standard C is used to process the API information.  */
#if defined(__cplusplus)
 #define FSP_CPP_HEADER    extern "C" {
 #define FSP_CPP_FOOTER    }
#else
 #define FSP_CPP_HEADER
 #define FSP_CPP_FOOTER
#endif

/** FSP Header and Footer definitions */
#define FSP_HEADER             FSP_CPP_HEADER
#define FSP_FOOTER             FSP_CPP_FOOTER

/** Macro to be used when argument to function is ignored since function call is NSC and the parameter is statically
 *  defined on the Secure side. */
#define FSP_SECURE_ARGUMENT    (NULL)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Common error codes */
typedef enum e_fsp_err
{
    FSP_SUCCESS = 0,

    FSP_ERR_ASSERTION             = 1,                      ///< A critical assertion has failed
    FSP_ERR_INVALID_POINTER       = 2,                      ///< Pointer points to invalid memory location
    FSP_ERR_INVALID_ARGUMENT      = 3,                      ///< Invalid input parameter
    FSP_ERR_INVALID_CHANNEL       = 4,                      ///< Selected channel does not exist
    FSP_ERR_INVALID_MODE          = 5,                      ///< Unsupported or incorrect mode
    FSP_ERR_UNSUPPORTED           = 6,                      ///< Selected mode not supported by this API
    FSP_ERR_NOT_OPEN              = 7,                      ///< Requested channel is not configured or API not open
    FSP_ERR_IN_USE                = 8,                      ///< Channel/peripheral is running/busy
    FSP_ERR_OUT_OF_MEMORY         = 9,                      ///< Allocate more memory in the driver's cfg.h
    FSP_ERR_HW_LOCKED             = 10,                     ///< Hardware is locked
    FSP_ERR_IRQ_BSP_DISABLED      = 11,                     ///< IRQ not enabled in BSP
    FSP_ERR_OVERFLOW              = 12,                     ///< Hardware overflow
    FSP_ERR_UNDERFLOW             = 13,                     ///< Hardware underflow
    FSP_ERR_ALREADY_OPEN          = 14,                     ///< Requested channel is already open in a different configuration
    FSP_ERR_APPROXIMATION         = 15,                     ///< Could not set value to exact result
    FSP_ERR_CLAMPED               = 16,                     ///< Value had to be limited for some reason
    FSP_ERR_INVALID_RATE          = 17,                     ///< Selected rate could not be met
    FSP_ERR_ABORTED               = 18,                     ///< An operation was aborted
    FSP_ERR_NOT_ENABLED           = 19,                     ///< Requested operation is not enabled
    FSP_ERR_TIMEOUT               = 20,                     ///< Timeout error
    FSP_ERR_INVALID_BLOCKS        = 21,                     ///< Invalid number of blocks supplied
    FSP_ERR_INVALID_ADDRESS       = 22,                     ///< Invalid address supplied
    FSP_ERR_INVALID_SIZE          = 23,                     ///< Invalid size/length supplied for operation
    FSP_ERR_WRITE_FAILED          = 24,                     ///< Write operation failed
    FSP_ERR_ERASE_FAILED          = 25,                     ///< Erase operation failed
    FSP_ERR_INVALID_CALL          = 26,                     ///< Invalid function call is made
    FSP_ERR_INVALID_HW_CONDITION  = 27,                     ///< Detected hardware is in invalid condition
    FSP_ERR_INVALID_FACTORY_FLASH = 28,                     ///< Factory flash is not available on this MCU
    FSP_ERR_INVALID_STATE         = 30,                     ///< API or command not valid in the current state
    FSP_ERR_NOT_ERASED            = 31,                     ///< Erase verification failed
    FSP_ERR_SECTOR_RELEASE_FAILED = 32,                     ///< Sector release failed
    FSP_ERR_NOT_INITIALIZED       = 33,                     ///< Required initialization not complete
    FSP_ERR_NOT_FOUND             = 34,                     ///< The requested item could not be found
    FSP_ERR_NO_CALLBACK_MEMORY    = 35,                     ///< Non-secure callback memory not provided for non-secure callback
    FSP_ERR_BUFFER_EMPTY          = 36,                     ///< No data available in buffer

    /* Start of RTOS only error codes */
    FSP_ERR_INTERNAL     = 100,                             ///< Internal error
    FSP_ERR_WAIT_ABORTED = 101,                             ///< Wait aborted

    /* Start of Sensor specific */
    FSP_ERR_SENSOR_INVALID_DATA,                ///< Data is invalid.
    FSP_ERR_SENSOR_IN_STABILIZATION,            ///< Sensor is stabilizing.
    FSP_ERR_SENSOR_MEASUREMENT_NOT_FINISHED,    ///< Measurement is not finished.

    /* Start of CTSU Driver specific */
    FSP_ERR_CTSU_SCANNING              = 6000,       ///< Scanning.
    FSP_ERR_CTSU_NOT_GET_DATA          = 6001,       ///< Not processed previous scan data.
    FSP_ERR_CTSU_INCOMPLETE_TUNING     = 6002,       ///< Incomplete initial offset tuning.
    FSP_ERR_CTSU_DIAG_NOT_YET          = 6003,       ///< Diagnosis of data collected no yet.
    FSP_ERR_CTSU_DIAG_LDO_OVER_VOLTAGE = 6004,       ///< Diagnosis of LDO over voltage failed.
    FSP_ERR_CTSU_DIAG_CCO_HIGH         = 6005,       ///< Diagnosis of CCO into 19.2uA failed.
    FSP_ERR_CTSU_DIAG_CCO_LOW          = 6006,       ///< Diagnosis of CCO into 2.4uA failed.
    FSP_ERR_CTSU_DIAG_SSCG             = 6007,       ///< Diagnosis of SSCG frequency failed.
    FSP_ERR_CTSU_DIAG_DAC              = 6008,       ///< Diagnosis of non-touch count value failed.
    FSP_ERR_CTSU_DIAG_OUTPUT_VOLTAGE   = 6009,       ///< Diagnosis of LDO output voltage failed.
    FSP_ERR_CTSU_DIAG_OVER_VOLTAGE     = 6010,       ///< Diagnosis of over voltage detection circuit failed.
    FSP_ERR_CTSU_DIAG_OVER_CURRENT     = 6011,       ///< Diagnosis of over current detection circuit failed.
    FSP_ERR_CTSU_DIAG_LOAD_RESISTANCE  = 6012,       ///< Diagnosis of LDO internal resistance value failed.
    FSP_ERR_CTSU_DIAG_CURRENT_SOURCE   = 6013,       ///< Diagnosis of Current source value failed.
    FSP_ERR_CTSU_DIAG_SENSCLK_GAIN     = 6014,       ///< Diagnosis of SENSCLK frequency gain failed.
    FSP_ERR_CTSU_DIAG_SUCLK_GAIN       = 6015,       ///< Diagnosis of SUCLK frequency gain failed.
    FSP_ERR_CTSU_DIAG_CLOCK_RECOVERY   = 6016,       ///< Diagnosis of SUCLK clock recovery function failed.
    FSP_ERR_CTSU_DIAG_CFC_GAIN         = 6017,       ///< Diagnosis of CFC oscillator gain failed.

    /* Start of COMMS specific */
    FSP_ERR_COMMS_BUS_NOT_OPEN,                 ///< Bus is not open.
} fsp_err_t;

/** @} */

/***********************************************************************************************************************
 * Function prototypes
 **********************************************************************************************************************/

#endif

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
* File Name        : r_cg_itl.h
* Version          : 1.0.51
* Device(s)        : R7F100GSNxFB
* Description      : General header file for ITL peripheral.
***********************************************************************************************************************/

#ifndef ITL_H
#define ITL_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 1 (PER1)
*/
/* Control of clock supply to 32-bit interval timer (TML32EN) */
#define _00_ITL_CLOCK_STOP                                (0x00U)    /* stops clock supply */
#define _10_ITL_CLOCK_SUPPLY                              (0x10U)    /* supplies clock */

/*
    Peripheral Reset Control Register 1 (PRR1)
*/
/* Peripheral reset control of 32-bit interval timer (TML32RES) */
#define _00_ITL_RESET_RELEASE                             (0x00U)    /* released from the reset state */
#define _10_ITL_RESET_SET                                 (0x10U)    /* reset */

/*
    Interval Timer Control Register (ITLCTL0)
*/
/* Selection of 8-bit, 16-bit or 32-bit interval timer mode (ITLMD01,ITLMD00) */
#define _00_ITL_MODE_8BIT                                 (0x00U)    /* 8-bit interval timer */
#define _40_ITL_MODE_16BIT                                (0x40U)    /* 16-bit interval timer */
#define _80_ITL_MODE_32BIT                                (0x80U)    /* 32-bit interval timer */
/* Count enable for ITL013 (ITLEN03) */
#define _00_ITL_ITL013_COUNT_STOP                         (0x00U)    /* counting stops */
#define _08_ITL_ITL013_COUNT_START                        (0x08U)    /* counting begins */
/* Count enable for ITL012 / ITL012 + ITL013 (ITLEN02) */
#define _00_ITL_ITL012_COUNT_STOP                         (0x00U)    /* counting stops */
#define _04_ITL_ITL012_COUNT_START                        (0x04U)    /* counting begins */
/* Count enable for ITL001 (ITLEN01) */
#define _00_ITL_ITL001_COUNT_STOP                         (0x00U)    /* counting stops */
#define _02_ITL_ITL001_COUNT_START                        (0x02U)    /* counting begins */
/* Count enable for ITL000/ITL000+ITL001/ITL000+ITL001+ITL012+ITL013 (ITLEN00) */
#define _00_ITL_ITL000_COUNT_STOP                         (0x00U)    /* counting stops */
#define _01_ITL_ITL000_COUNT_START                        (0x01U)    /* counting begins */

/*
    Interval Timer Clock Select Register 0 (ITLCSEL0)
*/
/* Selection of interval timer count source for capturing (fITL1) (CSEL012,CSEL011,CSEL010) */
#define _00_ITL_CLOCK_FITL1_STOP                          (0x00U)    /* counting stops */
#define _10_ITL_CLOCK_FITL1_FIHP                          (0x10U)    /* fIHP */
#define _20_ITL_CLOCK_FITL1_FIMP                          (0x20U)    /* fIMP */
#define _30_ITL_CLOCK_FITL1_FMXP                          (0x30U)    /* fMXP */
#define _40_ITL_CLOCK_FITL1_FSXP                          (0x40U)    /* fSXP */
#define _50_ITL_CLOCK_FITL1_ELCL                          (0x50U)    /* event input from ELCL */
#define _8F_ITL_CLOCK_FITL1_CLEAR                         (0x8FU)    /* clear clock selection of fITL1 */
/* Selection interval timer count source (fITL0) (ISEL002,ISEL001,ISEL000) */
#define _00_ITL_CLOCK_FITL0_STOP                          (0x00U)    /* counting stops */
#define _01_ITL_CLOCK_FITL0_FIHP                          (0x01U)    /* fIHP */
#define _02_ITL_CLOCK_FITL0_FIMP                          (0x02U)    /* fIMP */
#define _03_ITL_CLOCK_FITL0_FMXP                          (0x03U)    /* fMXP */
#define _04_ITL_CLOCK_FITL0_FSXP                          (0x04U)    /* fSXP */
#define _05_ITL_CLOCK_FITL0_ELCL                          (0x05U)    /* event input from ELCL */
#define _F8_ITL_CLOCK_FITL0_CLEAR                         (0xF8U)    /* clear clock selection of fITL0 */

/*
    Interval Timer Frequency Division Register 0 (ITLFDIV00)
 */
/* Selection of frequency division ratio for ITL001 (FDIV012,FDIV011,FDIV010) */
#define _00_ITL_ITL001_FITL0_1                            (0x00U)    /* fITL0 */
#define _10_ITL_ITL001_FITL0_2                            (0x10U)    /* fITL0/2 */
#define _20_ITL_ITL001_FITL0_4                            (0x20U)    /* fITL0/4 */
#define _30_ITL_ITL001_FITL0_8                            (0x30U)    /* fITL0/8 */
#define _40_ITL_ITL001_FITL0_16                           (0x40U)    /* fITL0/16 */
#define _50_ITL_ITL001_FITL0_32                           (0x50U)    /* fITL0/32 */
#define _60_ITL_ITL001_FITL0_64                           (0x60U)    /* fITL0/64 */
#define _70_ITL_ITL001_FITL0_128                          (0x70U)    /* fITL0/128 */
#define _8F_ITL_ITL001_FITL0_CLEAR                        (0x8FU)    /* clear fITL0 division selection of ITL001 */
/* Selection of frequency division ratio for ITL000 (FDIV002,FDIV001,FDIV000) */
#define _00_ITL_ITL000_FITL0_1                            (0x00U)    /* fITL0 */
#define _01_ITL_ITL000_FITL0_2                            (0x01U)    /* fITL0/2 */
#define _02_ITL_ITL000_FITL0_4                            (0x02U)    /* fITL0/4 */
#define _03_ITL_ITL000_FITL0_8                            (0x03U)    /* fITL0/8 */
#define _04_ITL_ITL000_FITL0_16                           (0x04U)    /* fITL0/16 */
#define _05_ITL_ITL000_FITL0_32                           (0x05U)    /* fITL0/32 */
#define _06_ITL_ITL000_FITL0_64                           (0x06U)    /* fITL0/64 */
#define _07_ITL_ITL000_FITL0_128                          (0x07U)    /* fITL0/128 */
#define _F8_ITL_ITL000_FITL0_CLEAR                        (0xF8U)    /* clear fITL0 division selection of ITL000 */

/*
    Interval Timer Frequency Division Register 1 (ITLFDIV01)
 */
/* Selection of frequency division ratio for ITL013 (FDIV032,FDIV031,FDIV030) */
#define _00_ITL_ITL013_FITL0_1                            (0x00U)    /* fITL0 */
#define _10_ITL_ITL013_FITL0_2                            (0x10U)    /* fITL0/2 */
#define _20_ITL_ITL013_FITL0_4                            (0x20U)    /* fITL0/4 */
#define _30_ITL_ITL013_FITL0_8                            (0x30U)    /* fITL0/8 */
#define _40_ITL_ITL013_FITL0_16                           (0x40U)    /* fITL0/16 */
#define _50_ITL_ITL013_FITL0_32                           (0x50U)    /* fITL0/32 */
#define _60_ITL_ITL013_FITL0_64                           (0x60U)    /* fITL0/64 */
#define _70_ITL_ITL013_FITL0_128                          (0x70U)    /* fITL0/128 */
#define _8F_ITL_ITL013_FITL0_CLEAR                        (0x8FU)    /* clear fITL0 division selection of ITL013 */
/* Selection of frequency division ratio for ITL012 (FDIV022,FDIV021,FDIV020) */
#define _00_ITL_ITL012_FITL0_1                            (0x00U)    /* fITL0 */
#define _01_ITL_ITL012_FITL0_2                            (0x01U)    /* fITL0/2 */
#define _02_ITL_ITL012_FITL0_4                            (0x02U)    /* fITL0/4 */
#define _03_ITL_ITL012_FITL0_8                            (0x03U)    /* fITL0/8 */
#define _04_ITL_ITL012_FITL0_16                           (0x04U)    /* fITL0/16 */
#define _05_ITL_ITL012_FITL0_32                           (0x05U)    /* fITL0/32 */
#define _06_ITL_ITL012_FITL0_64                           (0x06U)    /* fITL0/64 */
#define _07_ITL_ITL012_FITL0_128                          (0x07U)    /* fITL0/128 */
#define _F8_ITL_ITL012_FITL0_CLEAR                        (0xF8U)    /* clear fITL0 division selection of ITL012 */

/*
    Interval Timer Capture Control Register 0 (ITLCC0)
*/
/* Capture enable (CAPEN0) */
#define _00_ITL_CAPTURE_DISABLE                           (0x00U)    /* capture is disabled */
#define _80_ITL_CAPTURE_ENABLE                            (0x80U)    /* capture is enabled */
/* Capture completion flag clear (CAPF0CR) */
#define _00_ITL_CAPTURE_COMPLETE_FLAG_RETAIN              (0x00U)    /* held capture completion flag CAPF0 */
#define _40_ITL_CAPTURE_COMPLETE_FLAG_CLEAR               (0x40U)    /* clear capture completion flag CAPF0 */
/* Capture completion flag (CAPF0) */
#define _00_ITL_CAPTURE_NOT_COMPLETE                      (0x00U)    /* capture not complete */
#define _20_ITL_CAPTURE_COMPLETE                          (0x20U)    /* capture complete */
/* Software capture trigger (CAPR0) */
#define _00_ITL_CAPTURE_SOFTWARE_NOT_TRIGGER              (0x00U)    /* software trigger is not generated */
#define _10_ITL_CAPTURE_SOFTWARE_TRIGGER                  (0x10U)    /* software trigger is generated */
/* Selection of 16-bit counter (ITL000 + ITL001) clearing after capturing (CAPC0CR) */
#define _00_ITL_CAPTURE_COUNTER_RETAIN                    (0x00U)    /* held the capture counter value */
#define _08_ITL_CAPTURE_COUNTER_CLEAR                     (0x08U)    /* clear the capture counter value */
/* Selection of capture trigger (CTRS01,CTRS00) */
#define _00_ITL_CAPTURE_TRIGGER_SOFTWARE                  (0x00U)    /* software trigger */
#define _01_ITL_CAPTURE_TRIGGER_INTERNAL                  (0x01U)    /* interrupt on compare match with ITLCMP01 */
#define _02_ITL_CAPTURE_TRIGGER_FSXP                      (0x02U)    /* fSXP */
#define _03_ITL_CAPTURE_TRIGGER_ELCL                      (0x03U)    /* event input from ELCL */
#define _FC_ITL_CAPTURE_TRIGGER_CLEAR                     (0xFCU)    /* clear capture trigger selection */

/*
    Interval Timer Status Register (ITLS0)
*/
/* Capture detection flag (ITF0C) */
#define _00_ITL_CAPTURE_COMPLETE_NOT_DETECTE              (0x00U)    /* completion of capturing not be detected */
#define _10_ITL_CAPTURE_COMPLETE_DETECTE                  (0x10U)    /* completion of capturing be detected */
/* Compare match detection flag for channel 3 (ITF03) */
#define _00_ITL_CHANNEL3_COUNT_MATCH_NOT_DETECTE          (0x00U)    /* channel 3 compare match signal not detected */
#define _08_ITL_CHANNEL3_COUNT_MATCH_DETECTE              (0x08U)    /* channel 3 compare match signal detected */
/* Compare match detection flag for channel 2 (ITF02) */
#define _00_ITL_CHANNEL2_COUNT_MATCH_NOT_DETECTE          (0x00U)    /* channel 2 compare match signal not detected */
#define _04_ITL_CHANNEL2_COUNT_MATCH_DETECTE              (0x04U)    /* channel 2 compare match signal detected */
/* Compare match detection flag for channel 1 (ITF01) */
#define _00_ITL_CHANNEL1_COUNT_MATCH_NOT_DETECTE          (0x00U)    /* channel 1 compare match signal not detected */
#define _02_ITL_CHANNEL1_COUNT_MATCH_DETECTE              (0x02U)    /* channel 1 compare match signal detected */
/* Compare match detection flag for channel 0 (ITF00) */
#define _00_ITL_CHANNEL0_COUNT_MATCH_NOT_DETECTE          (0x00U)    /* channel 0 compare match signal not detected */
#define _01_ITL_CHANNEL0_COUNT_MATCH_DETECTE              (0x01U)    /* channel 0 compare match signal detected */

/*
    Interval Timer Match Detection Mask Register (ITLMKF0)
*/
/* Mask for capture detection status flag (MKF0C) */
#define _00_ITL_CAPTURE_COMPLETE_NOT_MASK                 (0x00U)    /* not mask ITF0C */
#define _10_ITL_CAPTURE_COMPLETE_MASK                     (0x10U)    /* mask ITF0C */
/* Mask for compare match status flag for channel 3 (MKF03) */
#define _00_ITL_CHANNEL3_COUNT_MATCH_NOT_MASK             (0x00U)    /* not mask ITF03 */
#define _08_ITL_CHANNEL3_COUNT_MATCH_MASK                 (0x08U)    /* mask ITF03 */
/* Mask for compare match status flag for channel 2 (MKF02) */
#define _00_ITL_CHANNEL2_COUNT_MATCH_NOT_MASK             (0x00U)    /* not mask ITF02 */
#define _04_ITL_CHANNEL2_COUNT_MATCH_MASK                 (0x04U)    /* mask ITF02 */
/* Mask for compare match status flag for channel 1 (MKF01) */
#define _00_ITL_CHANNEL1_COUNT_MATCH_NOT_MASK             (0x00U)    /* not mask ITF01 */
#define _02_ITL_CHANNEL1_COUNT_MATCH_MASK                 (0x02U)    /* mask ITF01 */
/* Mask for compare match status flag for channel 0 (MKF00) */
#define _00_ITL_CHANNEL0_COUNT_MATCH_NOT_MASK             (0x00U)    /* not mask ITF00 */
#define _01_ITL_CHANNEL0_COUNT_MATCH_MASK                 (0x01U)    /* mask ITF00 */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

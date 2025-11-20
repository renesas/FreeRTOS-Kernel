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
* File Name        : r_cg_port.h
* Version          : 1.0.51
* Device(s)        : R7F100GSNxFB
* Description      : General header file for PORT peripheral.
***********************************************************************************************************************/

#ifndef PORT_H
#define PORT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Port Mode Registers (PMn)
*/
/* Pn7 pin I/O mode selection (PMn7) */
#define _00_PMn7_MODE_OUTPUT                    (0x00U)    /* use Pn7 as output mode */
#define _80_PMn7_MODE_INPUT                     (0x80U)    /* use Pn7 as input mode */
#define _80_PMn7_NOT_USE                        (0x80U)    /* not use Pn7 as digital I/O */
/* Pn6 pin I/O mode selection (PMn6) */
#define _00_PMn6_MODE_OUTPUT                    (0x00U)    /* use Pn6 as output mode */
#define _40_PMn6_MODE_INPUT                     (0x40U)    /* use Pn6 as input mode */
#define _40_PMn6_NOT_USE                        (0x40U)    /* not use Pn6 as digital I/O */
/* Pn5 pin I/O mode selection (PMn5) */
#define _00_PMn5_MODE_OUTPUT                    (0x00U)    /* use Pn5 as output mode */
#define _20_PMn5_MODE_INPUT                     (0x20U)    /* use Pn5 as input mode */
#define _20_PMn5_NOT_USE                        (0x20U)    /* not use Pn5 as digital I/O */
/* Pn4 pin I/O mode selection (PMn4) */
#define _00_PMn4_MODE_OUTPUT                    (0x00U)    /* use Pn4 as output mode */
#define _10_PMn4_MODE_INPUT                     (0x10U)    /* use Pn4 as input mode */
#define _10_PMn4_NOT_USE                        (0x10U)    /* not use Pn4 as digital I/O */
/* Pn3 pin I/O mode selection (PMn3) */
#define _00_PMn3_MODE_OUTPUT                    (0x00U)    /* use Pn3 as output mode */
#define _08_PMn3_MODE_INPUT                     (0x08U)    /* use Pn3 as input mode */
#define _08_PMn3_NOT_USE                        (0x08U)    /* not use Pn3 as digital I/O */
/* Pn2 pin I/O mode selection (PMn2) */
#define _00_PMn2_MODE_OUTPUT                    (0x00U)    /* use Pn2 as output mode */
#define _04_PMn2_MODE_INPUT                     (0x04U)    /* use Pn2 as input mode */
#define _04_PMn2_NOT_USE                        (0x04U)    /* not use Pn2 as digital I/O */
/* Pn1 pin I/O mode selection (PMn1) */
#define _00_PMn1_MODE_OUTPUT                    (0x00U)    /* use Pn1 as output mode */
#define _02_PMn1_MODE_INPUT                     (0x02U)    /* use Pn1 as input mode */
#define _02_PMn1_NOT_USE                        (0x02U)    /* not use Pn1 as digital I/O */
/* Pn0 pin I/O mode selection (PMn0) */
#define _00_PMn0_MODE_OUTPUT                    (0x00U)    /* use Pn0 as output mode */
#define _01_PMn0_MODE_INPUT                     (0x01U)    /* use Pn0 as input mode */
#define _01_PMn0_NOT_USE                        (0x01U)    /* not use Pn0 as digital I/O */

/*
    Port Registers (Pn)
*/
/* Pn7 pin output latch selection (Pn7) */
#define _00_Pn7_OUTPUT_0                        (0x00U)    /* Pn7 output 0 */
#define _80_Pn7_OUTPUT_1                        (0x80U)    /* Pn7 output 1 */
/* Pn6 pin output latch selection (Pn6) */
#define _00_Pn6_OUTPUT_0                        (0x00U)    /* Pn6 output 0 */
#define _40_Pn6_OUTPUT_1                        (0x40U)    /* Pn6 output 1 */
/* Pn5 pin output latch selection (Pn5) */
#define _00_Pn5_OUTPUT_0                        (0x00U)    /* Pn5 output 0 */
#define _20_Pn5_OUTPUT_1                        (0x20U)    /* Pn5 output 1 */
/* Pn4 pin output latch selection (Pn4) */
#define _00_Pn4_OUTPUT_0                        (0x00U)    /* Pn4 output 0 */
#define _10_Pn4_OUTPUT_1                        (0x10U)    /* Pn4 output 1 */
/* Pn3 pin output latch selection (Pn3) */
#define _00_Pn3_OUTPUT_0                        (0x00U)    /* Pn3 output 0 */
#define _08_Pn3_OUTPUT_1                        (0x08U)    /* Pn3 output 1 */
/* Pn2 pin output latch selection (Pn2) */
#define _00_Pn2_OUTPUT_0                        (0x00U)    /* Pn2 output 0 */
#define _04_Pn2_OUTPUT_1                        (0x04U)    /* Pn2 output 1 */
/* Pn1 pin output latch selection (Pn1) */
#define _00_Pn1_OUTPUT_0                        (0x00U)    /* Pn1 output 0 */
#define _02_Pn1_OUTPUT_1                        (0x02U)    /* Pn1 output 1 */
/* Pn0 pin output latch selection (Pn0) */
#define _00_Pn0_OUTPUT_0                        (0x00U)    /* Pn0 output 0 */
#define _01_Pn0_OUTPUT_1                        (0x01U)    /* Pn0 output 1 */

/*
    Pull-up Resistor Option Registers (PUn)
*/
/* Pn7 pin on-chip pull-up resistor selection (PUn7) */
#define _00_PUn7_PULLUP_OFF                     (0x00U)    /* Pn7 pull-up resistor not connected */
#define _80_PUn7_PULLUP_ON                      (0x80U)    /* Pn7 pull-up resistor connected */
/* Pn6 pin on-chip pull-up resistor selection (PUn6) */
#define _00_PUn6_PULLUP_OFF                     (0x00U)    /* Pn6 pull-up resistor not connected */
#define _40_PUn6_PULLUP_ON                      (0x40U)    /* Pn6 pull-up resistor connected */
/* Pn5 pin on-chip pull-up resistor selection (PUn5) */
#define _00_PUn5_PULLUP_OFF                     (0x00U)    /* Pn5 pull-up resistor not connected */
#define _20_PUn5_PULLUP_ON                      (0x20U)    /* Pn5 pull-up resistor connected */
/* Pn4 pin on-chip pull-up resistor selection (PUn4) */
#define _00_PUn4_PULLUP_OFF                     (0x00U)    /* Pn4 pull-up resistor not connected */
#define _10_PUn4_PULLUP_ON                      (0x10U)    /* Pn4 pull-up resistor connected */
/* Pn3 pin on-chip pull-up resistor selection (PUn3) */
#define _00_PUn3_PULLUP_OFF                     (0x00U)    /* Pn3 pull-up resistor not connected */
#define _08_PUn3_PULLUP_ON                      (0x08U)    /* Pn3 pull-up resistor connected */
/* Pn2 pin on-chip pull-up resistor selection (PUn2) */
#define _00_PUn2_PULLUP_OFF                     (0x00U)    /* Pn2 Pull-up resistor not connected */
#define _04_PUn2_PULLUP_ON                      (0x04U)    /* Pn2 pull-up resistor connected */
/* Pn1 pin on-chip pull-up resistor selection (PUn1) */
#define _00_PUn1_PULLUP_OFF                     (0x00U)    /* Pn1 pull-up resistor not connected */
#define _02_PUn1_PULLUP_ON                      (0x02U)    /* Pn1 pull-up resistor connected */
/* Pn0 pin on-chip pull-up resistor selection (PUn0) */
#define _00_PUn0_PULLUP_OFF                     (0x00U)    /* Pn0 pull-up resistor not connected */
#define _01_PUn0_PULLUP_ON                      (0x01U)    /* Pn0 pull-up resistor connected */

/*
    Port Input Mode Registers (PIMn)
*/
/* Pn7 pin input buffer selection (PIMn7) */
#define _00_PIMn7_TTL_OFF                       (0x00U)    /* Pn7 normal input buffer */
#define _80_PIMn7_TTL_ON                        (0x80U)    /* Pn7 TTL input buffer */
/* Pn6 pin input buffer selection (PIMn6) */
#define _00_PIMn6_TTL_OFF                       (0x00U)    /* Pn6 normal input buffer */
#define _40_PIMn6_TTL_ON                        (0x40U)    /* Pn6 TTL input buffer */
/* Pn5 pin input buffer selection (PIMn5) */
#define _00_PIMn5_TTL_OFF                       (0x00U)    /* Pn5 normal input buffer */
#define _20_PIMn5_TTL_ON                        (0x20U)    /* Pn5 TTL input buffer */
/* Pn4 pin input buffer selection (PIMn4) */
#define _00_PIMn4_TTL_OFF                       (0x00U)    /* Pn4 normal input buffer */
#define _10_PIMn4_TTL_ON                        (0x10U)    /* Pn4 TTL input buffer */
/* Pn3 pin input buffer selection (PIMn3) */
#define _00_PIMn3_TTL_OFF                       (0x00U)    /* Pn3 normal input buffer */
#define _08_PIMn3_TTL_ON                        (0x08U)    /* Pn3 TTL input buffer */
/* Pn2 pin input buffer selection (PIMn2) */
#define _00_PIMn2_TTL_OFF                       (0x00U)    /* Pn2 normal input buffer */
#define _04_PIMn2_TTL_ON                        (0x04U)    /* Pn2 TTL input buffer */
/* Pn1 pin input buffer selection (PIMn1) */
#define _00_PIMn1_TTL_OFF                       (0x00U)    /* Pn1 normal input buffer */
#define _02_PIMn1_TTL_ON                        (0x02U)    /* Pn1 TTL input buffer */
/* Pn0 pin input buffer selection (PIMn0) */
#define _00_PIMn0_TTL_OFF                       (0x00U)    /* Pn0 normal input buffer */
#define _01_PIMn0_TTL_ON                        (0x01U)    /* Pn0 TTL input buffer */

/*
    Port Output Mode Registers (POMn)
*/
/* Pn7 pin output mode selection (POMn7) */
#define _00_POMn7_NCH_OFF                       (0x00U)    /* Pn7 normal output mode */
#define _80_POMn7_NCH_ON                        (0x80U)    /* Pn7 N-ch open-drain output mode */
/* Pn6 pin output mode selection (POMn6) */
#define _00_POMn6_NCH_OFF                       (0x00U)    /* Pn6 normal output mode */
#define _40_POMn6_NCH_ON                        (0x40U)    /* Pn6 N-ch open-drain output mode */
/* Pn5 pin output mode selection (POMn5) */
#define _00_POMn5_NCH_OFF                       (0x00U)    /* Pn5 normal output mode */
#define _20_POMn5_NCH_ON                        (0x20U)    /* Pn5 N-ch open-drain output mode */
/* Pn4 pin output mode selection (POMn4) */
#define _00_POMn4_NCH_OFF                       (0x00U)    /* Pn4 normal output mode */
#define _10_POMn4_NCH_ON                        (0x10U)    /* Pn4 N-ch open-drain output mode */
/* Pn3 pin output mode selection (POMn3) */
#define _00_POMn3_NCH_OFF                       (0x00U)    /* Pn3 normal output mode */
#define _08_POMn3_NCH_ON                        (0x08U)    /* Pn3 N-ch open-drain output mode */
/* Pn2 pin output mode selection (POMn2) */
#define _00_POMn2_NCH_OFF                       (0x00U)    /* Pn2 normal output mode */
#define _04_POMn2_NCH_ON                        (0x04U)    /* Pn2 N-ch open-drain output mode */
/* Pn1 pin output mode selection (POMn1) */
#define _00_POMn1_NCH_OFF                       (0x00U)    /* Pn1 normal output mode */
#define _02_POMn1_NCH_ON                        (0x02U)    /* Pn1 N-ch open-drain output mode */
/* Pn0 pin output mode selection (POMn0) */
#define _00_POMn0_NCH_OFF                       (0x00U)    /* Pn0 normal output mode */
#define _01_POMn0_NCH_ON                        (0x01U)    /* Pn0 N-ch open-drain output mode */

/*
    Port Digital Input Disable Registers (PDIDISn)
*/
/* Pn7 setting of input buffers (PDIDISn7) */
#define _00_PDIDISn7_INPUT_BUFFER_ON            (0x00U)    /* Pn7 input to the input buffer is enabled */
#define _80_PDIDISn7_INPUT_BUFFER_OFF           (0x80U)    /* Pn7 input to the input buffer is disabled */
/* Pn6 setting of input buffers (PDIDISn6) */
#define _00_PDIDISn6_INPUT_BUFFER_ON            (0x00U)    /* Pn6 input to the input buffer is enabled */
#define _40_PDIDISn6_INPUT_BUFFER_OFF           (0x40U)    /* Pn6 input to the input buffer is disabled */
/* Pn5 setting of input buffers (PDIDISn5) */
#define _00_PDIDISn5_INPUT_BUFFER_ON            (0x00U)    /* Pn5 input to the input buffer is enabled */
#define _20_PDIDISn5_INPUT_BUFFER_OFF           (0x20U)    /* Pn5 input to the input buffer is disabled */
/* Pn4 setting of input buffers (PDIDISn4) */
#define _00_PDIDISn4_INPUT_BUFFER_ON            (0x00U)    /* Pn4 input to the input buffer is enabled */
#define _10_PDIDISn4_INPUT_BUFFER_OFF           (0x10U)    /* Pn4 input to the input buffer is disabled */
/* Pn3 setting of input buffers (PDIDISn3) */
#define _00_PDIDISn3_INPUT_BUFFER_ON            (0x00U)    /* Pn3 input to the input buffer is enabled */
#define _08_PDIDISn3_INPUT_BUFFER_OFF           (0x08U)    /* Pn3 input to the input buffer is disabled */
/* Pn2 setting of input buffers (PDIDISn2) */
#define _00_PDIDISn2_INPUT_BUFFER_ON            (0x00U)    /* Pn2 input to the input buffer is enabled */
#define _04_PDIDISn2_INPUT_BUFFER_OFF           (0x04U)    /* Pn2 input to the input buffer is disabled */
/* Pn1 setting of input buffers (PDIDISn1) */
#define _00_PDIDISn1_INPUT_BUFFER_ON            (0x00U)    /* Pn1 input to the input buffer is enabled */
#define _02_PDIDISn1_INPUT_BUFFER_OFF           (0x02U)    /* Pn1 input to the input buffer is disabled */
/* Pn0 setting of input buffers (PDIDISn0) */
#define _00_PDIDISn0_INPUT_BUFFER_ON            (0x00U)    /* Pn0 input to the input buffer is enabled */
#define _01_PDIDISn0_INPUT_BUFFER_OFF           (0x01U)    /* Pn0 input to the input buffer is disabled */

/*
    Port Mode Control A Registers (PMCAn)
*/
/* Selection of digital I/O or analog input for Pn7 (PMCAn7) */
#define _00_PMCAn7_DIGITAL_ON                   (0x00U)    /* digital I/O */
#define _80_PMCAn7_NOT_USE                      (0x80U)    /* analog input */
/* Selection of digital I/O or analog input for Pn6 (PMCAn6) */
#define _00_PMCAn6_DIGITAL_ON                   (0x00U)    /* digital I/O */
#define _40_PMCAn6_NOT_USE                      (0x40U)    /* analog input */
/* Selection of digital I/O or analog input for Pn5 (PMCAn5) */
#define _00_PMCAn5_DIGITAL_ON                   (0x00U)    /* digital I/O */
#define _20_PMCAn5_NOT_USE                      (0x20U)    /* analog input */
/* Selection of digital I/O or analog input for Pn4 (PMCAn4) */
#define _00_PMCAn4_DIGITAL_ON                   (0x00U)    /* digital I/O */
#define _10_PMCAn4_NOT_USE                      (0x10U)    /* analog input */
/* Selection of digital I/O or analog input for Pn3 (PMCAn3) */
#define _00_PMCAn3_DIGITAL_ON                   (0x00U)    /* digital I/O */
#define _08_PMCAn3_NOT_USE                      (0x08U)    /* analog input */
/* Selection of digital I/O or analog input for Pn2 (PMCAn2) */
#define _00_PMCAn2_DIGITAL_ON                   (0x00U)    /* digital I/O */
#define _04_PMCAn2_NOT_USE                      (0x04U)    /* analog input */
/* Selection of digital I/O or analog input for Pn1 (PMCAn1) */
#define _00_PMCAn1_DIGITAL_ON                   (0x00U)    /* digital I/O */
#define _02_PMCAn1_NOT_USE                      (0x02U)    /* analog input */
/* Selection of digital I/O or analog input for Pn0 (PMCAn0) */
#define _00_PMCAn0_DIGITAL_ON                   (0x00U)    /* digital I/O */
#define _01_PMCAn0_NOT_USE                      (0x01U)    /* analog input */

/*
    Port Mode Control T Registers (PMCTn)
*/
/* Selection of digital I/O or capacitance measurement for Pn7 (PMCTn7) */
#define _00_PMCTn7_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCTn7_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or capacitance measurement for Pn6 (PMCTn6) */
#define _00_PMCTn6_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCTn6_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or capacitance measurement for Pn5 (PMCTn5) */
#define _00_PMCTn5_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCTn5_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or capacitance measurement for Pn4 (PMCTn4) */
#define _00_PMCTn4_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCTn4_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or capacitance measurement for Pn3 (PMCTn3) */
#define _00_PMCTn3_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCTn3_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or capacitance measurement for Pn2 (PMCTn2) */
#define _00_PMCTn2_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCTn2_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or capacitance measurement for Pn1 (PMCTn1) */
#define _00_PMCTn1_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCTn1_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or capacitance measurement for Pn0 (PMCTn0) */
#define _00_PMCTn0_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCTn0_DIGITAL_ON                   (0x00U)    /* digital I/O */

/*
    Port Mode Control E Registers (PMCEn)
*/
/* Selection of digital I/O or ELCL output function for Pn7 (PMCEn7) */
#define _80_PMCEn7_ELCL_OUTPUT                  (0x80U)    /* ELCL output function */
#define _00_PMCEn7_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCEn7_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or ELCL output function for Pn6 (PMCEn6) */
#define _40_PMCEn6_ELCL_OUTPUT                  (0x40U)    /* ELCL output function */
#define _00_PMCEn6_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCEn6_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or ELCL output function for Pn5 (PMCEn5) */
#define _20_PMCEn5_ELCL_OUTPUT                  (0x20U)    /* ELCL output function */
#define _00_PMCEn5_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCEn5_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or ELCL output function for Pn4 (PMCEn4) */
#define _10_PMCEn4_ELCL_OUTPUT                  (0x10U)    /* ELCL output function */
#define _00_PMCEn4_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCEn4_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or ELCL output function for Pn3 (PMCEn3) */
#define _08_PMCEn3_ELCL_OUTPUT                  (0x08U)    /* ELCL output function */
#define _00_PMCEn3_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCEn3_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or ELCL output function for Pn2 (PMCEn2) */
#define _04_PMCEn2_ELCL_OUTPUT                  (0x04U)    /* ELCL output function */
#define _00_PMCEn2_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCEn2_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or ELCL output function for Pn1 (PMCEn1) */
#define _02_PMCEn1_ELCL_OUTPUT                  (0x02U)    /* ELCL output function */
#define _00_PMCEn1_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCEn1_DIGITAL_ON                   (0x00U)    /* digital I/O */
/* Selection of digital I/O or ELCL output function for Pn0 (PMCEn0) */
#define _01_PMCEn0_ELCL_OUTPUT                  (0x01U)    /* ELCL output function */
#define _00_PMCEn0_NOT_USE                      (0x00U)    /* not use digital I/O */
#define _00_PMCEn0_DIGITAL_ON                   (0x00U)    /* digital I/O */

/*
    Global Digital Input Disable Register (GDIDIS)
*/
/* Setting of input buffers using EVDD power supply (GDIDIS0) */
#define _00_GDIDIS0_INTPUT_BUFFERS_ON           (0x00U)    /* input to input buffers permitted */
#define _01_GDIDIS0_INTPUT_BUFFERS_OFF          (0x01U)    /* input to input buffers prohibited */

/*
    Output Current Control Enable Register (CCDE)
*/
/* Selection of digital I/O or output current control for CCD07 (CCDE07) */
#define _00_P63_OUTPUT_CURRENT_OFF              (0x00U)    /* digital I/O */
#define _80_P63_OUTPUT_CURRENT_ON               (0x80U)    /* current control function */
/* Selection of digital I/O or output current control for CCD06 (CCDE06) */
#define _00_P62_OUTPUT_CURRENT_OFF              (0x00U)    /* digital I/O */
#define _40_P62_OUTPUT_CURRENT_ON               (0x40U)    /* current control function */
/* Selection of digital I/O or output current control for CCD05 (CCDE05) */
#define _00_P61_OUTPUT_CURRENT_OFF              (0x00U)    /* digital I/O */
#define _20_P61_OUTPUT_CURRENT_ON               (0x20U)    /* current control function */
/* Selection of digital I/O or output current control for CCD04 (CCDE04) */
#define _00_P60_OUTPUT_CURRENT_OFF              (0x00U)    /* digital I/O */
#define _10_P60_OUTPUT_CURRENT_ON               (0x10U)    /* current control function */
/* Selection of digital I/O or output current control for CCD03 (CCDE03) */
#define _00_P50_OUTPUT_CURRENT_OFF              (0x00U)    /* digital I/O */
#define _08_P50_OUTPUT_CURRENT_ON               (0x08U)    /* current control function */
/* Selection of digital I/O or output current control for CCD02 (CCDE02) */
#define _00_P51_OUTPUT_CURRENT_OFF              (0x00U)    /* digital I/O */
#define _04_P51_OUTPUT_CURRENT_ON               (0x04U)    /* current control function */
/* Selection of digital I/O or output current control for CCD01 (CCDE01) */
#define _00_P17_OUTPUT_CURRENT_OFF              (0x00U)    /* digital I/O */
#define _02_P17_OUTPUT_CURRENT_ON               (0x02U)    /* current control function */
/* Selection of digital I/O or output current control for CCD00 (CCDE00) */
#define _00_P16_OUTPUT_CURRENT_OFF              (0x00U)    /* digital I/O */
#define _01_P16_OUTPUT_CURRENT_ON               (0x01U)    /* current control function */

/*
    Output Current Select Registers (CCSn)
*/
/* Setting of output current (CCSn2,CCSn1,CCSn0) */
#define _00_OUTPUT_CURRENT_HIZ                  (0x00U)    /* output current Hi-Z */
#define _01_OUTPUT_CURRENT_2mA                  (0x01U)    /* output current 2mA */
#define _02_OUTPUT_CURRENT_5mA                  (0x02U)    /* output current 5mA */
#define _03_OUTPUT_CURRENT_10mA                 (0x03U)    /* output current 10mA */
#define _04_OUTPUT_CURRENT_15mA                 (0x04U)    /* output current 15mA */

/*
    Port Overdrive Register (PTDC)
*/
/* Maximum load current when a low level is output from P120 (PTDC6) */
#define _00_P120_OUTPUT_MAX_CURRENT_20mA        (0x00U)    /* set P120 maximum load current 20mA */
#define _40_P120_OUTPUT_MAX_CURRENT_40mA        (0x40U)    /* set P120 maximum load current 40mA */
/* Maximum load current when a low level is output from P04 (PTDC5) */
#define _00_P04_OUTPUT_MAX_CURRENT_20mA         (0x00U)    /* set P04 maximum load current 20mA */
#define _20_P04_OUTPUT_MAX_CURRENT_40mA         (0x20U)    /* set P04 maximum load current 40mA */
/* Maximum load current when a low level is output from P101 (PTDC4) */
#define _00_P101_OUTPUT_MAX_CURRENT_20mA        (0x00U)    /* set P101 maximum load current 20mA */
#define _10_P101_OUTPUT_MAX_CURRENT_40mA        (0x10U)    /* set P101 maximum load current 40mA */
/* Maximum load current when a low level is output from P10 (PTDC3) */
#define _00_P10_OUTPUT_MAX_CURRENT_20mA         (0x00U)    /* set P10 maximum load current 20mA */
#define _08_P10_OUTPUT_MAX_CURRENT_40mA         (0x08U)    /* set P10 maximum load current 40mA */
/* Maximum load current when a low level is output from P17 (PTDC2) */
#define _00_P17_OUTPUT_MAX_CURRENT_20mA         (0x00U)    /* set P17 maximum load current 20mA */
#define _04_P17_OUTPUT_MAX_CURRENT_40mA         (0x04U)    /* set P17 maximum load current 40mA */
/* Maximum load current when a low level is output from P51 (PTDC1) */
#define _00_P51_OUTPUT_MAX_CURRENT_20mA         (0x00U)    /* set P51 maximum load current 20mA */
#define _02_P51_OUTPUT_MAX_CURRENT_40mA         (0x02U)    /* set P51 maximum load current 40mA */
/* Maximum load current when a low level is output from P70 (PTDC0) */
#define _00_P70_OUTPUT_MAX_CURRENT_20mA         (0x00U)    /* set P70 maximum load current 20mA */
#define _01_P70_OUTPUT_MAX_CURRENT_40mA         (0x01U)    /* set P70 maximum load current 40mA */

/*
    Port Function Output Enable Register 1 (PFOE1)
*/
/* CLKA0 pin output enable (PFOE15) */
#define _20_CLKA0_OUTPUT_ENABLED                (0x20U)    /* serial clock output to the CLKA0 pin is enabled */

/*
    Port Mode Select Register (PMS)
*/
/* Select the data read in output mode (PMS0) */
#define _00_PMN_VALUES                          (0x00U)    /* read Pmn register values */
#define _01_DIGITAL_OUTPUT_LEVEL                (0x01U)    /* read digital output level */

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


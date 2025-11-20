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
* File Name    : r_bsp_rl78_compiler.h
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.03.2021 1.00     First Release
*         : 22.04.2021 1.10     Added "__far" to the address of the option byte.
*         : 04.08.2021 1.12     Added include guard.
*         : 28.02.2022 1.20     Added macro definition for option byte(000C4H).
*         : 11.11.2022 1.40     Split lines with too many characters into two lines.
*         : 30.11.2023 1.62     Changed option byte comment.
***********************************************************************************************************************/

/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/

#ifndef R_RL78_COMPILER_H
#define R_RL78_COMPILER_H

/* Macro definition for option byte reference */
/* 000C0H or 040C0H
 * For details, please refer to the option byte chapter of the user's manual.
 */
#if defined(__CCRL__)
#define OPTBYTE_C0    (*(volatile __far unsigned char *)0x000C0)
#elif defined(__ICCRL78__)
#define OPTBYTE_C0    (*(volatile __far unsigned char *)0x000C0)
#elif defined(__llvm__)
#define OPTBYTE_C0    (*(volatile __far unsigned char *)0x000C0)
#endif

/* 000C1H or 040C1H
 * For details, please refer to the option byte chapter of the user's manual.
 */
#if defined(__CCRL__)
#define OPTBYTE_C1    (*(volatile __far unsigned char *)0x000C1)
#elif defined(__ICCRL78__)
#define OPTBYTE_C1    (*(volatile __far unsigned char *)0x000C1)
#elif defined(__llvm__)
#define OPTBYTE_C1    (*(volatile __far unsigned char *)0x000C1)
#endif

/* 000C2H or 040C2H
 * For details, please refer to the option byte chapter of the user's manual.
 */
#if defined(__CCRL__)
#define OPTBYTE_C2    (*(volatile __far unsigned char *)0x000C2)
#elif defined(__ICCRL78__)
#define OPTBYTE_C2    (*(volatile __far unsigned char *)0x000C2)
#elif defined(__llvm__)
#define OPTBYTE_C2    (*(volatile __far unsigned char *)0x000C2)
#endif

/* 000C3H or 040C3H
 * For details, please refer to the option byte chapter of the user's manual.
 */
#if defined(__CCRL__)
#define OPTBYTE_C3    (*(volatile __far unsigned char *)0x000C3)
#elif defined(__ICCRL78__)
#define OPTBYTE_C3    (*(volatile __far unsigned char *)0x000C3)
#elif defined(__llvm__)
#define OPTBYTE_C3    (*(volatile __far unsigned char *)0x000C3)
#endif

/* 000C4H or 040C4H
 * For details, please refer to the option byte chapter of the user's manual.
 */
#if defined(__CCRL__)
#define OPTBYTE_C4    (*(volatile __far unsigned char *)0x000C4)
#elif defined(__ICCRL78__)
#define OPTBYTE_C4    (*(volatile __far unsigned char *)0x000C4)
#elif defined(__llvm__)
#define OPTBYTE_C4    (*(volatile __far unsigned char *)0x000C4)
#endif

#if defined(__CCRL__)
#define BSP_FAR_FUNC               __far
#define BSP_NOP()                  __nop()    /* NOP instruction */
#define BSP_DISABLE_INTERRUPT()    __DI()
#define BSP_ENABLE_INTERRUPT()     __EI()
#elif defined(__ICCRL78__)
#define BSP_FAR_FUNC               __far_func
#define BSP_NOP()                  __no_operation()
#define BSP_DISABLE_INTERRUPT()    __disable_interrupt()
#define BSP_ENABLE_INTERRUPT()     __enable_interrupt()
#elif defined(__llvm__)
#define BSP_NOP()                  NOP()
#define BSP_DISABLE_INTERRUPT()    DI()
#define BSP_ENABLE_INTERRUPT()     EI()
#endif

/* Sections */
#if defined(__CCRL__)
#define R_BSP_SECTOP(name)         __sectop(#name)
#define R_BSP_SECEND(name)         __secend(#name)
#define R_BSP_SECSIZE(name)        __secsize(#name)
#elif defined(__ICCRL78__)
#elif defined(__llvm__)
#endif

/* ========== #pragma Directive ========== */
#if defined(__CCRL__)
#define R_BSP_PRAGMA(...)                                      _Pragma(#__VA_ARGS__)
/* Define __R_BSP_ATTRIB_SECTION_CHANGE_ */
#define __R_BSP_ATTRIB_SECTION_CHANGE_F(type, section_name)    R_BSP_PRAGMA(section (type) (section_name))
#define _R_BSP_ATTRIB_SECTION_CHANGE_text(section_tag)         __R_BSP_ATTRIB_SECTION_CHANGE_F(text, ##section_tag)
#define _R_BSP_ATTRIB_SECTION_CHANGE_data(section_tag)         __R_BSP_ATTRIB_SECTION_CHANGE_F(data, ##section_tag)
#define R_BSP_ATTRIB_SECTION_CHANGE(type, section_tag)         _R_BSP_ATTRIB_SECTION_CHANGE_##type(section_tag)
#define R_BSP_ATTRIB_SECTION_CHANGE_END                        R_BSP_PRAGMA(section)
#elif defined(__ICCRL78__)
#define R_BSP_PRAGMA(...)                                      _Pragma(#__VA_ARGS__)
#elif defined(__llvm__)
#endif

/* ---------- Interrupt Function Creation ---------- */
#if defined(__CCRL__)
/* Standard */
#define R_BSP_PRAGMA_INTERRUPT(function_name, vector)           R_BSP_PRAGMA(interrupt function_name(vect=vector))\
                                                                extern void function_name(void);
#define R_BSP_PRAGMA_STATIC_INTERRUPT(function_name, vector)    R_BSP_PRAGMA(interrupt function_name(vect=vector))\
                                                                static void function_name(void);
#define R_BSP_ATTRIB_INTERRUPT                                  extern
#define R_BSP_ATTRIB_STATIC_INTERRUPT                           static

#elif defined(__ICCRL78__)
/* Standard */
#define R_BSP_PRAGMA_INTERRUPT(function_name, vect)             R_BSP_PRAGMA(vector=vect)\
                                                                extern __interrupt void function_name(void);
#define R_BSP_PRAGMA_STATIC_INTERRUPT(function_name, vect)      R_BSP_PRAGMA(vector=vect)\
                                                                static __interrupt void function_name(void);
#define R_BSP_ATTRIB_INTERRUPT                                  extern __interrupt
#define R_BSP_ATTRIB_STATIC_INTERRUPT                           static __interrupt

#elif defined(__llvm__)
/* R_BSP_PRAGMA_INTERRUPT */
#define R_BSP_PRAGMA_INTERRUPT(function_name, vector)           extern void function_name(void) \
                                                                __attribute__((interrupt(vect=vector), used));
#define R_BSP_PRAGMA_STATIC_INTERRUPT(function_name, vector)    static void function_name(void) \
                                                                __attribute__((interrupt(vect=vector), used));
#define R_BSP_ATTRIB_INTERRUPT                                  extern
#define R_BSP_ATTRIB_STATIC_INTERRUPT                           static
#endif

#endif /* R_RL78_COMPILER_H */


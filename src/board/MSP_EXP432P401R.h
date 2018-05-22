/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       MSP_EXP432P401R.h
 *
 *  @brief      MSP_EXP432P401R Board Specific APIs
 *
 *  The MSP_EXP432P401R header file should be included in an application as
 *  follows:
 *  @code
 *  #include <MSP_EXP432P401R.h>
 *  @endcode
 *
 *  ============================================================================
 */
#ifndef __MSP_EXP432P401R_H
#define __MSP_EXP432P401R_H

#ifdef __cplusplus
extern "C" {
#endif

/*!
 *  @def    MSP_EXP432P401R_SDFatFSName
 *  @brief  Enum of SDFatFS names on the MSP_EXP432P401R dev board
 */
typedef enum MSP_EXP432P401R_SDFatFSName {
    MSP_EXP432P401R_SDFatFS0 = 0,

    MSP_EXP432P401R_SDFatFSCOUNT
} MSP_EXP432P401R_SDFatFSName;

/*!
 *  @def    MSP_EXP432P401R_SDName
 *  @brief  Enum of SD names on the MSP_EXP432P401R dev board
 */
typedef enum MSP_EXP432P401R_SDName {
    MSP_EXP432P401R_SDSPI0 = 0,

    MSP_EXP432P401R_SDCOUNT
} MSP_EXP432P401R_SDName;

/*!
 *  @def    MSP_EXP432P401R_CaptureName
 *  @brief  Enum of Capture timer names on the MSP_EXP432P401R dev board
 */
typedef enum MSP_EXP432P401R_CaptureName {
    MSP_EXP432P401R_CAPTURE_TA1 = 0,
    MSP_EXP432P401R_CAPTURE_TA2,
    MSP_EXP432P401R_CAPTURE_TA3,

    MSP_EXP432P401R_CAPTURECOUNT
} MSP_EXP432P401R_CaptureName;

/*!
 *  @def    MSP_EXP432P401R_GPIOName
 *  @brief  Enum of GPIO names on the MSP_EXP432P401R dev board
 */
typedef enum Board_GPIOName {
    INT1_P_CDH = 0,
    INT2_P_CDH = 1,
    ENABLE_P_CDH = 2,
    INT_CDH_CMS = 3,
    BYP1_CDH_CMS = 4,
    BYP2_CDH_CMS = 5,
    RESET_CDH_CMS = 6,
    X_Mag_DIR_CDH_FS = 7,
    Y_Mag_DIR_CDH_FS = 8,
    Z_Mag_DIR_CDH_FS = 9,
    NVM_nCS = 10,
    HEARTBEAT_LED = 11,
    NVM_nCS_1 = 12,
    NVM_nCS_2 = 13,
    NVM_nCS_3 = 14,
    INT_MCU_MCU_1 = 15,
    INT_MCU_MCU_2 = 16,
    BUS_SWITCH_ENABLE = 17,
    // Used for the purposes of I2C bus sensing. Should not be used except in
    // the I2c driver.
    I2C_BUS_A_SCL = 18,
    I2C_BUS_A_SDA = 19,
    I2C_BUS_B_SCL = 20,
    I2C_BUS_B_SDA = 21,
    I2C_BUS_C_SCL = 22,
    I2C_BUS_C_SDA = 23,
    I2C_BUS_D_SCL = 24,
    I2C_BUS_D_SDA = 25,
    Board_GPIOCOUNT
} Board_GPIOName;

/*!
 *  @def    MSP_EXP432P401R_I2CName
 *  @brief  Enum of I2C names on the MSP_EXP432P401R dev board
 */
typedef enum Board_I2CName {
    I2C_BUS_A = 0,
    I2C_BUS_B = 1,
    I2C_BUS_C = 2,
    I2C_BUS_D = 3,
    Board_I2CCOUNT
} Board_I2CName;

/*!
 *  @def    MSP_EXP432P401R_PWMName
 *  @brief  Enum of PWM names on the MSP_EXP432P401R dev board
 */
typedef enum Board_PWMName {
    Mag_STR_CDH_FS_Out1 = 0,
    Mag_STR_CDH_FS_Out2 = 1,
    Mag_STR_CDH_FS_Out3 = 2,

    Board_PWMCOUNT
} Board_PWMName;

/*!
 *  @def    MSP_EXP432P401R_SPIName
 *  @brief  Enum of SPI names on the MSP_EXP432P401R dev board
 */
typedef enum Board_SPIName { NVM = 0, Board_SPICOUNT } Board_SPIName;

/*!
 *  @def    MSP_EXP432P401R_TimerName
 *  @brief  Enum of Timer names on the MSP_EXP432P401R dev board
 */
typedef enum MSP_EXP432P401R_TimerName {
    MSP_EXP432P401R_TIMER_T32_0 = 0,
    MSP_EXP432P401R_TIMER_T32_1,
    MSP_EXP432P401R_TIMER_TA_1,
    MSP_EXP432P401R_TIMER_TA_2,
    MSP_EXP432P401R_TIMER_TA_3,

    MSP_EXP432P401R_TIMERCOUNT
} MSP_EXP432P401R_TimerName;

/*!
 *  @def    MSP_EXP432P401R_UARTName
 *  @brief  Enum of UART names on the MSP_EXP432P401R dev board
 */
typedef enum Board_UARTName {
    UART_MCU_MCU = 0,
    UART_CDH_UMB = 1,
    UART_CMS_CDH = 2,
    Board_UARTCOUNT
} Board_UARTName;

/*!
 *  @def    MSP_EXP432P401R_WatchdogName
 *  @brief  Enum of Watchdog names on the MSP_EXP432P401R dev board
 */
typedef enum MSP_EXP432P401R_WatchdogName {
    MSP_EXP432P401R_WATCHDOG = 0,

    MSP_EXP432P401R_WATCHDOGCOUNT
} MSP_EXP432P401R_WatchdogName;

/*!
 *  @brief  Initialize the general board specific settings
 *
 *  This function initializes the general board specific settings.
 */
extern void MSP_EXP432P401R_initGeneral(void);

#ifdef __cplusplus
}
#endif

#endif /* __MSP_EXP432P401R_H */
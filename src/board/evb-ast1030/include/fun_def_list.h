/*
 * Copyright (c) 2020-2021 Aspeed Technology Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "config.h"

#ifdef CONFIG_STDIO_UART
#if (CONFIG_STDIO_UART == 10)
FUN_DEFINE(UART10, TXD11, RXD11)
#endif
#endif

#ifdef CONFIG_ARM_ICE
FUN_DEFINE(ARM_ICE, ARM_TRST, ARM_TCK, ARM_TDI, ARM_TDO, ARM_TMS)
#endif

#ifdef CONFIG_DEVICE_ADC
FUN_DEFINE(ADC0, ADC0)
FUN_DEFINE(ADC1, ADC1)
FUN_DEFINE(ADC2, ADC2)
FUN_DEFINE(ADC3, ADC3)
FUN_DEFINE(ADC4, ADC4)
FUN_DEFINE(ADC5, ADC5)
FUN_DEFINE(ADC6, ADC6)
FUN_DEFINE(ADC7, ADC7)
#endif /* end of "#if CONFIG_DEVICE_ADC" */

#ifdef CONFIG_DEVICE_PWM_TACH
FUN_DEFINE(PWM0, PWM0)
FUN_DEFINE(PWM1, PWM1)
FUN_DEFINE(PWM2, PWM2)
FUN_DEFINE(PWM3, PWM3)
FUN_DEFINE(TACH0, TACH0)
FUN_DEFINE(TACH1, TACH1)
FUN_DEFINE(TACH2, TACH2)
FUN_DEFINE(TACH3, TACH3)
FUN_DEFINE(TACH4, TACH4)
FUN_DEFINE(TACH5, TACH5)
FUN_DEFINE(TACH6, TACH6)
FUN_DEFINE(TACH7, TACH7)
FUN_DEFINE(TACH8, TACH8)
#endif

#ifdef CONFIG_DEVICE_JTAG
FUN_DEFINE(JTAGM1, MTRSTN2, MTDI2, MTCK2, MTMS2, MTDO2)
#endif

#ifdef CONFIG_DEVICE_GPIO
#endif

#ifdef CONFIG_DEVICE_SGPIOM
FUN_DEFINE(SGPIOM, SGPMCLK, SGPMLD, SGPMO, SGPMI)
#endif

#ifdef CONFIG_DEVICE_I3C
FUN_DEFINE(HVI3C0, HVI3C1SCL, HVI3C1SDA)
FUN_DEFINE(HVI3C1, HVI3C2SCL, HVI3C2SDA)
#endif

#ifdef CONFIG_DEVICE_I2C

FUN_DEFINE(I2C0, SCL1, SDA1)
FUN_DEFINE(I2C1, SCL2, SDA2)
FUN_DEFINE(I2C2, SCL3, SDA3)
FUN_DEFINE(I2C3, SCL4, SDA4)
FUN_DEFINE(I2C4, SCL5, SDA5)
FUN_DEFINE(I2C5, SCL6, SDA6)
FUN_DEFINE(I2C8, SCL9, SDA9)
FUN_DEFINE(I2C9, SCL10, SDA10)
#endif

#if CONFIG_DEVICE_FMC_SPI
FUN_DEFINE(FWSPIQ, FWSPIQ2, FWSPIQ3)
#endif

#if CONFIG_DEVICE_FMC_SPI
FUN_DEFINE(SPI1Q, SPI1DQ2, SPI1DQ3)
#endif

#if CONFIG_DEVICE_FMC_SPI
FUN_DEFINE(SPI2, SPI2CS0, SPI2CS1, SPI2CK, SPI2DQ0, SPI2DQ1)
FUN_DEFINE(SPI2Q, SPI2DQ2, SPI2DQ3)
#endif

#if CONFIG_DEVICE_MDIO
FUN_DEFINE(MDIO0, MDC, MDIO)
#endif

#ifndef __DEVICE_H__
#define __DEVICE_H__

/* peripheral device ID */
typedef enum {
	/* UART */
	ASPEED_DEV_UART0 = 0,
	ASPEED_DEV_UART1,
	ASPEED_DEV_UART2,
	ASPEED_DEV_UART3,
	ASPEED_DEV_UART4,
	ASPEED_DEV_UART5,
	ASPEED_DEV_UART6,
	ASPEED_DEV_UART7,
	ASPEED_DEV_UART8,
	ASPEED_DEV_UART9,
	ASPEED_DEV_UART10,
	ASPEED_DEV_UART11,
	ASPEED_DEV_UART12,
	ASPEED_DEV_UART_NUM,

	/* GPIO */
	ASPEED_DEV_GPIO0,
	ASPEED_DEV_GPIO1,

	/* SGPIOM */
	ASPEED_DEV_SGPIOM0,
	ASPEED_DEV_SGPIOM1,
	
	/* I2C */
	ASPEED_DEV_I2C_GLOBAL,
	ASPEED_DEV_I2C0,
	ASPEED_DEV_I2C1,
	ASPEED_DEV_I2C2,
	ASPEED_DEV_I2C3,
	ASPEED_DEV_I2C4,
	ASPEED_DEV_I2C5,
	ASPEED_DEV_I2C6,
	ASPEED_DEV_I2C7,
	ASPEED_DEV_I2C8,
	ASPEED_DEV_I2C9,
	ASPEED_DEV_I2C10,
	ASPEED_DEV_I2C11,
	ASPEED_DEV_I2C12,
	ASPEED_DEV_I2C13,
	ASPEED_DEV_I2C14,
	ASPEED_DEV_I2C15,
	
	/* secure I2C */
	ASPEED_DEV_I2CSEC_GLOBAL,
	ASPEED_DEV_I2CSEC0,
	ASPEED_DEV_I2CSEC1,
	ASPEED_DEV_I2CSEC2,
	ASPEED_DEV_I2CSEC3,
	
	/* I3C */
	ASPEED_DEV_I3C_GLOBAL,
	ASPEED_DEV_I3C0,
	ASPEED_DEV_I3C1,
	ASPEED_DEV_I3C2,
	ASPEED_DEV_I3C3,
	ASPEED_DEV_I3C4,
	ASPEED_DEV_I3C5,
	ASPEED_DEV_I3C_NUM,

	/* IPI (inter-processor interrupt) */
	ASPEED_DEV_IPI,

	/* ESPI */
	ASPEED_DEV_ESPI,

    /* PECI */
    ASPEED_DEV_PECI,

	/* PWM/Tach */
    ASPEED_DEV_G_PWM_TACH,
	ASPEED_DEV_PWM0,
	ASPEED_DEV_PWM1,
	ASPEED_DEV_PWM2,
	ASPEED_DEV_PWM3,
	ASPEED_DEV_PWM4,
	ASPEED_DEV_PWM5,
	ASPEED_DEV_PWM6,
	ASPEED_DEV_PWM7,
	ASPEED_DEV_PWM8,
	ASPEED_DEV_PWM9,
	ASPEED_DEV_PWM10,
	ASPEED_DEV_PWM11,
	ASPEED_DEV_PWM12,
	ASPEED_DEV_PWM13,
	ASPEED_DEV_PWM14,
	ASPEED_DEV_PWM15,
	ASPEED_DEV_TACH0,
	ASPEED_DEV_TACH1,
	ASPEED_DEV_TACH2,
	ASPEED_DEV_TACH3,
	ASPEED_DEV_TACH4,
	ASPEED_DEV_TACH5,
	ASPEED_DEV_TACH6,
	ASPEED_DEV_TACH7,
	ASPEED_DEV_TACH8,
	ASPEED_DEV_TACH9,
	ASPEED_DEV_TACH10,
	ASPEED_DEV_TACH11,
	ASPEED_DEV_TACH12,
	ASPEED_DEV_TACH13,
	ASPEED_DEV_TACH14,
	ASPEED_DEV_TACH15,

	/* ADC */
	ASPEED_DEV_G_ADC,
	ASPEED_DEV_ADC0,
	ASPEED_DEV_ADC1,
	/* JTAG */
	ASPEED_DEV_JTAG0,
	ASPEED_DEV_JTAG1,

	/* KCS */
	ASPEED_DEV_KCS1,
	ASPEED_DEV_KCS2,
	ASPEED_DEV_KCS3,
	ASPEED_DEV_KCS4,

	/* BT */
	ASPEED_DEV_BT,

	/* Snoop */
	ASPEED_DEV_SNOOP,

	/* PCC */
	ASPEED_DEV_PCC,

	/* UDC */
	ASPEED_DEV_USB,

	/* timer */
	ASPEED_DEV_TMC0,
	ASPEED_DEV_TMC1,
	ASPEED_DEV_TMC2,
	ASPEED_DEV_TMC3,
	ASPEED_DEV_TMC4,
	ASPEED_DEV_TMC5,
	ASPEED_DEV_TMC6,
	ASPEED_DEV_TMC7,

	/* mdio */
	ASPEED_DEV_MDIO0,
	ASPEED_DEV_MDIO1,
	ASPEED_DEV_MDIO2,
	ASPEED_DEV_MDIO3,

	/* mac */
	ASPEED_DEV_MAC0,
	ASPEED_DEV_MAC1,
	ASPEED_DEV_MAC2,
	ASPEED_DEV_MAC3,

	/* fmc_spi */
	ASPEED_DEV_FMC,
	ASPEED_DEV_SPI1,
	ASPEED_DEV_SPI2,

	/* i3c hdma */
	ASPEED_DEV_I3CDMA,

} ASPEED_DEV_ID;

#endif /* #ifndef __DEVICE_H__ */

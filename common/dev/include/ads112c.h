#ifndef ADS112C_H
#define ADS112C_H

enum ADS112C_REG0_CONFIG {
	//Input multiplexer configuration(Bit 7:4)
	ADS112C_REG0_INPUT_AIN0AIN1 = 0x00, //AINP = AIN0, AINN = AIN1(default)
	ADS112C_REG0_INPUT_AIN0AIN2 = 0x10, //AINP = AIN0, AINN = AIN2
	ADS112C_REG0_INPUT_AIN0AIN3 = 0x20, //AINP = AIN0, AINN = AIN3
	ADS112C_REG0_INPUT_AIN1AIN0 = 0x30, //AINP = AIN1, AINN = AIN0
	ADS112C_REG0_INPUT_AIN1AIN2 = 0x40, //AINP = AIN1, AINN = AIN2
	ADS112C_REG0_INPUT_AIN1AIN3 = 0x50, //AINP = AIN1, AINN = AIN3
	ADS112C_REG0_INPUT_AIN2AIN3 = 0x60, //AINP = AIN2, AINN = AIN3
	ADS112C_REG0_INPUT_AIN3AIN2 = 0x70, //AINP = AIN3, AINN = AIN2
	ADS112C_REG0_INPUT_AIN0AVSS = 0x80, //AINP = AIN0, AINN = AVSS
	ADS112C_REG0_INPUT_AIN1AVSS = 0x90, //AINP = AIN1, AINN = AVSS
	ADS112C_REG0_INPUT_AIN2AVSS = 0xA0, //AINP = AIN2, AINN = AVSS
	ADS112C_REG0_INPUT_AIN3AVSS = 0xB0, //AINP = AIN3, AINN = AVSS
	//Gain configuration(Bit 3:1)
	ADS112C_REG0_GAIN1 = 0x00, //Gain = 1 (default)
	ADS112C_REG0_GAIN2 = 0x02,
	ADS112C_REG0_GAIN4 = 0x04,
	ADS112C_REG0_GAIN8 = 0x06,
	ADS112C_REG0_GAIN16 = 0x08,
	ADS112C_REG0_GAIN32 = 0x0A,
	ADS112C_REG0_GAIN64 = 0x0C,
	ADS112C_REG0_GAIN128 = 0x0E,
	//Disables and bypasses the internal low-noise PGA (Bit 0)
	ADS112C_REG0_PGA_ENABLE = 0x00,
	ADS112C_REG0_PGA_DISABLE = 0x01,
};

enum ADS112C_REG1_CONFIG {
	//Data rate (Bit 5:7)
	ADS112C_REG1_DR_1000_SPS = 0xC0,
	//Conversion mode. (Bit 3)
	ADS112C_REG1_SINGLEMODE = 0x00,
	ADS112C_REG1_CONTINUEMODE = 0x08,
	//Voltage reference selection. (Bit 2:1)
	ADS112C_REG1_INTERNALV = 0x00,
	ADS112C_REG1_EXTERNALV = 0x02,
	//Temperature sensor mode. (Bit 0)
	ADS112C_REG1_TEMPMODE_DISABLE = 0x00,
	ADS112C_REG1_TEMPMODE_ENABLE = 0x01,
};

enum ADS112C_REG2_CONFIG {
	//IDAC current setting (Bit 2:0)
	ADS112C_REG2_IDAC_OFF = 0x00,
	ADS112C_REG2_IDAC_10UA = 0x01,
	ADS112C_REG2_IDAC_50UA = 0x02,
	ADS112C_REG2_IDAC_100UA = 0x03,
	ADS112C_REG2_IDAC_250UA = 0x04,
	ADS112C_REG2_IDAC_500UA = 0x05,
	ADS112C_REG2_IDAC_1000UA = 0x06,
	ADS112C_REG2_IDAC_1500UA = 0x07,
};

enum ADS112C_REG3_CONFIG {
	//IDAC1 routing configuration (Bit 7:5)
	ADS112C_REG3_IDAC1_DISABLED = 0x00,
	ADS112C_REG3_IDAC1_AIN0 = 0x20,
	ADS112C_REG3_IDAC1_AIN1 = 0x40,
	ADS112C_REG3_IDAC1_AIN2 = 0x60,
	ADS112C_REG3_IDAC1_AIN3 = 0x80,
	ADS112C_REG3_IDAC1_REFP = 0xA0,
	ADS112C_REG3_IDAC1_REFN = 0xC0,
	ADS112C_REG3_IDAC1_RESERVED = 0xE0,
};

// Command Byte to control device
#define CMD_RESET 0x06 //000 011x(06h)
#define CMD_START_SYNC 0x08 //000 100x(08h)
#define CMD_POWERDOWN 0x02 //000 001x(08h)
#define CMD_RDATA 0x10 //001 000x(10h)
#define CMD_RREG 0x20 //010 000x(20h)
#define CMD_WREG 0x40 //100 000x(40h)

// Configuration Registers offset
#define CFG_REG_OFFSET0 0x00
#define CFG_REG_OFFSET1 0x04
#define CFG_REG_OFFSET2 0x08
#define CFG_REG_OFFSET3 0x0C

#define ADS112C_REG2_DRDY_READY 0x80
#define ENABLE_RESET_CFG_REG 1
#define DISABLE_RESET_CFG_REG 0

typedef struct _ads112c_init_arg {
	uint8_t reg0_input;
	uint8_t reg0_gain;
	uint8_t reg0_pga;
	uint8_t reg1_dr;
	uint8_t reg1_conversion;
	uint8_t reg1_vol_refer;
	double vol_refer_val;
	uint8_t reg1_temp_mode;
	uint8_t reg2_idac;
	uint8_t reg3_idac1_cfg;
} ads112c_init_arg;

enum ADS112C_READ_OUTPUT_OFFSET {
	ADS112C_READ_OUTPUT_RAW = 0x00,
	ADS112C_READ_OUTPUT_VOLT = 0x01,
	ADS112C_READ_OUTPUT_TEMP = 0x02,
};

#endif //ADS112C_H

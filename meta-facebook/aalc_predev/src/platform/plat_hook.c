/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <string.h>
#include <logging/log.h>
#include "plat_hook.h"
#include "plat_class.h"
<<<<<<< HEAD
#include "ads112c.h"
=======
#include "plat_i2c.h"
#include "sensor.h"
>>>>>>> 96340ac

LOG_MODULE_REGISTER(plat_hook);

struct k_mutex i2c_1_PCA9546a_mutex;
struct k_mutex i2c_2_PCA9546a_mutex;
struct k_mutex i2c_6_pca9546a_mutex;
struct k_mutex i2c_7_PCA9546a_mutex;
struct k_mutex i2c_8_PCA9546a_mutex;
struct k_mutex i2c_9_PCA9546a_mutex;

/**************************************************************************************************
 * INIT ARGS
**************************************************************************************************/
adm1272_init_arg adm1272_init_args[] = {
	[0] = { .is_init = false,
		.is_need_set_pwr_cfg = true,
		.pwr_monitor_cfg.value = 0x3F3F,
		.r_sense_mohm = 0.3,
		.is_record_ein = false,
		.last_energy = 0,
		.last_rollover = 0,
		.last_sample = 0,
	},
	[1] = { .is_init = false,
		.is_need_set_pwr_cfg = true,
		.pwr_monitor_cfg.value = 0x3F3F,
		.r_sense_mohm = 0.3,
		.is_record_ein = false,
		.last_energy = 0,
		.last_rollover = 0,
		.last_sample = 0,
	},
};

nct7363_init_arg nct7363_init_args[] = {
    //GPIO setting: Reserved=11, FANINx=10, PWMx=01, GPIOXX=00
    //Fan BD
    [0] = { 
        .is_init = false, 
            .init_pin_config = {
                .GPIO_14_to_17_Pin_Function_Configuration = 0b01001000,
                .GPIO0x_Input_Output_Configuration = 0b00000100,
                .GPIO1x_Input_Output_Configuration = 0b11111100,
                .PWM_8_to_15_Enable = 0b10000000,
                .FANIN_0_to_7_Monitoring_Enable = 0b00100000,
            },
        .fan_poles = 0,
    },	
    // Management BD(no used)
    [1] = { 
        .is_init = false,
            .init_pin_config = {
                .GPIO_00_to_03_Pin_Function_Configuration = 0b00101001,
                .GPIO0x_Input_Output_Configuration = 0b11101111,
                .GPIO1x_Input_Output_Configuration = 0b11111111,
                .PWM_0_to_7_Enable = 0b00000001,
                .FANIN_8_to_15_Monitoring_Enable = 0b00000110,
            },
        .fan_poles = 0,
    },
    //Backplane BD
    [2] = { 
        .is_init = false,
            .init_pin_config = {
                .GPIO_00_to_03_Pin_Function_Configuration = 0b10010101,
                .GPIO_04_to_07_Pin_Function_Configuration = 0b00000000,
                .GPIO0x_Input_Output_Configuration = 0b11111111,
                .GPIO1x_Input_Output_Configuration = 0b00000000,
                .PWM_0_to_7_Enable = 0b00000111,
                .FANIN_8_to_15_Monitoring_Enable = 0b00001000,
            },
        .fan_poles = 0,
    },
    //Pump BD
    [3] = { 
        .is_init = false,
            .init_pin_config = {
                .GPIO_00_to_03_Pin_Function_Configuration = 0b00000101,
                .GPIO_04_to_07_Pin_Function_Configuration = 0b00101010,
                .GPIO0x_Input_Output_Configuration = 0b11111111,
                .GPIO1x_Input_Output_Configuration = 0b11111100,
                .PWM_0_to_7_Enable = 0b00000011,
                .FANIN_8_to_15_Monitoring_Enable = 0b01110000,
            },
        .fan_poles = 0,
    },
};

ads112c_init_arg ads112c_init_args[] = {
	[0] = { .reg0_input = ADS112C_REG0_INPUT_AIN0AVSS,
		.reg0_gain = ADS112C_REG0_GAIN1,
		.reg0_pga = ADS112C_REG0_PGA_ENABLE,
		.reg1_conversion = ADS112C_REG1_CONTINUEMODE,
		.reg1_vol_refer = ADS112C_REG1_EXTERNALV,
	},
	[1] = { .reg0_input = ADS112C_REG0_INPUT_AIN1AVSS,
		.reg0_gain = ADS112C_REG0_GAIN1,
		.reg0_pga = ADS112C_REG0_PGA_ENABLE,
		.reg1_conversion = ADS112C_REG1_CONTINUEMODE,
		.reg1_vol_refer = ADS112C_REG1_EXTERNALV,
	},    
	[2] = { .reg0_input = ADS112C_REG0_INPUT_AIN2AVSS,
		.reg0_gain = ADS112C_REG0_GAIN1,
		.reg0_pga = ADS112C_REG0_PGA_ENABLE,
		.reg1_conversion = ADS112C_REG1_CONTINUEMODE,
		.reg1_vol_refer = ADS112C_REG1_EXTERNALV,
	},
	[3] = { .reg0_input = ADS112C_REG0_INPUT_AIN3AVSS,
		.reg0_gain = ADS112C_REG0_GAIN1,
		.reg0_pga = ADS112C_REG0_PGA_ENABLE,
		.reg1_conversion = ADS112C_REG1_CONTINUEMODE,
		.reg1_vol_refer = ADS112C_REG1_EXTERNALV,
	},
};
/**************************************************************************************************
 *  PRE-HOOK/POST-HOOK ARGS
 **************************************************************************************************/
mux_config bus_1_PCA9546A_configs[] = {
	[0] = { .target_addr = 0xE0, .channel = PCA9546A_CHANNEL_0 },
	[1] = { .target_addr = 0xE0, .channel = PCA9546A_CHANNEL_1 },
	[2] = { .target_addr = 0xE0, .channel = PCA9546A_CHANNEL_2 },
	[3] = { .target_addr = 0xE0, .channel = PCA9546A_CHANNEL_3 },
};
mux_config bus_2_PCA9546A_configs[] = {
	[0] = { .target_addr = 0xE2, .channel = PCA9546A_CHANNEL_0 },
	[1] = { .target_addr = 0xE2, .channel = PCA9546A_CHANNEL_1 },
	[2] = { .target_addr = 0xE2, .channel = PCA9546A_CHANNEL_2 },
	[3] = { .target_addr = 0xE2, .channel = PCA9546A_CHANNEL_3 },
};
mux_config bus_6_PCA9546A_configs[] = {
	[0] = { .target_addr = 0xE4, .channel = PCA9546A_CHANNEL_0 },
	[1] = { .target_addr = 0xE4, .channel = PCA9546A_CHANNEL_1 },
	[2] = { .target_addr = 0xE4, .channel = PCA9546A_CHANNEL_2 },
	[3] = { .target_addr = 0xE4, .channel = PCA9546A_CHANNEL_3 },
};
mux_config bus_7_PCA9546A_configs[] = {
	[0] = { .target_addr = 0xE6, .channel = PCA9546A_CHANNEL_0 },
	[1] = { .target_addr = 0xE6, .channel = PCA9546A_CHANNEL_1 },
	[2] = { .target_addr = 0xE6, .channel = PCA9546A_CHANNEL_2 },
	[3] = { .target_addr = 0xE6, .channel = PCA9546A_CHANNEL_3 },
};
mux_config bus_8_PCA9546A_configs[] = {
	[0] = { .target_addr = 0xE8, .channel = PCA9546A_CHANNEL_0 },
	[1] = { .target_addr = 0xE8, .channel = PCA9546A_CHANNEL_1 },
	[2] = { .target_addr = 0xE8, .channel = PCA9546A_CHANNEL_2 },
};
mux_config bus_9_PCA9546A_configs[] = {
	[0] = { .target_addr = 0xE8, .channel = PCA9546A_CHANNEL_1 }, // sensor box
	[1] = { .target_addr = 0xE8, .channel = PCA9546A_CHANNEL_2 }, // PDB
};
/**************************************************************************************************
 *  PRE-HOOK/POST-HOOK FUNC
 **************************************************************************************************/
struct k_mutex *get_i2c_mux_mutex(uint8_t i2c_bus)
{
	struct k_mutex *mutex = NULL;

	switch (i2c_bus) {
	case I2C_BUS1:
		mutex = &i2c_1_PCA9546a_mutex;
		break;
	case I2C_BUS2:
		mutex = &i2c_2_PCA9546a_mutex;
		break;
	case I2C_BUS6:
		mutex = &i2c_6_pca9546a_mutex;
		break;
	case I2C_BUS7:
		mutex = &i2c_7_PCA9546a_mutex;
		break;
	case I2C_BUS8:
		mutex = &i2c_8_PCA9546a_mutex;
		break;
	case I2C_BUS9:
		mutex = &i2c_9_PCA9546a_mutex;
		break;
	default:
		LOG_ERR("No support for i2c bus %d mutex", i2c_bus);
		break;
	}

	return mutex;
}
bool pre_PCA9546A_read(sensor_cfg *cfg, void *args)
{
	CHECK_NULL_ARG_WITH_RETURN(cfg, false);
	CHECK_NULL_ARG_WITH_RETURN(args, false);

	// Select Channel
	bool ret = true;
	int mutex_status = 0;
	mux_config *pre_args = (mux_config *)args;
	pre_args->bus = cfg->port;

	struct k_mutex *mutex = get_i2c_mux_mutex(pre_args->bus);
	mutex_status = k_mutex_lock(mutex, K_MSEC(MUTEX_LOCK_INTERVAL_MS));
	if (mutex_status != 0) {
		LOG_ERR("Mutex lock fail, status: %d", mutex_status);
		return false;
	}

	ret = set_mux_channel(*pre_args, MUTEX_LOCK_ENABLE);
	if (ret != true) {
		k_mutex_unlock(mutex);
	}

	return ret;
}
bool post_PCA9546A_read(sensor_cfg *cfg, void *args, int *reading)
{
	CHECK_NULL_ARG_WITH_RETURN(cfg, false);
	ARG_UNUSED(reading);
	ARG_UNUSED(args);

	int unlock_status = 0;
	uint8_t bus = cfg->port;

	struct k_mutex *mutex = get_i2c_mux_mutex(bus);
	if (mutex->lock_count != 0) {
		unlock_status = k_mutex_unlock(mutex);
	}

	if (unlock_status != 0) {
		LOG_ERR("Mutex unlock fail, status: %d", unlock_status);
		return false;
	}

	return true;
}
bool post_adm1272_read(sensor_cfg *cfg, void *args, int *reading)
{
	CHECK_NULL_ARG_WITH_RETURN(cfg, false);
	ARG_UNUSED(args);

	if (reading == NULL) {
		return check_reading_pointer_null_is_allowed(cfg);
	}

	sensor_val *sval = (sensor_val *)reading;
	if (cfg->offset == PMBUS_READ_IOUT || cfg->offset == PMBUS_READ_IIN) {
		// Adjust negative current value to zero according to power team suggestion
		if ((int)sval->integer < 0) {
			*reading = 0;
			return true;
		}
	}

	if (cfg->offset == PMBUS_READ_IOUT || cfg->offset == PMBUS_READ_IIN ||
	    cfg->offset == PMBUS_READ_POUT || cfg->offset == PMBUS_READ_PIN) {
		// multiply 98% for accuracy
		float val = ((float)sval->integer + (sval->fraction / 1000.0)) * 0.98;
		sval->integer = (int)val & 0xFFFF;
		sval->fraction = (val - sval->integer) * 1000;
	}

	return true;
}

bool post_ads112c_read(sensor_cfg *cfg, void *args, int *reading)
{

    short int read16Bits =(short int) *reading;
    double ads112c_default_vol = 5;
    ads112c_init_arg *init_arg = (ads112c_init_arg *)cfg->init_args;

    double genValue;
    switch (init_arg->reg0_gain) {
        case ADS112C_REG0_GAIN1:
        genValue = 1;
        break;
        case ADS112C_REG0_GAIN2:
        genValue = 2;
        break;
        case ADS112C_REG0_GAIN4:
        genValue = 4;
        break;
        case ADS112C_REG0_GAIN8:
        genValue = 8;
        break;
        case ADS112C_REG0_GAIN16:
        genValue = 16;
        break;
        case ADS112C_REG0_GAIN32:
        genValue = 32;
        break;
        case ADS112C_REG0_GAIN64:
        genValue = 64;
        break;
        case ADS112C_REG0_GAIN128:
        genValue = 128;
        break;
        default:
        genValue = 1;
        break;        
    }

    double rawValue = (double) read16Bits * ads112c_default_vol / (32768 * genValue); //(2 · VREF / Gain) / (2^16)

	double val;
	double v_val, flow_Pmax = 400, flow_Pmin = 10, press_Pmax = 50, press_Pmin = 0;

	switch (cfg->offset) {
	case ADS112C_FLOW_OFFSET: //Flow_Rate_LPM
		v_val = 5 - ((32767 - rawValue) * 0.000153);
		val = ((flow_Pmax - flow_Pmin) * (2 * v_val - 1) / 8) + 10;
		//val = (((v_val / 5) - 0.1) / (0.8 / (flow_Pmax - flow_Pmin))) + 10;
		val = (val - 7.56494) * 0.294524;
		val = 1.2385 * ((2.5147 * val) - 2.4892);
		val = (1.7571 * val) - 0.8855;
		break;

	case ADS112C_PRESS_OFFSET: //Filter_P/Outlet_P/Inlet_P
		v_val = 5 - ((32767 - rawValue) * 0.000153);
		val = ((press_Pmax - press_Pmin) * (2 * v_val - 1) / 8) + 10;
		//val = (((v_val / 5) - 0.1) / (0.8 / (press_Pmax - press_Pmin))) + 10;
		val = ((0.9828 * val) - 9.9724) * 6.894759;
		break;

	case ADS112C_TEMP_OFFSET: //RDHx_Hot_Liq_T/CDU_Inlet_Liq_T
		val = (rawValue - 15888) * 0.015873;
		val = (1.1685 * val) - 4.5991;
		break;

	default:
		val = rawValue * 1.0;
		break;
	}

	sensor_val *sval = (sensor_val *)reading;
	sval->integer = (int)val & 0xFFFF;
	sval->fraction = (val - sval->integer) * 1000;

	return true;
}

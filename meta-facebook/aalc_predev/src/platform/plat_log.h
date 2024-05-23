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
#include "plat_modbus.h"

uint8_t modbus_error_log_count(modbus_command_mapping *cmd);
uint8_t modbus_error_log_event(modbus_command_mapping *cmd);
void error_log_event(uint8_t sensor_num, bool val_normal);
void init_load_eeprom_log(void);
bool modbus_clear_log(void);

typedef struct _modbus_err_log_mapping {
	uint16_t index;
	uint16_t err_code;
	uint32_t sys_time;
	uint16_t pump_duty;
	uint16_t fan_duty;
	uint16_t outlet_temp;
	uint16_t outlet_press;
	uint16_t flow_rate;
	uint16_t volt;
} modbus_err_log_mapping;

enum LOG_ERROR_CODE {
	LEAK_CHASSIS_0 = 0X0A,
	LEAK_CHASSIS_1 = 0X0B,
	LEAK_CHASSIS_2 = 0X0C,
	LEAK_CHASSIS_3 = 0X0D,
	LEAK_RPU_INT = 0X0E,
    LEAK_RPU_EXT = 0X0F,
    LEAK_MAN_HOT = 0X10,
    LEAK_MAN_COLD = 0X11,
    LEAK_MAN_PAN_GPO = 0X6E,
    LEAK_MAN_FLOOR_GPO = 0X6F,
    LEAK_MAN_PAN_RELAY = 0X70,
    LEAK_MAN_FLOOR_RELAY = 0X71,
    LOW_WATER_LEVEL = 0x02,
    PUMP_1_SPEED_ABNORMAL = 0x1F,
    PUMP_2_SPEED_ABNORMAL = 0x20,
    PUMP_3_SPEED_ABNORMAL = 0x21,
    PUMP_1_SPEED_RECOVER = 0x29,
    PUMP_2_SPEED_RECOVER = 0x2A,
    PUMP_3_SPEED_RECOVER = 0x2B,
};

typedef struct _err_sensor_mapping {
	uint16_t err_code;
	uint8_t sen_num;
} err_sensor_mapping;

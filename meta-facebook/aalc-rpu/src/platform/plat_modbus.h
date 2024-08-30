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

#ifndef PLAT_MODBUS_H
#define PLAT_MODBUS_H

#include <stdbool.h>
#include <stdint.h>

#define MODBUS_UART_NODE_ADDR 0x0C
#define MODBUS_UART_FP_OFFSET 5000

/*MODBUS Serial Line Parameter*/
#define MODBUS_UART_BAUDRATE_LOW 19200
#define MODBUS_UART_BAUDRATE_HIGH 115200
#define MODBUS_UART_PARITY UART_CFG_PARITY_NONE
#define MODBUS_UART_RESPONSE_T 1000000
//from zephyr/samples/subsys/modbus/rtu_client, client_param: rx_timeout = 1000000(default 50000)

/* MODBUS Command for i2c w/r */
#define MODBUS_MASTER_I2C_WRITE_READ_ADDR 0xF000
#define MODBUS_MASTER_I2C_WRITE_READ_RESPONSE_ADDR 0xF010
#define MODBUS_MASTER_I2C_SCAN_BUS_SET_ADDR 0xF020 // 1 byte
#define MODBUS_MASTER_I2C_SCAN_ADDR 0xF021 // 31 bytes

#define MODBUS_GET_SET_SENSOR_POLL_ADDR 0xF080

#define MODBUS_GET_SET_HMI_VER_ADDR 0x19F2

int init_custom_modbus_server(void);
void init_modbus_command_table(void);
int change_modbus_slave_addr(uint8_t idx, uint8_t addr);

typedef struct _modbus_command_mapping {
	uint16_t addr;
	uint8_t (*wr_fn)(struct _modbus_command_mapping *);
	uint8_t (*rd_fn)(struct _modbus_command_mapping *);
	uint8_t arg0;
	uint8_t arg1;
	uint8_t arg2;
	uint16_t cmd_size;

	/* private */
	uint16_t start_addr; // first addr for multiple register write/read
	uint16_t *data;
	uint8_t data_len;
} modbus_command_mapping;

typedef struct _sensor_access_mapping {
	uint8_t function_index;
	uint8_t senser_num[5];
} sensor_access_mapping;

/* define modbus data address */
#define MODBUS_TEMP_BB_TMP75_ADDR 0x0101
#define MODBUS_TEMP_BPB_TMP75_ADDR 0x0102
#define MODBUS_POWER_RPU_ADDR 0x9999
/* define sensor modbus data address*/
#define MODBUS_BPB_RPU_COOLANT_FLOW_RATE_LPM_ADDR 0x9000
#define MODBUS_BPB_RPU_COOLANT_OUTLET_TEMP_ADDR 0x9001
#define MODBUS_BPB_RPU_COOLANT_INLET_TEMP_ADDR 0x9002
#define MODBUS_BPB_RPU_COOLANT_OUTLET_P_KPA_ADDR 0x9003
#define MODBUS_BPB_RPU_COOLANT_INLET_P_KPA_ADDR 0x9004
#define MODBUS_RPU_PWR_W_ADDR 0x9005
#define MODBUS_AALC_TOTAL_PWR_W_ADDR 0x9006
#define MODBUS_RPU_INPUT_VOLT_V_ADDR 0x9007
#define MODBUS_MB_RPU_AIR_INLET_TEMP_ADDR 0x9008
#define MODBUS_RPU_PUMP_PWM_TACH_PCT_ADDR 0x9009
#define MODBUS_PB_1_PUMP_TACH_RPM_ADDR 0x900A
#define MODBUS_PB_2_PUMP_TACH_RPM_ADDR 0x900B
#define MODBUS_PB_3_PUMP_TACH_RPM_ADDR 0x900C
#define MODBUS_RPU_FAN_STATUS_ADDR 0x900E
#define MODBUS_MB_FAN1_TACH_RPM_ADDR 0x900F
#define MODBUS_MB_FAN2_TACH_RPM_ADDR 0x9010
#define MODBUS_AALC_COOLING_CAPACITY_W_ADDR 0x9011
#define MODBUS_RPU_PUMP1_STATUS_ADDR 0x9012
#define MODBUS_RPU_PUMP2_STATUS_ADDR 0x9013
#define MODBUS_RPU_PUMP3_STATUS_ADDR 0x9014
#define MODBUS_RPU_RESERVOIR_STATUS_ADDR 0x9016
#define MODBUS_RPU_LED_STATUS_ADDR 0x9017
#define MODBUS_RPU_PUMP_STATUS_ADDR 0x9018
#define MODBUS_RPU_INTERNAL_FAN_STATUS_ADDR 0x9019
#define MODBUS_PUMP_1_RUNNING_ADDR 0x9030
#define MODBUS_PUMP_2_RUNNING_ADDR 0x9032
#define MODBUS_PUMP_3_RUNNING_ADDR 0x9034
#define MODBUS_BB_TMP75_TEMP_ADDR 0xA000
#define MODBUS_BPB_RPU_OUTLET_TEMP_ADDR 0xA001
#define MODBUS_PDB_HDC1080DMBR_TEMP_ADDR 0xA002
#define MODBUS_BB_HSC_P48V_TEMP_ADDR 0xA006
#define MODBUS_BPB_HSC_P48V_TEMP_ADDR 0xA007
#define MODBUS_PB_1_HDC1080DMBR_TEMP_ADDR 0xA003
#define MODBUS_PB_2_HDC1080DMBR_TEMP_ADDR 0xA004
#define MODBUS_PB_3_HDC1080DMBR_TEMP_ADDR 0xA005
#define MODBUS_PB_1_HSC_P48V_TEMP_ADDR 0xA008
#define MODBUS_PB_2_HSC_P48V_TEMP_ADDR 0xA009
#define MODBUS_PB_3_HSC_P48V_TEMP_ADDR 0xA00A
#define MODBUS_PB_1_HSC_P48V_VIN_VOLT_V_ADDR 0xA00D
#define MODBUS_PB_2_HSC_P48V_VIN_VOLT_V_ADDR 0xA00E
#define MODBUS_PB_3_HSC_P48V_VIN_VOLT_V_ADDR 0xA00F
#define MODBUS_BB_HSC_P48V_VIN_VOLT_V_ADDR 0xA00B
#define MODBUS_BPB_HSC_P48V_VIN_VOLT_V_ADDR 0xA00C
#define MODBUS_BB_HSC_P48V_IOUT_CURR_A_ADDR 0xA010
#define MODBUS_BPB_HSC_P48V_IOUT_CURR_A_ADDR 0xA011
#define MODBUS_PB_1_HSC_P48V_IOUT_CURR_A_ADDR 0xA012
#define MODBUS_PB_2_HSC_P48V_IOUT_CURR_A_ADDR 0xA013
#define MODBUS_PB_3_HSC_P48V_IOUT_CURR_A_ADDR 0xA014
#define MODBUS_BB_HSC_P48V_PIN_PWR_W_ADDR 0xA015
#define MODBUS_BPB_HSC_P48V_PIN_PWR_W_ADDR 0xA016
#define MODBUS_PB_1_HSC_P48V_PIN_PWR_W_ADDR 0xA017
#define MODBUS_PB_2_HSC_P48V_PIN_PWR_W_ADDR 0xA018
#define MODBUS_PB_3_HSC_P48V_PIN_PWR_W_ADDR 0xA019
#define MODBUS_PB_1_FAN_OUTLET_TACH_RPM_ADDR 0xA01A
#define MODBUS_PB_1_FAN_INLET_TACH_RPM_ADDR 0xA01B
#define MODBUS_PB_2_FAN_OUTLET_TACH_RPM_ADDR 0xA01C
#define MODBUS_PB_2_FAN_INLET_TACH_RPM_ADDR 0xA01D
#define MODBUS_PB_3_FAN_OUTLET_TACH_RPM_ADDR 0xA01E
#define MODBUS_PB_3_FAN_INLET_TACH_RPM_ADDR 0xA01F
#define MODBUS_BPB_RACK_FILTER_INLET_PRESSURE_P_KPA_ADDR 0xA020
#define MODBUS_BPB_RACK_FILTER_OUTLET_PRESSURE_P_KPA_ADDR 0xA021
#define MODBUS_BPB_RACK_LEVEL_1_ADDR 0xA022
#define MODBUS_BPB_RACK_LEVEL_2_ADDR 0xA023
#define MODBUS_MB_HUM_PCT_RH_ADDR 0xA024
#define MODBUS_PDB_HUM_PCT_RH_ADDR 0xA025
#define MODBUS_PB_1_HUM_PCT_RH_ADDR 0xA026
#define MODBUS_PB_2_HUM_PCT_RH_ADDR 0xA027
#define MODBUS_PB_3_HUM_PCT_RH_ADDR 0xA028
#define MODBUS_RPU_PDB_48V_SENSE_DIFF_POS_VOLT_V_ADDR 0xA029
#define MODBUS_RPU_PDB_48V_SENSE_DIFF_NEG_VOLT_V_ADDR 0xA02A
#define MODBUS_BPB_CDU_COOLANT_LEAKAGE_VOLT_V_ADDR 0xA02B
#define MODBUS_BPB_RACK_COOLANT_LEAKAGE_VOLT_V_ADDR 0xA02C
#define MODBUS_AALC_TOTAL_PWR_EXT_W_ADDR 0xA02D
#define MODBUS_HEX_FAN_PWM_TACH_PCT_ADDR 0x9100
#define MODBUS_HEX_PWR_W_ADDR 0x9101
#define MODBUS_HEX_INPUT_VOLT_V_ADDR 0x9102
#define MODBUS_HEX_INPUT_CURRENT_A_ADDR 0x9103
#define MODBUS_FB_1_FAN_TACH_RPM_ADDR 0x9104
#define MODBUS_FB_2_FAN_TACH_RPM_ADDR 0x9105
#define MODBUS_FB_3_FAN_TACH_RPM_ADDR 0x9106
#define MODBUS_FB_4_FAN_TACH_RPM_ADDR 0x9107
#define MODBUS_FB_5_FAN_TACH_RPM_ADDR 0x9108
#define MODBUS_FB_6_FAN_TACH_RPM_ADDR 0x9109
#define MODBUS_FB_7_FAN_TACH_RPM_ADDR 0x910A
#define MODBUS_FB_8_FAN_TACH_RPM_ADDR 0x910B
#define MODBUS_FB_9_FAN_TACH_RPM_ADDR 0x910C
#define MODBUS_FB_10_FAN_TACH_RPM_ADDR 0x910D
#define MODBUS_FB_1_HEX_OUTLET_TEMP_ADDR 0x910E
#define MODBUS_FB_2_HEX_OUTLET_TEMP_ADDR 0x910F
#define MODBUS_SB_HEX_AIR_INLET_1_TEMP_ADDR 0x9110
#define MODBUS_SB_HEX_AIR_INLET_2_TEMP_ADDR 0x9111
#define MODBUS_HEX_WATER_INLET_TEMP_C_ADDR 0x9112
#define MODBUS_HEX_BLADDER_LEVEL_STATUS_ADDR 0x9113
#define MODBUS_HEX_EXTERNAL_Y_FILTER_PRESSURE_ADDR 0x9114
#define MODBUS_HEX_STATIC_PRESSURE_ADDR 0x9115
#define MODBUS_HEX_VERTICAL_BLADDER_ADDR 0x9116
#define MODBUS_SB_HEX_AIR_INLET_3_TEMP_ADDR 0xA100
#define MODBUS_SB_HEX_AIR_INLET_4_TEMP_ADDR 0xA101
#define MODBUS_FB_3_HEX_OUTLET_TEMP_ADDR 0xA102
#define MODBUS_FB_4_HEX_OUTLET_TEMP_ADDR 0xA103
#define MODBUS_FB_5_HEX_OUTLET_TEMP_ADDR 0xA104
#define MODBUS_FB_6_HEX_OUTLET_TEMP_ADDR 0xA105
#define MODBUS_FB_7_HEX_OUTLET_TEMP_ADDR 0xA106
#define MODBUS_FB_8_HEX_OUTLET_TEMP_ADDR 0xA107
#define MODBUS_FB_9_HEX_OUTLET_TEMP_ADDR 0xA108
#define MODBUS_FB_10_HEX_OUTLET_TEMP_ADDR 0xA109
#define MODBUS_FB_11_HEX_OUTLET_TEMP_ADDR 0xA10A
#define MODBUS_FB_12_HEX_OUTLET_TEMP_ADDR 0xA10B
#define MODBUS_FB_13_HEX_OUTLET_TEMP_ADDR 0xA10C
#define MODBUS_FB_14_HEX_OUTLET_TEMP_ADDR 0xA10D
#define MODBUS_FB_1_HSC_TEMP_ADDR 0xA10E
#define MODBUS_FB_2_HSC_TEMP_ADDR 0xA10F
#define MODBUS_FB_3_HSC_TEMP_ADDR 0xA110
#define MODBUS_FB_4_HSC_TEMP_ADDR 0xA111
#define MODBUS_FB_5_HSC_TEMP_ADDR 0xA112
#define MODBUS_FB_6_HSC_TEMP_ADDR 0xA113
#define MODBUS_FB_7_HSC_TEMP_ADDR 0xA114
#define MODBUS_FB_8_HSC_TEMP_ADDR 0xA115
#define MODBUS_FB_9_HSC_TEMP_ADDR 0xA116
#define MODBUS_FB_10_HSC_TEMP_ADDR 0xA117
#define MODBUS_FB_11_HSC_TEMP_ADDR 0xA118
#define MODBUS_FB_12_HSC_TEMP_ADDR 0xA119
#define MODBUS_FB_13_HSC_TEMP_ADDR 0xA11A
#define MODBUS_FB_14_HSC_TEMP_ADDR 0xA11B
#define MODBUS_FB_1_HSC_P48V_VIN_VOLT_V_ADDR 0xA11C
#define MODBUS_FB_2_HSC_P48V_VIN_VOLT_V_ADDR 0xA11D
#define MODBUS_FB_3_HSC_P48V_VIN_VOLT_V_ADDR 0xA11E
#define MODBUS_FB_4_HSC_P48V_VIN_VOLT_V_ADDR 0xA11F
#define MODBUS_FB_5_HSC_P48V_VIN_VOLT_V_ADDR 0xA120
#define MODBUS_FB_6_HSC_P48V_VIN_VOLT_V_ADDR 0xA121
#define MODBUS_FB_7_HSC_P48V_VIN_VOLT_V_ADDR 0xA122
#define MODBUS_FB_8_HSC_P48V_VIN_VOLT_V_ADDR 0xA123
#define MODBUS_FB_9_HSC_P48V_VIN_VOLT_V_ADDR 0xA124
#define MODBUS_FB_10_HSC_P48V_VIN_VOLT_V_ADDR 0xA125
#define MODBUS_FB_11_HSC_P48V_VIN_VOLT_V_ADDR 0xA126
#define MODBUS_FB_12_HSC_P48V_VIN_VOLT_V_ADDR 0xA127
#define MODBUS_FB_13_HSC_P48V_VIN_VOLT_V_ADDR 0xA128
#define MODBUS_FB_14_HSC_P48V_VIN_VOLT_V_ADDR 0xA129
#define MODBUS_FB_1_HSC_P48V_IOUT_CURR_A_ADDR 0xA12A
#define MODBUS_FB_2_HSC_P48V_IOUT_CURR_A_ADDR 0xA12B
#define MODBUS_FB_3_HSC_P48V_IOUT_CURR_A_ADDR 0xA12C
#define MODBUS_FB_4_HSC_P48V_IOUT_CURR_A_ADDR 0xA12D
#define MODBUS_FB_5_HSC_P48V_IOUT_CURR_A_ADDR 0xA12E
#define MODBUS_FB_6_HSC_P48V_IOUT_CURR_A_ADDR 0xA12F
#define MODBUS_FB_7_HSC_P48V_IOUT_CURR_A_ADDR 0xA130
#define MODBUS_FB_8_HSC_P48V_IOUT_CURR_A_ADDR 0xA131
#define MODBUS_FB_9_HSC_P48V_IOUT_CURR_A_ADDR 0xA132
#define MODBUS_FB_10_HSC_P48V_IOUT_CURR_A_ADDR 0xA133
#define MODBUS_FB_11_HSC_P48V_IOUT_CURR_A_ADDR 0xA134
#define MODBUS_FB_12_HSC_P48V_IOUT_CURR_A_ADDR 0xA135
#define MODBUS_FB_13_HSC_P48V_IOUT_CURR_A_ADDR 0xA136
#define MODBUS_FB_14_HSC_P48V_IOUT_CURR_A_ADDR 0xA137
#define MODBUS_FB_1_HSC_P48V_PIN_PWR_W_ADDR 0xA138
#define MODBUS_FB_2_HSC_P48V_PIN_PWR_W_ADDR 0xA139
#define MODBUS_FB_3_HSC_P48V_PIN_PWR_W_ADDR 0xA13A
#define MODBUS_FB_4_HSC_P48V_PIN_PWR_W_ADDR 0xA13B
#define MODBUS_FB_5_HSC_P48V_PIN_PWR_W_ADDR 0xA13C
#define MODBUS_FB_6_HSC_P48V_PIN_PWR_W_ADDR 0xA13D
#define MODBUS_FB_7_HSC_P48V_PIN_PWR_W_ADDR 0xA13E
#define MODBUS_FB_8_HSC_P48V_PIN_PWR_W_ADDR 0xA13F
#define MODBUS_FB_9_HSC_P48V_PIN_PWR_W_ADDR 0xA140
#define MODBUS_FB_10_HSC_P48V_PIN_PWR_W_ADDR 0xA141
#define MODBUS_FB_11_HSC_P48V_PIN_PWR_W_ADDR 0xA142
#define MODBUS_FB_12_HSC_P48V_PIN_PWR_W_ADDR 0xA143
#define MODBUS_FB_13_HSC_P48V_PIN_PWR_W_ADDR 0xA144
#define MODBUS_FB_14_HSC_P48V_PIN_PWR_W_ADDR 0xA145
#define MODBUS_FB_11_FAN_TACH_RPM_ADDR 0xA146
#define MODBUS_FB_12_FAN_TACH_RPM_ADDR 0xA147
#define MODBUS_FB_13_FAN_TACH_RPM_ADDR 0xA148
#define MODBUS_FB_14_FAN_TACH_RPM_ADDR 0xA149
#define MODBUS_SB_HEX_INLET_PRESSURE_P_KPA_ADDR 0xA14A
#define MODBUS_SB_HEX_OUTLET_PRESSURE_P_KPA_ADDR 0xA14B
#define MODBUS_FB_1_HUM_PCT_RH_ADDR 0xA14C
#define MODBUS_FB_2_HUM_PCT_RH_ADDR 0xA14D
#define MODBUS_FB_3_HUM_PCT_RH_ADDR 0xA14E
#define MODBUS_FB_4_HUM_PCT_RH_ADDR 0xA14F
#define MODBUS_FB_5_HUM_PCT_RH_ADDR 0xA150
#define MODBUS_FB_6_HUM_PCT_RH_ADDR 0xA151
#define MODBUS_FB_7_HUM_PCT_RH_ADDR 0xA152
#define MODBUS_FB_8_HUM_PCT_RH_ADDR 0xA153
#define MODBUS_FB_9_HUM_PCT_RH_ADDR 0xA154
#define MODBUS_FB_10_HUM_PCT_RH_ADDR 0xA155
#define MODBUS_FB_11_HUM_PCT_RH_ADDR 0xA156
#define MODBUS_FB_12_HUM_PCT_RH_ADDR 0xA157
#define MODBUS_FB_13_HUM_PCT_RH_ADDR 0xA158
#define MODBUS_FB_14_HUM_PCT_RH_ADDR 0xA159

#define MODBUS_LEAKAGE_STATUS_ADDR 0x9202
#define MODBUS_SB_TTV_COOLANT_LEAKAGE_ADDR 0xA200
#define MODBUS_AALC_SENSOR_ALARM_ADDR 0x9200
#define MODBUS_Y_FILTER_SENSOR_STATUS_ADDR 0x91FF
#define MODBUS_AALC_STATUS_ALARM_ADDR 0x9201
#define MODBUS_HEX_FAN_ALARM_1_ADDR 0x9203
#define MODBUS_HEX_FAN_ALARM_2_ADDR 0xA201
#define MODBUS_HEX_FAN_COMMS_ALARM_ADDR 0xA205
#define MODBUS_HSC_POWER_STATUS_ADDR 0xA203
#define MODBUS_FB_HSC_POWER_STATUS_ADDR 0xA204
#define MODBUS_HSC_COMMS_STATUS_ADDR 0xA206
#define MODBUS_FB_HSC_COMMS_STATUS_ADDR 0xA207
#define MODBUS_AUTO_TUNE_COOLANT_FLOW_RATE_TARGET_SET_ADDR 0x9400
#define MODBUS_AUTO_TUNE_COOLANT_OUTLET_TEMPERATURE_TARGET_SET_ADDR 0x9401
#define MODBUS_PUMP_REDUNDANT_SWITCHED_INTERVAL_ADDR 0x9402
#define MODBUS_MANUAL_CONTROL_PUMP_DUTY_SET_ADDR 0x9403
#define MODBUS_MANUAL_CONTROL_FAN_DUTY_SET_ADDR 0x9404
#define MODBUS_MANUAL_CONTROL_RPU_FAN_DUTY_SET_ADDR 0xA402
#define MODBUS_MANUAL_CONTROL_PUMP1_DUTY_SET_ADDR 0xA403
#define MODBUS_MANUAL_CONTROL_PUMP2_DUTY_SET_ADDR 0xA404
#define MODBUS_MANUAL_CONTROL_PUMP3_DUTY_SET_ADDR 0xA405
#define MODBUS_MANUAL_CONTROL_PUMP_FAN_1_DUTY_SET_ADDR 0xA406
#define MODBUS_MANUAL_CONTROL_PUMP_FAN_2_DUTY_SET_ADDR 0xA407
#define MODBUS_MANUAL_CONTROL_PUMP_FAN_3_DUTY_SET_ADDR 0xA408
#define MODBUS_MANUAL_CONTROL_RPU_PCB_FAN_DUTY_SET_ADDR 0xA409
#define MODBUS_PUMP_SETTING_ADDR 0x9410
#define MODBUS_LEAKAGE_SETTING_ON_ADDR 0x9411
#define MODBUS_STICKY_ITRACK_CHASSIS0_LEAKAGE_ADDR 0x19A1
#define MODBUS_STICKY_ITRACK_CHASSIS1_LEAKAGE_ADDR 0x19A2
#define MODBUS_STICKY_ITRACK_CHASSIS2_LEAKAGE_ADDR 0x19A3
#define MODBUS_STICKY_ITRACK_CHASSIS3_LEAKAGE_ADDR 0x19A4
#define MODBUS_STICKY_RPU_INTERNAL_LEAKAGE_ABNORMAL_ADDR 0x19A5
#define MODBUS_STICKY_RPU_EXTERNAL_LEAKAGE_ABNORMAL_ADDR 0x19A6
#define MODBUS_STICKY_RPU_OPT_EXTERNAL_LEAKAGE1_ABNORMAL_ADDR 0x19A7
#define MODBUS_STICKY_RPU_OPT_EXTERNAL_LEAKAGE2_ABNORMAL_ADDR 0x19A8
#define MODBUS_STICKY_HEX_RACK_PAN_LEAKAGE_ADDR 0x19A9
#define MODBUS_STICKY_HEX_RACK_FLOOR_LEAKAGE_ADDR 0x19AA
#define MODBUS_STICKY_HEX_RACK_PAN_LEAKAGE_RELAY_ADDR 0x19AB
#define MODBUS_STICKY_HEX_RACK_FLOOR_LEAKAGE_RELAY_ADDR 0x19AC
#define MODBUS_PUMP_FAN_STATUS_ADDR 0xA080
#define MODBUS_HEX_AIR_THERMOMETER_STATUS_ADDR 0xA202
#define MODBUS_V_12_AUX_ADDR 0xA02E
#define MODBUS_V_5_AUX_ADDR 0xA02F
#define MODBUS_V_3_3_AUX_ADDR 0xA030
#define MODBUS_V_1_2_AUX_ADDR 0xA031
#define MODBUS_V_5_USB_ADDR 0xA032
#define MODBUS_MODBUS_ADDR_PATH_WITH_WEDGE400_ADDR 0xA401
#define MODBUS_MANUAL_CONTROL_RPU_FAN_ON_OFF_ADDR 0xA480
#define MODBUS_ERROR_LOG_COUNT_ADDR 0x1A28
#define MODBUS_EVENT_1_ERROR_LOG_ADDR 0x1A29
#define MODBUS_EVENT_2_ERROR_LOG_ADDR 0x1A33
#define MODBUS_EVENT_3_ERROR_LOG_ADDR 0x1A3D
#define MODBUS_EVENT_4_ERROR_LOG_ADDR 0x1A47
#define MODBUS_EVENT_5_ERROR_LOG_ADDR 0x1A51
#define MODBUS_EVENT_6_ERROR_LOG_ADDR 0x1A5B
#define MODBUS_EVENT_7_ERROR_LOG_ADDR 0x1A65
#define MODBUS_EVENT_8_ERROR_LOG_ADDR 0x1A6F
#define MODBUS_EVENT_9_ERROR_LOG_ADDR 0x1A79
#define MODBUS_EVENT_10_ERROR_LOG_ADDR 0x1A83
#define MODBUS_EVENT_11_ERROR_LOG_ADDR 0x1A8D
#define MODBUS_EVENT_12_ERROR_LOG_ADDR 0x1A97
#define MODBUS_EVENT_13_ERROR_LOG_ADDR 0x1AA1
#define MODBUS_EVENT_14_ERROR_LOG_ADDR 0x1AAB
#define MODBUS_EVENT_15_ERROR_LOG_ADDR 0x1AB5
#define MODBUS_EVENT_16_ERROR_LOG_ADDR 0x1ABF
#define MODBUS_EVENT_17_ERROR_LOG_ADDR 0x1AC9
#define MODBUS_EVENT_18_ERROR_LOG_ADDR 0x1AD3
#define MODBUS_EVENT_19_ERROR_LOG_ADDR 0x1ADD
#define MODBUS_EVENT_20_ERROR_LOG_ADDR 0x1AE7

/* FW Update */
#define MODBUS_FW_REVISION_ADDR 0x19E8
#define MODBUS_FW_DOWNLOAD_ADDR 0x2000
#define MODBUS_RPU_RUN_ADDR 0x0C30
#define MODBUS_SYNAX_CHECK_ADDR 0x0C31

//FRU Regs
#define MODBUS_MB_FRU_ADDR 0xB000
#define MODBUS_BB_FRU_ADDR 0xB100
#define MODBUS_BPB_FRU_ADDR 0xB200
#define MODBUS_PDB_FRU_ADDR 0xB300
#define MODBUS_SB_FRU_ADDR 0xB400
#define MODBUS_PB_1_FRU_ADDR 0xB500
#define MODBUS_PB_2_FRU_ADDR 0xB600
#define MODBUS_PB_3_FRU_ADDR 0xB700
#define MODBUS_FB_1_FRU_ADDR 0xB800
#define MODBUS_FB_2_FRU_ADDR 0xB900
#define MODBUS_FB_3_FRU_ADDR 0xBA00
#define MODBUS_FB_4_FRU_ADDR 0xBB00
#define MODBUS_FB_5_FRU_ADDR 0xBC00
#define MODBUS_FB_6_FRU_ADDR 0xBD00
#define MODBUS_FB_7_FRU_ADDR 0xBE00
#define MODBUS_FB_8_FRU_ADDR 0xBF00
#define MODBUS_FB_9_FRU_ADDR 0xC000
#define MODBUS_FB_10_FRU_ADDR 0xC100
#define MODBUS_FB_11_FRU_ADDR 0xC200
#define MODBUS_FB_12_FRU_ADDR 0xC300
#define MODBUS_FB_13_FRU_ADDR 0xC400
#define MODBUS_FB_14_FRU_ADDR 0xC500

#endif

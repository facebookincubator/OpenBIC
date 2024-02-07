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

#ifndef PLAT_SENSOR_TABLE_H
#define PLAT_SENSOR_TABLE_H

#include <stdint.h>
#include <pmbus.h>

/* define sensors address(7 bit) */
#define BB_TMP75_ADDR (0x9E >> 1)
#define BPB_TMP75_ADDR (0x90 >> 1)
#define BB_ADM1272_ADDR (0x26 >> 1)
#define BPB_ADM1272_ADDR (0x20 >> 1)
#define BPB_ADS112C_1_ADDR (0x88 >> 1)
#define BPB_ADS112C_2_ADDR (0x8A >> 1)
#define BPB_ADS112C_3_ADDR (0x82 >> 1)
#define BPB_ADS112C_4_ADDR (0x80 >> 1)
#define SB_ADS112C_ADDR (0x80 >> 1)
#define BPB_NCT7363_ADDR (0x40 >> 1)
#define FB_NCT7363_ADDR (0x42 >> 1)
#define PB_NCT7363_ADDR (0x40 >> 1)
#define HDC1080_ADDR (0x80 >> 1)
#define SB_TMP461_1_ADDR (0x90 >> 1)
#define SB_TMP461_2_ADDR (0x92 >> 1)
#define SB_TMP461_3_ADDR (0x94 >> 1)
#define SB_TMP461_4_ADDR (0x96 >> 1)
#define FB_ADM1272_ADDR (0x22 >> 1)
#define PB_ADM1272_ADDR (0x24 >> 1)
#define ADS112C_MUX_1_CON 0x80 //AINP = AIN0, AINN = AVSS
#define ADS112C_MUX_2_CON 0x90 //AINP = AIN1, AINN = AVSS
#define ADS112C_MUX_3_CON 0xA0 //AINP = AIN2, AINN = AVSS
#define ADS112C_MUX_4_CON 0xA1 //AINP = AIN3, AINN = AVSS

/* define sensors offset */
#define TMP75_TEMP_OFFSET 0x00

/*  threshold sensor number, 1 based  */
#define SENSOR_NUM_TEMP_BB_TMP75 0x01
#define SENSOR_NUM_TEMP_BPB_TMP75 0x02
#define SENSOR_NUM_TEMP_BPB_ADS_1 0x03
#define SENSOR_NUM_TEMP_BPB_ADS_2 0x04
#define SENSOR_NUM_TEMP_BPB_ADS_3 0x05
#define SENSOR_NUM_TEMP_MB 0x06
#define SENSOR_NUM_TEMP_PDB 0x07
#define SENSOR_NUM_TEMP_SB_1 0x08
#define SENSOR_NUM_TEMP_SB_2 0x09
#define SENSOR_NUM_TEMP_SB_3 0x0A
#define SENSOR_NUM_TEMP_SB_4 0x0B
#define SENSOR_NUM_PRESS_BPB_ADS_1 0x0C
#define SENSOR_NUM_PRESS_BPB_ADS_2 0x0D
#define SENSOR_NUM_PRESS_BPB_ADS_3 0x0E
#define SENSOR_NUM_PRESS_BPB_ADS_4 0x0F
#define SENSOR_NUM_FLOW_BPB_ADS 0x10
#define SENSOR_NUM_LEAK_BPB_ADS_1 0x11
#define SENSOR_NUM_LEAK_BPB_ADS_2 0x12
#define SENSOR_NUM_LEAK_BPB_ADS_3 0x13
#define SENSOR_NUM_PUMP_BPB 0x14
/* ast1030 fan sensor number */
#define SENSOR_NUM_FAN_MB_1 0x15
#define SENSOR_NUM_FAN_MB_2 0x16

#define SENSOR_NUM_PUMP_PB_1 0x17
#define SENSOR_NUM_PUMP_PB_2 0x18
#define SENSOR_NUM_PUMP_PB_3 0x19
#define SENSOR_NUM_HUM_MB 0x1A
#define SENSOR_NUM_HUM_PDB 0x1B
/* HSC Temp sensor number */
#define SENSOR_NUM_TEMP_BB_HSC 0x1C
#define SENSOR_NUM_TEMP_BPB_HSC 0x1D
/* HSC Voltage sensor number */
#define SENSOR_NUM_VOL_BB_P51V_STBY 0x1E
#define SENSOR_NUM_VOL_BB_P51V_AUX 0x1F
#define SENSOR_NUM_VOL_BPB_P51V_STBY 0x20
#define SENSOR_NUM_VOL_BPB_P51V_AUX 0x21
/* HSC Current sensor number */
#define SENSOR_NUM_CUR_BB_P51V_STBY 0x22
#define SENSOR_NUM_CUR_BB_P51V_AUX 0x23
#define SENSOR_NUM_CUR_BPB_P51V_STBY 0x24
#define SENSOR_NUM_CUR_BPB_P51V_AUX 0x25
/* HSC Power sensor number */
#define SENSOR_NUM_PWR_BB_P51V_STBY 0x26
#define SENSOR_NUM_PWR_BB_P51V_AUX 0x27
#define SENSOR_NUM_PWR_BPB_P51V_STBY 0x28
#define SENSOR_NUM_PWR_BPB_P51V_AUX 0x29
/* Fan speed sensor number */
#define SENSOR_NUM_FAN_FB_BUS1_1 0x2A
#define SENSOR_NUM_FAN_FB_BUS1_2 0x2B
#define SENSOR_NUM_FAN_FB_BUS1_3 0x2C
#define SENSOR_NUM_FAN_FB_BUS1_4 0x2D
#define SENSOR_NUM_FAN_FB_BUS2_1 0x2E
#define SENSOR_NUM_FAN_FB_BUS2_2 0x2F
#define SENSOR_NUM_FAN_FB_BUS2_3 0x30
#define SENSOR_NUM_FAN_FB_BUS2_4 0x31
#define SENSOR_NUM_FAN_FB_BUS6_1 0x32
#define SENSOR_NUM_FAN_FB_BUS6_2 0x33
#define SENSOR_NUM_FAN_FB_BUS6_3 0x34
#define SENSOR_NUM_FAN_FB_BUS6_4 0x35
#define SENSOR_NUM_FAN_FB_BUS7_1 0x36
#define SENSOR_NUM_FAN_FB_BUS7_2 0x37
#define SENSOR_NUM_FAN_FB_BUS7_3 0x38
#define SENSOR_NUM_FAN_FB_BUS7_4 0x39
/* Pump board fan speed sensor number */
#define SENSOR_NUM_FAN_1_PB_1 0x3A
#define SENSOR_NUM_FAN_2_PB_1 0x3B
#define SENSOR_NUM_FAN_1_PB_2 0x3C
#define SENSOR_NUM_FAN_2_PB_2 0x3D
#define SENSOR_NUM_FAN_1_PB_3 0x3E
#define SENSOR_NUM_FAN_2_PB_3 0x3F
/* Pump board temperature sensor number */
#define SENSOR_NUM_TEMP_PB_1 0x40
#define SENSOR_NUM_TEMP_PB_2 0x41
#define SENSOR_NUM_TEMP_PB_3 0x42
/* Fan board temperature sensor number */
#define SENSOR_NUM_TEMP_FB_BUS1_1 0x43
#define SENSOR_NUM_TEMP_FB_BUS1_2 0x44
#define SENSOR_NUM_TEMP_FB_BUS1_3 0x45
#define SENSOR_NUM_TEMP_FB_BUS1_4 0x46
#define SENSOR_NUM_TEMP_FB_BUS2_1 0x47
#define SENSOR_NUM_TEMP_FB_BUS2_2 0x48
#define SENSOR_NUM_TEMP_FB_BUS2_3 0x49
#define SENSOR_NUM_TEMP_FB_BUS2_4 0x4A
#define SENSOR_NUM_TEMP_FB_BUS6_1 0x4B
#define SENSOR_NUM_TEMP_FB_BUS6_2 0x4C
#define SENSOR_NUM_TEMP_FB_BUS6_3 0x4D
#define SENSOR_NUM_TEMP_FB_BUS6_4 0x4E
#define SENSOR_NUM_TEMP_FB_BUS7_1 0x4F
#define SENSOR_NUM_TEMP_FB_BUS7_2 0x50
#define SENSOR_NUM_TEMP_FB_BUS7_3 0x51
#define SENSOR_NUM_TEMP_FB_BUS7_4 0x52
/* Pump board humidity sensor number */
#define SENSOR_NUM_HUM_PB_1 0x53
#define SENSOR_NUM_HUM_PB_2 0x54
#define SENSOR_NUM_HUM_PB_3 0x55
/* Fan board humidity sensor number */
#define SENSOR_NUM_HUM_FB_BUS1_1 0x56
#define SENSOR_NUM_HUM_FB_BUS1_2 0x57
#define SENSOR_NUM_HUM_FB_BUS1_3 0x58
#define SENSOR_NUM_HUM_FB_BUS1_4 0x59
#define SENSOR_NUM_HUM_FB_BUS2_1 0x5A
#define SENSOR_NUM_HUM_FB_BUS2_2 0x5B
#define SENSOR_NUM_HUM_FB_BUS2_3 0x5C
#define SENSOR_NUM_HUM_FB_BUS2_4 0x5D
#define SENSOR_NUM_HUM_FB_BUS6_1 0x5E
#define SENSOR_NUM_HUM_FB_BUS6_2 0x5F
#define SENSOR_NUM_HUM_FB_BUS6_3 0x60
#define SENSOR_NUM_HUM_FB_BUS6_4 0x61
#define SENSOR_NUM_HUM_FB_BUS7_1 0x62
#define SENSOR_NUM_HUM_FB_BUS7_2 0x63
#define SENSOR_NUM_HUM_FB_BUS7_3 0x64
#define SENSOR_NUM_HUM_FB_BUS7_4 0x65
/*Fan HSC sensor number*/
#define SENSOR_NUM_TEMP_FB_HSC_BUS1_1 0x66
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS1_1 0x67
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS1_1 0x68
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS1_1 0x69
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS1_1 0x6A
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS1_1 0x6B
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS1_1 0x6C
#define SENSOR_NUM_TEMP_FB_HSC_BUS1_2 0x6D
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS1_2 0x6E
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS1_2 0x6F
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS1_2 0x70
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS1_2 0x71
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS1_2 0x72
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS1_2 0x73
#define SENSOR_NUM_TEMP_FB_HSC_BUS1_3 0x74
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS1_3 0x75
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS1_3 0x76
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS1_3 0x77
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS1_3 0x78
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS1_3 0x79
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS1_3 0x7A
#define SENSOR_NUM_TEMP_FB_HSC_BUS1_4 0x7B
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS1_4 0x7C
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS1_4 0x7D
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS1_4 0x7E
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS1_4 0x7F
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS1_4 0x80
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS1_4 0x81
#define SENSOR_NUM_TEMP_FB_HSC_BUS2_1 0x82
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS2_1 0x83
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS2_1 0x84
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS2_1 0x85
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS2_1 0x86
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS2_1 0x87
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS2_1 0x88
#define SENSOR_NUM_TEMP_FB_HSC_BUS2_2 0x89
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS2_2 0x8A
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS2_2 0x8B
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS2_2 0x8C
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS2_2 0x8D
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS2_2 0x8E
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS2_2 0x8F
#define SENSOR_NUM_TEMP_FB_HSC_BUS2_3 0x90
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS2_3 0x91
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS2_3 0x92
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS2_3 0x93
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS2_3 0x94
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS2_3 0x95
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS2_3 0x96
#define SENSOR_NUM_TEMP_FB_HSC_BUS2_4 0x97
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS2_4 0x98
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS2_4 0x99
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS2_4 0x9A
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS2_4 0x9B
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS2_4 0x9C
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS2_4 0x9D
#define SENSOR_NUM_TEMP_FB_HSC_BUS6_1 0x9E
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS6_1 0x9F
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS6_1 0xA0
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS6_1 0xA1
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS6_1 0xA2
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS6_1 0xA3
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS6_1 0xA4
#define SENSOR_NUM_TEMP_FB_HSC_BUS6_2 0xA5
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS6_2 0xA6
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS6_2 0xA7
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS6_2 0xA8
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS6_2 0xA9
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS6_2 0xAA
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS6_2 0xAB
#define SENSOR_NUM_TEMP_FB_HSC_BUS6_3 0xAC
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS6_3 0xAD
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS6_3 0xAE
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS6_3 0xAF
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS6_3 0xB0
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS6_3 0xB1
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS6_3 0xB2
#define SENSOR_NUM_TEMP_FB_HSC_BUS6_4 0xB3
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS6_4 0xB4
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS6_4 0xB5
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS6_4 0xB6
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS6_4 0xB7
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS6_4 0xB8
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS6_4 0xB9
#define SENSOR_NUM_TEMP_FB_HSC_BUS7_1 0xBA
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS7_1 0xBB
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS7_1 0xBC
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS7_1 0xBD
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS7_1 0xBE
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS7_1 0xBF
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS7_1 0xC0
#define SENSOR_NUM_TEMP_FB_HSC_BUS7_2 0xC1
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS7_2 0xC2
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS7_2 0xC3
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS7_2 0xC4
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS7_2 0xC5
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS7_2 0xC6
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS7_2 0xC7
#define SENSOR_NUM_TEMP_FB_HSC_BUS7_3 0xC8
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS7_3 0xC9
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS7_3 0xCA
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS7_3 0xCB
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS7_3 0xCC
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS7_3 0xCD
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS7_3 0xCE
#define SENSOR_NUM_TEMP_FB_HSC_BUS7_4 0xCF
#define SENSOR_NUM_VOL_FB_P48V_STBY_BUS7_4 0xD0
#define SENSOR_NUM_VOL_FB_P48V_AUX_BUS7_4 0xD1
#define SENSOR_NUM_CUR_FB_P48V_STBY_BUS7_4 0xD2
#define SENSOR_NUM_CUR_FB_P48V_AUX_BUS7_4 0xD3
#define SENSOR_NUM_PWR_FB_P48V_STBY_BUS7_4 0xD4
#define SENSOR_NUM_PWR_FB_P48V_AUX_BUS7_4 0xD5
/*Pump HSC sensor number*/
#define SENSOR_NUM_TEMP_PB_1_HSC_BUS8 0xD6
#define SENSOR_NUM_VOL_PB_1_P48V_STBY_BUS8 0xD7
#define SENSOR_NUM_VOL_PB_1_P48V_AUX_BUS8 0xD8
#define SENSOR_NUM_CUR_PB_1_P48V_STBY_BUS8 0xD9
#define SENSOR_NUM_CUR_PB_1_P48V_AUX_BUS8 0xDA
#define SENSOR_NUM_PWR_PB_1_P48V_STBY_BUS8 0xDB
#define SENSOR_NUM_PWR_PB_1_P48V_AUX_BUS8 0xDC
#define SENSOR_NUM_TEMP_PB_2_HSC_BUS8 0xDD
#define SENSOR_NUM_VOL_PB_2_P48V_STBY_BUS8 0xDE
#define SENSOR_NUM_VOL_PB_2_P48V_AUX_BUS8 0xDF
#define SENSOR_NUM_CUR_PB_2_P48V_STBY_BUS8 0xE0
#define SENSOR_NUM_CUR_PB_2_P48V_AUX_BUS8 0xE1
#define SENSOR_NUM_PWR_PB_2_P48V_STBY_BUS8 0xE2
#define SENSOR_NUM_PWR_PB_2_P48V_AUX_BUS8 0xE3
#define SENSOR_NUM_TEMP_PB_3_HSC_BUS8 0xE4
#define SENSOR_NUM_VOL_PB_3_P48V_STBY_BUS8 0xE5
#define SENSOR_NUM_VOL_PB_3_P48V_AUX_BUS8 0xE6
#define SENSOR_NUM_CUR_PB_3_P48V_STBY_BUS8 0xE7
#define SENSOR_NUM_CUR_PB_3_P48V_AUX_BUS8 0xE8
#define SENSOR_NUM_PWR_PB_3_P48V_STBY_BUS8 0xE9
#define SENSOR_NUM_PWR_PB_3_P48V_AUX_BUS8 0xEA
/* Backplan board Level sensor number*/
#define SENSOR_NUM_BPB_Level_1_RACK 0xEB
#define SENSOR_NUM_BPB_Level_2_RACK 0xEC
#define SENSOR_NUM_BPB_Level_3_CDU 0xED
/* Sensor box pressure sensor number*/
#define SENSOR_NUM_PRESS_SB_ADS_1 0xEE
#define SENSOR_NUM_PRESS_SB_ADS_2 0xEF

uint8_t plat_get_config_size();
void load_sensor_config(void);
#endif

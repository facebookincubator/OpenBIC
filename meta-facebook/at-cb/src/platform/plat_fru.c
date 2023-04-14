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

#include "plat_fru.h"

#include <stdio.h>
#include <string.h>
#include <logging/log.h>
#include "fru.h"
#include "libutil.h"
#include "common_i2c_mux.h"
#include "plat_sensor_table.h"

LOG_MODULE_REGISTER(plat_fru);

const EEPROM_CFG plat_fru_config[] = {
	// ACB BIC fru
	{
		PUYA_P24C128F,
		CB_FRU_ID,
		CB_FRU_PORT,
		CB_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
	},
	// ACB FIO fru
	{
		ST_M24C64_W,
		FIO_FRU_ID,
		FIO_FRU_PORT,
		FIO_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
	},
	// ACCL_1 fru
	{
		PUYA_P24C128F,
		ACCL_1_FRU_ID,
		ACCL_1_6_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_1_6_FRU_MUX_ADDR,
		ACCL_1_7_FRU_MUX_CHAN,
		&i2c_7_accl_mutex,
	},
	// ACCL_2 fru
	{
		PUYA_P24C128F,
		ACCL_2_FRU_ID,
		ACCL_1_6_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_1_6_FRU_MUX_ADDR,
		ACCL_2_8_FRU_MUX_CHAN,
		&i2c_7_accl_mutex,
	},
	// ACCL_3 fru
	{
		PUYA_P24C128F,
		ACCL_3_FRU_ID,
		ACCL_1_6_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_1_6_FRU_MUX_ADDR,
		ACCL_3_9_FRU_MUX_CHAN,
		&i2c_7_accl_mutex,
	},
	// ACCL_4 fru
	{
		PUYA_P24C128F,
		ACCL_4_FRU_ID,
		ACCL_1_6_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_1_6_FRU_MUX_ADDR,
		ACCL_4_10_FRU_MUX_CHAN,
		&i2c_7_accl_mutex,
	},
	// ACCL_5 fru
	{
		PUYA_P24C128F,
		ACCL_5_FRU_ID,
		ACCL_1_6_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_1_6_FRU_MUX_ADDR,
		ACCL_5_11_FRU_MUX_CHAN,
		&i2c_7_accl_mutex,
	},
	// ACCL_6 fru
	{
		PUYA_P24C128F,
		ACCL_6_FRU_ID,
		ACCL_1_6_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_1_6_FRU_MUX_ADDR,
		ACCL_6_12_FRU_MUX_CHAN,
		&i2c_7_accl_mutex,
	},
	// ACCL_7 fru
	{
		PUYA_P24C128F,
		ACCL_7_FRU_ID,
		ACCL_7_12_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_7_12_FRU_MUX_ADDR,
		ACCL_1_7_FRU_MUX_CHAN,
		&i2c_8_accl_mutex,
	},
	// ACCL_8 fru
	{
		PUYA_P24C128F,
		ACCL_8_FRU_ID,
		ACCL_7_12_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_7_12_FRU_MUX_ADDR,
		ACCL_2_8_FRU_MUX_CHAN,
		&i2c_8_accl_mutex,
	},
	// ACCL_9 fru
	{
		PUYA_P24C128F,
		ACCL_9_FRU_ID,
		ACCL_7_12_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_7_12_FRU_MUX_ADDR,
		ACCL_3_9_FRU_MUX_CHAN,
		&i2c_8_accl_mutex,
	},
	// ACCL_10 fru
	{
		PUYA_P24C128F,
		ACCL_10_FRU_ID,
		ACCL_7_12_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_7_12_FRU_MUX_ADDR,
		ACCL_4_10_FRU_MUX_CHAN,
		&i2c_8_accl_mutex,
	},
	// ACCL_11 fru
	{
		PUYA_P24C128F,
		ACCL_11_FRU_ID,
		ACCL_7_12_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_7_12_FRU_MUX_ADDR,
		ACCL_5_11_FRU_MUX_CHAN,
		&i2c_8_accl_mutex,
	},
	// ACCL_12 fru
	{
		PUYA_P24C128F,
		ACCL_12_FRU_ID,
		ACCL_7_12_FRU_PORT,
		ACCL_FRU_ADDR,
		FRU_DEV_ACCESS_BYTE,
		FRU_START,
		FRU_SIZE,
		/* Because there has mux before eeprom, so mux_present is true to access mux first */
		true,
		ACCL_7_12_FRU_MUX_ADDR,
		ACCL_6_12_FRU_MUX_CHAN,
		&i2c_8_accl_mutex,
	},
};

void pal_load_fru_config(void)
{
	memcpy(&fru_config, &plat_fru_config, sizeof(plat_fru_config));
}

bool pal_get_accl_fru_config(uint8_t accl_fru_id, mux_config *mux_cfg)
{
	CHECK_NULL_ARG_WITH_RETURN(mux_cfg, false);

	uint8_t index = 0;

	for (index = 0; index < ARRAY_SIZE(plat_fru_config); ++index) {
		if (plat_fru_config[index].dev_id == accl_fru_id) {
			mux_cfg->bus = plat_fru_config[index].port;
			mux_cfg->target_addr = plat_fru_config[index].mux_addr;
			mux_cfg->channel = BIT(plat_fru_config[index].mux_channel);
			return true;
		}
	}

	LOG_ERR("Invalid fru id: 0x%x", accl_fru_id);
	return false;
}

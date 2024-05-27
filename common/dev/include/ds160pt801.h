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

#ifndef DS160PT801_H
#define DS160PT801_H

#include "plat_def.h"
#ifdef ENABLE_DS160PT801

#include "hal_i2c.h"

enum {
	DS160PT801_READ_TEMP,
};

bool ds160pt801_get_fw_version(I2C_MSG *i2c_msg, uint8_t *version);
uint8_t ds160pt801_fw_update(I2C_MSG *msg, uint32_t *offset, uint32_t *msg_len, uint8_t *msg_buf,
			     uint8_t flag);
bool ds160pt801_read_data(I2C_MSG *msg, uint16_t offset, uint8_t *rxbuf, uint16_t length);

#endif

#endif

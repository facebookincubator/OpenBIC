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

#include <stdbool.h>
#include <stdint.h>

#ifndef PLAT_CLASS_H
#define PLAT_CLASS_H

enum HSC_MODULE {
	HSC_MODULE_ADM1272,
	HSC_MODULE_XDP710,
	HSC_MODULE_UNKNOWN = 0xFF,
};
enum TEMP_MODULE {
	SB_TMP461,
	SB_NCT214,
	TEMP_MODULE_UNKNOWN = 0xFF,
};

uint8_t get_hsc_module();
uint8_t get_temp_module();
#endif

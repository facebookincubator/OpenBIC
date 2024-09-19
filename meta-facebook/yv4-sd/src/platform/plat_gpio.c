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

#include <logging/log.h>
#include <zephyr.h>
#include <stdio.h>
#include <string.h>
#include "cmsis_os.h"
#include "hal_gpio.h"
#include "plat_isr.h"
#include "plat_gpio.h"
#include "plat_isr.h"
#include "plat_class.h"

LOG_MODULE_REGISTER(plat_gpio);

#define gpio_name_to_num(x) #x,
char *gpio_name[] = {
	name_gpioA name_gpioB name_gpioC name_gpioD name_gpioE name_gpioF name_gpioG name_gpioH
		name_gpioI name_gpioJ name_gpioK name_gpioL name_gpioM name_gpioN name_gpioO
			name_gpioP name_gpioQ name_gpioR name_gpioS name_gpioT name_gpioU
};
#undef gpio_name_to_num

// clang-format off

/* chip,
 * number,
 * is_init,is_latch,
 * direction,
 * status,
 * property,
 * int_type,
 * int_cb,
*/

GPIO_CFG plat_gpio_cfg[] = {
	/** Group A: 00-07 **/
	{ CHIP_GPIO, 0, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 1, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_SLP3 },
	{ CHIP_GPIO, 2, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 3, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_DC_ON },
	{ CHIP_GPIO, 4, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_FALLING, ISR_CPU_SMERR_BIC },
	{ CHIP_GPIO, 5, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 6, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 7, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group B: 08-15 **/
	{ CHIP_GPIO, 8, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 9, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 10, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 11, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 12, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_FALLING, ISR_SOC_THMALTRIP },
	{ CHIP_GPIO, 13, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_FALLING, ISR_APML_ALERT },
	{ CHIP_GPIO, 14, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 15, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },

	/** Group C: 16-23 **/
	{ CHIP_GPIO, 16, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_PVDDCR_CPU0_PMALERT },
	{ CHIP_GPIO, 17, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_HSC_OC },
	{ CHIP_GPIO, 18, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 19, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_PVDDCR_CPU1_PMALERT },
	{ CHIP_GPIO, 20, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 21, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 22, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 23, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_LOW,  PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group D: 24-31 **/
	{ CHIP_GPIO, 24, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_LOW,  PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 25, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 26, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_MB_THROTTLE },
	{ CHIP_GPIO, 27, ENABLE, ENABLE, GPIO_OUTPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 28, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_SYS_THROTTLE },
	{ CHIP_GPIO, 29, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 30, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 31, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },

	/** Group E: 32-39 **/
	{ CHIP_GPIO, 32, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 33, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 34, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_POST_COMPLETE },
	{ CHIP_GPIO, 35, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_UV_DETECT },
	{ CHIP_GPIO, 36, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_PVDDCR_CPU0_OCP },
	{ CHIP_GPIO, 37, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_PVDDCR_CPU1_OCP },
	{ CHIP_GPIO, 38, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 39, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },

	/** Group F: 40-47 **/
	{ CHIP_GPIO, 40, ENABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 41, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 42, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_PVDD11_S3_PMALERT },
	{ CHIP_GPIO, 43, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 44, ENABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 45, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 46, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_DBP_PRSNT },
	{ CHIP_GPIO, 47, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group G: 48-55 **/
	{ CHIP_GPIO, 48, ENABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 49, ENABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_EDGE_BOTH, ISR_BMC_READY },
	{ CHIP_GPIO, 50, ENABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 51, ENABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_EDGE_FALLING, IST_PLTRST },
	{ CHIP_GPIO, 52, ENABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 53, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 54, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 55, ENABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },

	/** Group H: 56-63 **/
	{ CHIP_GPIO, 56, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 57, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 58, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 59, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 60, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 61, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 62, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 63, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group I: 64-71 **/
	{ CHIP_GPIO, 64, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 65, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 66, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 67, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 68, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 69, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 70, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 71, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group J: 72-79 **/
	{ CHIP_GPIO, 72, DISABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 73, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 74, DISABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 75, DISABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 76, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 77, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 78, DISABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 79, DISABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },

	/** Group K: 80-87 **/
	{ CHIP_GPIO, 80, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 81, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 82, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 83, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 84, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 85, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 86, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 87, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group L: 88-95 **/
	{ CHIP_GPIO, 88, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 89, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 90, ENABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 91, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 92, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 93, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 94, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 95, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group M: 96-103 **/
	{ CHIP_GPIO, 96, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 97, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 98, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 99, ENABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 100, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 101, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 102, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 103, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group N: 104-111 **/
	{ CHIP_GPIO, 104, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 105, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 106, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 107, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 108, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 109, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 110, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 111, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group O: 112-119 **/
	{ CHIP_GPIO, 112, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 113, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 114, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 115, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 116, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 117, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 118, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 119, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group P: 120-127 **/
	{ CHIP_GPIO, 120, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 121, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 122, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 123, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 124, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 125, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 126, DISABLE, DISABLE, GPIO_OUTPUT, GPIO_HIGH, OPEN_DRAIN, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 127, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group Q: 128-135 **/
	{ CHIP_GPIO, 128, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 129, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 130, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 131, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 132, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 133, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 134, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 135, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group R: 136-143 **/
	{ CHIP_GPIO, 136, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 137, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 138, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 139, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 140, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 141, DISABLE, DISABLE, GPIO_INPUT, GPIO_HIGH, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 142, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 143, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group S: 144-151 **/
	{ CHIP_GPIO, 144, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 145, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 146, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 147, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 148, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 149, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 150, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 151, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group T: 152-159 **/
	{ CHIP_GPIO, 152, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 153, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 154, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 155, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 156, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 157, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 158, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 159, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },

	/** Group U: 160-167 **/
	{ CHIP_GPIO, 160, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 161, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 162, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 163, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 164, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 165, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 166, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
	{ CHIP_GPIO, 167, DISABLE, DISABLE, GPIO_INPUT, GPIO_LOW, PUSH_PULL, GPIO_INT_DISABLE, NULL },
};

// clang-format on

bool pal_load_gpio_config(void)
{
	uint8_t board_revision = BOARD_REV_EVT;

	get_board_rev(&board_revision);

	if (board_revision <= BOARD_REV_EVT) {
		gpio_name[EVT_EXAMAX_RESERVED_1] = "EXAMAX_RESERVED_1";
		gpio_name[EVT_EXAMAX_RESERVED_2] = "EXAMAX_RESERVED_2";
		gpio_name[EVT_EXAMAX_RESERVED_3] = "EXAMAX_RESERVED_3";
		gpio_name[EVT_EXAMAX_RESERVED_4] = "EXAMAX_RESERVED_4";
		gpio_name[EVT_CPU_TYPE_1] = "CPU_TYPE1";
		gpio_name[EVT_RTM_IOEXP_INT_N] = "RTM_IOEXP_INT_N";
		plat_gpio_cfg[EVT_AUTH_COMPLETE].is_init = ENABLE;
		gpio_name[EVT_AUTH_COMPLETE] = "AUTH_COMPLETE";
		plat_gpio_cfg[EVT_BIC_READY_TOP_EXP].is_init = ENABLE;
		gpio_name[EVT_BIC_READY_TOP_EXP] = "BIC_READY_TOP_EXP";
		plat_gpio_cfg[EVT_RTM2_IOEXP_INT_N].is_init = ENABLE;
		gpio_name[EVT_RTM2_IOEXP_INT_N] = "RTM2_IOEXP_INT_N";
		gpio_name[EVT_SIDECAR_CABLE_PRESENT] = "SIDECAR_CABLE_PRESENT";
		gpio_name[EVT_CPU_BIC_RTC_GET_N] = "CPU_BIC_RTC_GET_N";
		plat_gpio_cfg[EVT_SMB_RTM1_INA233_ALRT_N].is_init = ENABLE;
		gpio_name[EVT_SMB_RTM1_INA233_ALRT_N] = "SMB_RTM1_INA233_ALRT_N";
		plat_gpio_cfg[EVT_SMB_RTM2_INA233_ALRT_N].is_init = ENABLE;
		gpio_name[EVT_SMB_RTM2_INA233_ALRT_N] = "SMB_RTM2_INA233_ALRT_N";
		plat_gpio_cfg[EVT_Reserve_GPIOM0].is_init = DISABLE;
		plat_gpio_cfg[EVT_MEDUSA_HSC_R_PG].is_init = ENABLE;
		gpio_name[EVT_MEDUSA_HSC_R_PG] = "MEDUSA_HSC_R_PG";
		plat_gpio_cfg[EVT_Reserve_GPIOM3].is_init = DISABLE;
		plat_gpio_cfg[EVT_BIC_READY_FRONT_EXP].is_init = ENABLE;
		gpio_name[EVT_BIC_READY_FRONT_EXP] = "BIC_READY_FRONT_EXP";
	}

	memcpy(&gpio_cfg[0], &plat_gpio_cfg[0], sizeof(plat_gpio_cfg));
	return 1;
};

void sync_bmc_ready_pin()
{
	uint8_t gpio_val = gpio_get(FM_CPLD_BMC_BIC_READY);
	gpio_set(BMC_READY, gpio_val);
}

void reset_usb_hub()
{
	if (gpio_get(BIC_READY_R) == HIGH_ACTIVE) {
		gpio_set(RST_USB_HUB_R_N, HIGH_ACTIVE);
		LOG_INF("Reset USB Hub");
	} else {
		LOG_ERR("Failed to reset USB Hub because BIC_READY_R is not active");
	}
}

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
#define I2C_MWR_MODBUS_DATA_SIZE 16 //16 registers(2 bytes each)
uint8_t modbus_command_i2c_master_write_read(modbus_command_mapping *cmd);
uint8_t modbus_command_i2c_master_write_read_response(modbus_command_mapping *cmd);

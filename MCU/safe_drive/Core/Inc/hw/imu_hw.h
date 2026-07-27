#ifndef HW_IMU_JW_H
#define HW_IMU_JW_H
#include "main.h"
#include <stdint.h>
#include <stdbool.h>

#define IMU_REG_TEMP_OUT_H 0x39 
#define IMU_REG_TEMP_OUT_L 0x3A


#define IMU_I2C_ADDRESS 0x69
#define IMU_REG_BANK_SEL 0x7F
#define IMU_REG_WHO_AM_I 0x00
#define IMU_REG_PWR_MGMT_1 0x06
#define IMU_REG_PWR_MGMT_2 0x07

#define IMU_WHO_AM_I_VALUE 0xEA

bool imu_hw_init(void);
bool imu_hw_alive(void);    

bool imu_hw_read_reg(uint8_t reg, uint8_t *data);
bool imu_hw_write_reg(uint8_t reg, uint8_t data);
bool imu_select_bank(uint8_t bank);

bool imu_hw_read_temp(float *temp);

#endif // HW_IMU_JW_H


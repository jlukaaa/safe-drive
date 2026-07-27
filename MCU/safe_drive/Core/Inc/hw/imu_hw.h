#ifndef HW_IMU_JW_H
#define HW_IMU_JW_H
#include "main.h"
#include <stdint.h>
#include <stdbool.h>

#define IMU_REG_TEMP_OUT_H 0x39 
#define IMU_REG_TEMP_OUT_L 0x3A

//Banka 0

#define IMU_REG_ACCEL_XOUT_H 0x2D
#define IMU_REG_GYRO_XOUT_H 0x33

// Banka 2

#define IMU_REG_ACCEL_CONFIG 0x14
#define IMU_REG_GYRO_CONFIG_1 0x01

#define IMU_ACCEL_SENS_4G 8192.0f
#define IMU_GYRO_SENS_500DPS 65.5f




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

bool imu_hw_config_ranges(void);
bool imu_hw_read_accel_g(float *ax, float *ay, float *az);
bool imu_hw_read_gyro_dps(float *gx, float *gy, float *gz);

#endif // HW_IMU_JW_H


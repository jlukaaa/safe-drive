#include "hw/imu_hw.h"
#include <stdio.h>

extern I2C_HandleTypeDef hi2c1;

#define IMU_I2C_TIMEOUT 100

bool imu_write_reg(uint8_t reg, uint8_t data)
{
    HAL_StatusTypeDef status = HAL_I2C_Mem_Write(&hi2c1, IMU_I2C_ADDRESS << 1, reg, I2C_MEMADD_SIZE_8BIT, &data, 1, IMU_I2C_TIMEOUT);
    return (status == HAL_OK);
}   

bool imu_read_reg(uint8_t reg, uint8_t *data)
{
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&hi2c1, IMU_I2C_ADDRESS << 1, reg, I2C_MEMADD_SIZE_8BIT, data, 1, IMU_I2C_TIMEOUT);
    return (status == HAL_OK);
}

bool imu_select_bank(uint8_t bank)
{
    uint8_t current_bank = (uint8_t)((bank & 0x03) << 4); // Ensure bank is within 0-3
    return imu_write_reg(IMU_REG_BANK_SEL, current_bank);
}

bool imu_hw_init(void)
{
    // Select bank 0
    if (!imu_select_bank(0)){
            printf("IMU: greska pri izboru banke za citanje temperature\r\n");
        return false;
    }
    if (!imu_write_reg(IMU_REG_PWR_MGMT_1, 0x80)) return false; // Set clock source to PLL

    HAL_Delay(100); // Wait for the device to reset

    if(!imu_select_bank(0)) return false;

    if(!imu_write_reg(IMU_REG_PWR_MGMT_1, 0x01)) {
    printf("IMU: greska pri citanju TEMP_OUT_L\r\n");
    return false; // Set clock source to PLL
    }

    HAL_Delay(100); // Wait for the device to stabilize
    return true;
}

bool imu_hw_alive(void)
{
    uint8_t who_am_i = 0;
    if (!imu_select_bank(0)) 
    {
        printf("IMU: greska pri izboru banke za WHO_AM_I citanje\r\n");
        return false;
    }

    if (!imu_read_reg(IMU_REG_WHO_AM_I, &who_am_i)){
        printf("IMU: greska pri citanju WHO_AM_I registra\r\n");
     return false;
    }

    if (who_am_i != IMU_WHO_AM_I_VALUE) {
        printf("IMU not alive, WHO_AM_I: 0x%02X\r\n", who_am_i); return false;
    }
    else
    {
        printf("IMU alive, WHO_AM_I: 0x%02X\r\n", who_am_i);
        return true;
    }
   
}

bool imu_hw_read_temp(float *temp)
{
    uint8_t temp_h = 0, temp_l = 0;

    /* Temperatura je u banci 0 */
    if (!imu_select_bank(0))
    {
        printf("IMU: greska pri izboru banke za citanje temperature\r\n");
        return false;
    }

    if (!imu_read_reg(IMU_REG_TEMP_OUT_H, &temp_h))
    {
        printf("IMU: greska pri citanju TEMP_OUT_H\r\n");
        return false;
    }

    if (!imu_read_reg(IMU_REG_TEMP_OUT_L, &temp_l))
    {
        printf("IMU: greska pri citanju TEMP_OUT_L\r\n");
        return false;
    }

    /* Spoji H i L bajt u 16-bitnu signed vrijednost */
    int16_t raw_temp = (int16_t)((temp_h << 8) | temp_l);

    /* Formula iz ICM-20948 datasheeta */
    *temp = ((float)raw_temp / 333.87f) + 21.0f;

    return true;
}

bool imu_hw_config_ranges(void)
{
    if (!imu_select_bank(2))
    {
        printf("IMU: GReska pri izboru banke 2\r\n");
        return false;
    }

    uint8_t accel_cfg = (0x01 << 1);
    if(!imu_write_reg(IMU_REG_ACCEL_CONFIG, accel_cfg))
    {
        printf("IMU: Greska pri konfiguraciji akcelerometra!\r\n");
        return false;
    }

    uint8_t gyro_cfg = (0x01 << 1);
    if(!imu_write_reg(IMU_REG_GYRO_CONFIG_1, gyro_cfg))
    {
        printf("IMU: Greska pri konfiguraciji ziroskopa!\r\n");
        return false;
    }
    if(!imu_select_bank(0))
    {
    printf("IMU: Greska pri povratku na banku 0!\r\n");
    return false;
    }

    return true;
}

bool imu_hw_read_accel_g(float *ax, float *ay, float *az)
{
    uint8_t raw[6] = {0};

    if(!imu_select_bank(0))
    {
        printf("IMU: greska pri izboru banke za citanje akcelerometra\r\n");
        return false;
    }

    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&hi2c1, (uint16_t)(IMU_I2C_ADDRESS << 1), 
    IMU_REG_ACCEL_XOUT_H, I2C_MEMADD_SIZE_8BIT, raw, 6, IMU_I2C_TIMEOUT);

    if (status != HAL_OK)
    {
        printf("IMU: greska pri citanju akcelerometra\r\n");
        return false;
    }

    int16_t raw_x = (int16_t)((raw[0] << 8) | raw[1]);
    int16_t raw_y = (int16_t)((raw[2] << 8) | raw[3]);
    int16_t raw_z = (int16_t)((raw[4] << 8) | raw[5]);

    *ax = (float)raw_x / IMU_ACCEL_SENS_4G;
    *ay = (float)raw_y / IMU_ACCEL_SENS_4G;
    *az = (float)raw_z / IMU_ACCEL_SENS_4G;

    return true;
}

bool imu_hw_read_gyro_dps(float *gx, float *gy, float *gz)
{
    uint8_t raw[6] = {0};

    if(!imu_select_bank(0))
    {
        printf("IMU: greska pri izboru banke za citanje ziroskopa\r\n");
        return false;
    }

    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&hi2c1, (uint16_t)(IMU_I2C_ADDRESS << 1),
     IMU_REG_GYRO_XOUT_H, I2C_MEMADD_SIZE_8BIT, raw, 6, IMU_I2C_TIMEOUT);

    if (status != HAL_OK)
    {
        printf("IMU: greska pri citanju ziroskopa\r\n");
        return false;
    }

    int16_t raw_x = (int16_t)((raw[0] << 8) | raw[1]);
    int16_t raw_y = (int16_t)((raw[2] << 8) | raw[3]);
    int16_t raw_z = (int16_t)((raw[4] << 8) | raw[5]);

    *gx = (float)raw_x / IMU_GYRO_SENS_500DPS;
    *gy = (float)raw_y / IMU_GYRO_SENS_500DPS;
    *gz = (float)raw_z / IMU_GYRO_SENS_500DPS;

    return true;
}   
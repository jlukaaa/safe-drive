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
#include "hw/distance_hw.h"
#include "stm32f4xx_hal_adc.h"
#include <stdint.h>
#include <stdio.h>


extern ADC_HandleTypeDef hadc1;

#define ADC_VREF        3.3f
#define ADC_MAX_VALUE   4095.0f

typedef struct 
{
    float voltage;
    float distance_cm;
} calib_point_t;

static const calib_point_t calib_table[] = {
    {2.20f, 4.0f},
    {2.12f, 6.0f},
    {2.00f, 10.0f},
    {1.77f, 15.0f},
    {1.55f, 20.0f},
    {1.36f, 25.0f},
    {1.00f, 30.0f},
    {0.75f, 40.0f},
    {0.27f, 50.0f}
};

#define CALIB_TABLE_SIZE (sizeof(calib_table) / sizeof(calib_table[0]))

void distance_hw_init(void)
{

}

static float voltage_to_distance(float voltage)
{

    if (voltage >= calib_table[0].voltage)
    {
        return calib_table[0].distance_cm;
    }

    if (voltage <= calib_table[CALIB_TABLE_SIZE - 1].voltage)
    {
        return calib_table[CALIB_TABLE_SIZE - 1].distance_cm;
    }

    for (uint32_t i = 0; i < CALIB_TABLE_SIZE - 1; i++)
    {
        float v_high = calib_table[i].voltage;
        float v_low = calib_table[i + 1].voltage;

        if (voltage <= v_high && voltage >= v_low)
        {
            float d_high = calib_table[i].distance_cm;
            float d_low = calib_table[i + 1].distance_cm;

            float ratio = (v_high - voltage) / (v_high - v_low);

            return d_high + ratio * (d_low - d_high);
        }
    }

    return DISTANCE_MAX_CM;
}

bool distance_hw_read_cm(float *distance_cm)
{
    if(HAL_ADC_Start(&hadc1) != HAL_OK)
    {
        printf("Distance: greska pri pokretanju ADC konverzije\r\n");
        return false;
    }

    if (HAL_ADC_PollForConversion(&hadc1, 10) != HAL_OK)
    {
        printf("Distance: ADC konverzija nije zavrsena na vrijeme\r\n");
        HAL_ADC_Stop(&hadc1);
        return false;
    }

    uint32_t raw_value = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    float voltage = ((float)raw_value / ADC_MAX_VALUE) * ADC_VREF;

    float distance = voltage_to_distance(voltage);

    if (distance < DISTANCE_MIN_CM) distance = DISTANCE_MIN_CM;
    if (distance > DISTANCE_MAX_CM) distance = DISTANCE_MAX_CM;

    *distance_cm = distance;
    return true;
}

bool distance_hw_read_voltage_debug(float *voltage_out)
{
    if (HAL_ADC_Start(&hadc1) != HAL_OK) return false;
    if (HAL_ADC_PollForConversion(&hadc1, 10) != HAL_OK)
    {
        HAL_ADC_Stop(&hadc1);
        return false;
    }

    uint32_t raw_value = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    *voltage_out = ((float)raw_value / ADC_MAX_VALUE) * ADC_VREF;
    return true;
}
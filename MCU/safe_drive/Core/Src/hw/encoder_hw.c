#include "hw/encoder_hw.h"
#include "main.h"

extern TIM_HandleTypeDef htim2;

static int16_t last_count = 0;

void encoder_hw_init(void)
{
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
    __HAL_TIM_SET_COUNTER(&htim2, 0);
    last_count = 0;
}

int16_t encoder_hw_get_count(void)
{
    return (int16_t)__HAL_TIM_GET_COUNTER(&htim2);
}

// Izračunava RPM na osnovu proteklog vremena (delta_ms) i broja impulsa po krugu (PPR)
float encoder_hw_get_rpm(uint32_t delta_ms, uint16_t ppr)
{
    if (delta_ms == 0 || ppr == 0) return 0.0f;

    int16_t current_count = encoder_hw_get_count();
    int16_t pulses = current_count - last_count;
    last_count = current_count;

    // RPM = (broj_impulsa / PPR) * (60000ms / delta_ms)
    return ((float)pulses / (float)ppr) * (60000.0f / (float)delta_ms);
}
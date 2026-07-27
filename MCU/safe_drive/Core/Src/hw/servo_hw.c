#include "hw/servo_hw.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include <stdint.h>

extern TIM_HandleTypeDef htim3;

#define DIR_GPIO_Pin GPIOE
#define DIR_Pin      GPIO_PIN_11

void servo_hw_init(void)
{
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

    HAL_GPIO_WritePin(DIR_GPIO_Pin, DIR_Pin, GPIO_PIN_RESET);

    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
}

void servo_hw_set_speed(int8_t speed)
{
    if (speed > 100) speed = 100;
    if (speed < -100) speed = -100;

    if (speed >= 0)
    {
        HAL_GPIO_WritePin(DIR_GPIO_Pin, DIR_Pin, GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(DIR_GPIO_Pin, DIR_Pin, GPIO_PIN_SET);
        speed = -speed;
    }

    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, (uint32_t)speed);
}
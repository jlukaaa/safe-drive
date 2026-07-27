#include "hw/fan_hw.h"
#include "main.h"

#define FAN_GPIO_PORT GPIOE
#define FAN_GPIO_PIN GPIO_PIN_10

void fan_hw_init(void)
{
    fan_hw_set(false);
}

void fan_hw_set(bool state)
{
    HAL_GPIO_WritePin(FAN_GPIO_PORT, FAN_GPIO_PIN, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void fan_hw_toggle(void)
{
    HAL_GPIO_TogglePin(FAN_GPIO_PORT, FAN_GPIO_PIN);
}
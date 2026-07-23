#include "main.h"
#include "stm32f4xx_hal_gpio.h"
#include "touch_hw.h"
#include <stdint.h>
#include <stdbool.h>


static volatile uint32_t last_exit_tick = 0;
static bool is_btn_pressed = false;
static uint32_t press_start_tick = 0;
static uint32_t press_dur = 0;

#define DEBOUNCE_DELAY_MS 20

void touch_hw_init(void)
{
    last_exit_tick = 0;
    is_btn_pressed = false;
    press_start_tick = 0;
    press_dur = 0;
}

void touch_hw_on_exti(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == USER_Btn_Pin || GPIO_Pin == GPIO_PIN_13)
    {
        uint32_t now = HAL_GetTick();

        if (now - last_exit_tick >= DEBOUNCE_DELAY_MS)
        {
            
            last_exit_tick = now;

            GPIO_PinState pin_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

            if (pin_state == GPIO_PIN_RESET)
            {
                if (!is_btn_pressed)
                {
                    is_btn_pressed = true;
                    press_start_tick = now;
                    HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
                }
            }
            else
            {
                if (is_btn_pressed)
                {
                    is_btn_pressed = false;
                    press_dur = now - press_start_tick;
                }
            }
        }
    }
}

void touch_hw_update(void)
{
    GPIO_PinState state = HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin);

    if (state == GPIO_PIN_SET)
    {
        if (!is_btn_pressed)
        {
            is_btn_pressed = true;
            press_start_tick = HAL_GetTick();
        }

        press_dur = HAL_GetTick() - press_start_tick;
    }

    else

    {
        is_btn_pressed = false;
        press_dur = 0;
    }
}

bool touch_is_pressed(void)
{
    return is_btn_pressed;
}

uint32_t touch_get_press_dur_mil(void)
{
    return press_dur;
}
#ifndef TOUCH_HW_H
#define TOUCH_HW_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

void touch_hw_init(void);

void touch_hw_on_exti(uint16_t GPIO_Pin);

void touch_hw_update(void);

bool touch_is_pressed(void);

uint32_t touch_get_press_dur_mil(void);


#endif


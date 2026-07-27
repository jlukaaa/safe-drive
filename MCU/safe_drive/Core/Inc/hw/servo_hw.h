#ifndef SERVO_HW_H
#define SERVO_HW_H

#include "main.h"
#include <stdint.h>
#include <stdbool.h>

void servo_hw_init(void);

void servo_hw_set_speed(int8_t speed);


#endif


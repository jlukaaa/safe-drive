#ifndef DISTANCE_HW_H
#define DISTANCE_HW_H

#include "main.h"
#include <stdint.h>
#include <stdbool.h>

#define DISTANCE_MIN_CM 4.0f
#define DISTANCE_MAX_CM 50.0f

void distance_hw_init(void);

bool distance_hw_read_cm(float *distance_cm);
bool distance_hw_read_voltage_debug(float *voltage_out);

#endif // HW_DISTANCE_HW_H


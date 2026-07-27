#ifndef FAN_HW_H
#define FAN_HW_H

#include <stdbool.h>

void fan_hw_init(void);
void fan_hw_set(bool state);
void fan_hw_toggle(void);

#endif


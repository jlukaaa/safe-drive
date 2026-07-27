#ifndef ENCODER_HW_H
#define ENCODER_HW_H

#include <stdint.h>

void encoder_hw_init(void);
int16_t encoder_hw_get_count(void);
float encoder_hw_get_rpm(uint32_t delta_ms, uint16_t ppr);

#endif // ENCODER_HW_H
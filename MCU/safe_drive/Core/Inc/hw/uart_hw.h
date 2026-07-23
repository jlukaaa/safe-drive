#ifndef UART_HW_H
#define UART_HW_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

#define UART_RING_BUF_SIZE 128

void uart_hw_init(UART_HandleTypeDef *huart);

bool uart_hw_read_byte(uint8_t *byte);

void uart_hw_update(void);

#endif /* UART_HW_H */
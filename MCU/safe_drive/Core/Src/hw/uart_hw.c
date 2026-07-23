#include "uart_hw.h"
#include <stdio.h>
#include <string.h>

static UART_HandleTypeDef *p_huart = NULL;

static uint8_t ring_buffer[UART_RING_BUF_SIZE];
static volatile uint16_t head = 0;
static uint16_t tail = 0;
static uint8_t rx_byte = 0;

static char line_buffer[UART_RING_BUF_SIZE];
static uint16_t line_idx = 0;

void uart_hw_init(UART_HandleTypeDef *huart)
{
    p_huart = huart;
    head = 0;
    tail = 0;
    line_idx = 0;

    HAL_UART_Receive_IT(p_huart, &rx_byte, 1);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == p_huart->Instance)
    {
        uint16_t next_head = (head + 1) % UART_RING_BUF_SIZE;

        if (next_head != tail)
        {
            ring_buffer[head] = rx_byte;
            head = next_head;
        }

        HAL_UART_Receive_IT(p_huart, &rx_byte, 1);
    }
}


bool uart_hw_read_byte(uint8_t *byte)
{
    if (head == tail)
    {
        return false; // Bafer je prazan
    }

    *byte = ring_buffer[tail];
    tail = (tail + 1) % UART_RING_BUF_SIZE;
    return true;
}

void uart_hw_update(void)
{
    uint8_t c;

    while (uart_hw_read_byte(&c))
    {

        if (c == '\n' || c == '\r')
        {

            if (line_idx > 0)
            {
                line_buffer[line_idx] = '\0'; 
                if (strcmp(line_buffer, "1") == 0)
                {
                    HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
                    printf("OK: LD1 toglan!\r\n");
                }
                else if (strcmp(line_buffer, "2") == 0)
                {
                    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
                    printf("OK: LD2 toglan!\r\n");
                }
                else if (strcmp(line_buffer, "3") == 0)
                {
                    HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
                    printf("OK: LD3 toglan!\r\n");
                }
                else
                {
                    printf("Nepoznata komanda: '%s'\r\n", line_buffer);
                }
            }

            line_idx = 0;
        }
        else
        {
            if (line_idx < (UART_RING_BUF_SIZE - 1))
            {
                line_buffer[line_idx++] = c;
            }
            else
            {
                line_idx = 0; 
            }
        }
    }
}
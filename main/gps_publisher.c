#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"

#define UART_PORT UART_NUM_2
#define BUF_SIZE 4095

void setup() {
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(UART_PORT, &uart_config);
    uart_set_pin(UART_PORT, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_PORT, BUF_SIZE * 2, BUF_SIZE * 2, 10, NULL, 0);
}


void uart_task()
{
    int count = 0;
    char a;
    char gpsBuffer[BUF_SIZE];
    char* gpsMessage;

    while (uart_read_bytes(UART_PORT, (uint8_t*)&a, 1, portMAX_DELAY) > 0) {
        if (count < BUF_SIZE) {
            gpsBuffer[count] = a;
            count++;
        }
    }

    gpsMessage = gpsBuffer;

    printf("%s\n", gpsMessage);
    printf("===========================\n");
    vTaskDelay(pdMS_TO_TICKS(5000));

}

void app_main(void)
{
  xTaskCreate(uart_task, "uart_task", 2048, NULL, 10, NULL);
}

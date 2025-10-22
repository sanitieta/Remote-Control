//
// Created by xuhao on 2025/10/22.
//

#include "RemoteController.h"
#include "usart.h"
#include "dma.h"

extern RemoteController remoteController;

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
    if (huart == &huart3) {
        // 处理接收到的数据
        remoteController.connect_state() = true;
        remoteController.handle(Size);
    }
}
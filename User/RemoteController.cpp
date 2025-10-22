//
// Created by xuhao on 2025/10/22.
//

#include "RemoteController.h"
#include "usart.h"

void RemoteController::init() {
    // 初始化遥控器相关设置
    HAL_UARTEx_ReceiveToIdle_DMA(&huart3, rx_data, sizeof(rx_data));
}
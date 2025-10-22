//
// Created by xuhao on 2025/10/22.
//
#include "stm32f4xx_hal.h"
#include "RemoteController.h"
#include "usart.h"
#include <string.h>

void RemoteController::init(UART_HandleTypeDef* huart) {
    // 初始化遥控器相关设置
    this->huart_ = huart;
    // 启动DMA接收
    HAL_UARTEx_ReceiveToIdle_DMA(huart, rx_dma_buffer_, RX_DMA_BUFFER_SIZE);
}

void RemoteController::handle(uint16_t Size) {
    if (Size != FRAME_SIZE) { return; }
    memcpy(rx_data_, rx_dma_buffer_, FRAME_SIZE);

    // 解包数据
    data_.ch0 = (static_cast<int16_t>(rx_data_[0]) | (static_cast<int16_t>(rx_data_[1]) << 8)) & 0x07FF;
    data_.ch1 = ((static_cast<int16_t>(rx_data_[1]) >> 3) | (static_cast<int16_t>(rx_data_[2]) << 5)) & 0x07FF;
    data_.ch2 = ((static_cast<int16_t>(rx_data_[2]) >> 6) | (static_cast<int16_t>(rx_data_[3]) << 2) | (static_cast<
        int16_t>(rx_data_[4]) << 10)) & 0x07FF;
    data_.ch3 = ((static_cast<int16_t>(rx_data_[4]) >> 1) | (static_cast<int16_t>(rx_data_[5]) << 7)) & 0x07FF;
    data_.s1 = ((rx_data_[5] >> 4) & 0x000C) >> 2;
    data_.s2 = ((rx_data_[5] >> 4) & 0x0003);
    data_.mouse_x = static_cast<int16_t>(rx_data_[6]) | (static_cast<int16_t>(rx_data_[7]) << 8);
    data_.mouse_y = static_cast<int16_t>(rx_data_[8]) | (static_cast<int16_t>(rx_data_[9]) << 8);
    data_.mouse_z = static_cast<int16_t>(rx_data_[10]) | (static_cast<int16_t>(rx_data_[11]) << 8);
    data_.mouse_press_l = rx_data_[12];
    data_.mouse_press_r = rx_data_[13];
    data_.key = static_cast<int16_t>(rx_data_[14]) | (static_cast<int16_t>(rx_data_[15]) << 8);

    // 重新开启接收
    HAL_UARTEx_ReceiveToIdle_DMA(huart_, rx_dma_buffer_, RX_DMA_BUFFER_SIZE);
}

bool& RemoteController::connect_state() {
    return isConnected;
}
//
// Created by xuhao on 2025/10/22.
//

#ifndef REMOTE_CONTROL_REMOTECONTROLLER_H
#define REMOTE_CONTROL_REMOTECONTROLLER_H
#include "stm32f4xx_hal.h"

class RemoteController {
private:
    static constexpr size_t RX_DMA_BUFFER_SIZE = 512;
    static constexpr size_t FRAME_SIZE = 18;

    uint8_t rx_dma_buffer_[RX_DMA_BUFFER_SIZE]{ 0 };
    uint8_t rx_data_[FRAME_SIZE]{ 0 };
    UART_HandleTypeDef* huart_;
    bool isConnected = false; // 连接状态
    uint32_t last_rx_tick_ = 0; // 上次接收数据的tick

    struct Data {
        uint16_t ch0 = 0, ch1 = 0, ch2 = 0, ch3 = 0;
        uint8_t s1 = 0, s2 = 0;
        int16_t mouse_x = 0, mouse_y = 0, mouse_z = 0;
        uint8_t mouse_press_l = 0, mouse_press_r = 0;
        uint16_t key = 0;
    } data_;

public:
    void init(UART_HandleTypeDef* huart);
    void handle(uint16_t Size);
    bool& connect_state();
};


#endif //REMOTE_CONTROL_REMOTECONTROLLER_H
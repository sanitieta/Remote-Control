//
// Created by xuhao on 2025/10/22.
//

#ifndef REMOTE_CONTROL_REMOTECONTROLLER_H
#define REMOTE_CONTROL_REMOTECONTROLLER_H
#include "stm32f4xx_hal.h"

class RemoteController {
private:
    bool isConnected = false;
    uint8_t tx_data[1024]{0};
    uint8_t rx_data[1024]{0};

public:
    RemoteController();
    void init();
    void handle();
    bool connect();

};


#endif //REMOTE_CONTROL_REMOTECONTROLLER_H
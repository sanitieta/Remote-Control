#include "remote_controller_c_api.h"
#include "RemoteController.h"

RemoteController remoteController;

void RemoteController_Init(UART_HandleTypeDef *huart_) {
    remoteController.init(huart_);
}


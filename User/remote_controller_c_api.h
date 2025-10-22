#ifndef REMOTE_CONTROLLER_IF_H
#define REMOTE_CONTROLLER_IF_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "stm32f4xx_hal.h"
// 初始化遥控器
void RemoteController_Init(UART_HandleTypeDef* huart_);

#ifdef __cplusplus
}
#endif

#endif
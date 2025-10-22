#include "remote_controller_c_api.h"
#include "RemoteController.h"

static RemoteController remoteController;

void RemoteController_Init(void) {
    remoteController.init();
}


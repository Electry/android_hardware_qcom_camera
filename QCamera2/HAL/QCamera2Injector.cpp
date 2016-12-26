#define LOG_TAG "QCamera2Injector"

#include "QCamera2Injector.h"

namespace qcamera {

void QCamera2Injector::inject(cam_capability_t *camCapability, int cameraId)
{
    ALOGE("%s: Injecting camera parameters for cameraId=%d",
            __func__, cameraId);
}

}; // namespace qcamera

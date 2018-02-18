#define LOG_TAG "QCamera2Injector"

#include "QCamera2Injector.h"

namespace qcamera {

void QCamera2Injector::inject(cam_capability_t *camCapability, int cameraId)
{
    ALOGE("%s: Injecting camera parameters for cameraId=%d",
            __func__, cameraId);

    if (cameraId == CAM_POSITION_BACK) {
        /* supported HFR */
        camCapability->hfr_tbl_cnt = 1;
        camCapability->hfr_tbl[0].mode = CAM_HFR_MODE_60FPS;
    }
}

}; // namespace qcamera

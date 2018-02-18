#define LOG_TAG "QCamera2Injector"

#include "QCamera2Injector.h"

namespace qcamera {

void QCamera2Injector::inject(cam_capability_t *camCapability, int cameraId)
{
    int i;

    ALOGE("%s: Injecting camera parameters for cameraId=%d",
            __func__, cameraId);

    if (cameraId == CAM_POSITION_BACK) {
        /* supported HFR */
        camCapability->hfr_tbl_cnt = 1;
        camCapability->hfr_tbl[0].mode = CAM_HFR_MODE_60FPS;

        /* supported preview sizes */
        for (i = camCapability->preview_sizes_tbl_cnt; i > 0; i--)
            camCapability->preview_sizes_tbl[i] = camCapability->preview_sizes_tbl[i - 1];
        camCapability->preview_sizes_tbl[0] = {4096, 2160};
        camCapability->preview_sizes_tbl_cnt++;

        /* supported video sizes */
        for (i = camCapability->video_sizes_tbl_cnt; i > 0; i--)
            camCapability->video_sizes_tbl[i] = camCapability->video_sizes_tbl[i - 1];
        camCapability->video_sizes_tbl[0] = {4096, 2160};
        camCapability->video_sizes_tbl_cnt++;

    }

    /* supported fps ranges */
    camCapability->fps_ranges_tbl_cnt = 2;
    camCapability->fps_ranges_tbl[1] = {30.0f, 30.0f, 30.0f, 30.0f};
}

}; // namespace qcamera

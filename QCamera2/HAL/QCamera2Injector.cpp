#define LOG_TAG "QCamera2Injector"

#include "QCamera2Injector.h"

#define CAMERA_FRONT_ID 0

namespace qcamera {


void QCamera2Injector::inject(cam_capability_t *camCapability, int cameraId)
{
    size_t s;

    ALOGE("%s: Injecting camera parameters for cameraId=%d",
            __func__, cameraId);

    camCapability->version = CAM_HAL_V1;
    camCapability->position =
            cameraId == CAMERA_FRONT_ID ? CAM_POSITION_FRONT : CAM_POSITION_BACK;

    //camCapability->auto_hdr_supported = auto_hdr_supported; // NOT IN THIS BRANCH

    /* supported iso modes */
    for (s = 0; s < supported_iso_modes_cnt; s++)
        camCapability->supported_iso_modes[s] = supported_iso_modes[s];
    camCapability->supported_iso_modes_cnt = supported_iso_modes_cnt;

    /* supported exposure time */
    camCapability->min_exposure_time = min_exposure_time;
    camCapability->max_exposure_time = max_exposure_time;

    /* supported flash modes */
    for (s = 0; s < supported_flash_modes_cnt; s++)
        camCapability->supported_flash_modes[s] = supported_flash_modes[s];
    camCapability->supported_flash_modes_cnt = supported_flash_modes_cnt;

    /* supported zoom ratios */
    for (s = 0; s < zoom_ratio_tbl_cnt; s++)
        camCapability->zoom_ratio_tbl[s] = zoom_ratio_tbl[s];
    camCapability->zoom_ratio_tbl_cnt = zoom_ratio_tbl_cnt;

    /* supported effect modes */
    for (s = 0; s < supported_effects_cnt; s++)
        camCapability->supported_effects[s] = supported_effects[s];
    camCapability->supported_effects_cnt = supported_effects_cnt;

    /* supported scene modes */
    for (s = 0; s < supported_scene_modes_cnt; s++)
        camCapability->supported_scene_modes[s] = supported_scene_modes[s];
    camCapability->supported_scene_modes_cnt = supported_scene_modes_cnt;

    /* supported auto exposure modes */
    for (s = 0; s < supported_aec_modes_cnt; s++)
        camCapability->supported_aec_modes[s] = supported_aec_modes[s];
    camCapability->supported_aec_modes_cnt = supported_aec_modes_cnt;

    /* supported fps ranges */
    for (s = 0; s < fps_ranges_tbl_cnt; s++)
        camCapability->fps_ranges_tbl[s] = fps_ranges_tbl[s];
    camCapability->fps_ranges_tbl_cnt = fps_ranges_tbl_cnt;

    /* supported antibanding modes */
    for (s = 0; s < supported_antibandings_cnt; s++)
        camCapability->supported_antibandings[s] = supported_antibandings[s];
    camCapability->supported_antibandings_cnt = supported_antibandings_cnt;

    /* supported white balance modes */
    for (s = 0; s < supported_white_balances_cnt; s++)
        camCapability->supported_white_balances[s] = supported_white_balances[s];
    camCapability->supported_white_balances_cnt = supported_white_balances_cnt;

    /* supported manual wb cct */
    camCapability->min_wb_cct = min_wb_cct;
    camCapability->max_wb_cct = max_wb_cct;

    /* supported focus modes */
    for (s = 0; s < supported_focus_modes_cnt; s++)
        camCapability->supported_focus_modes[s] = supported_focus_modes[s];
    camCapability->supported_focus_modes_cnt = supported_focus_modes_cnt;

    /* supported manual focus position */
    for (s = 0; s < (sizeof(min_focus_pos)/sizeof(min_focus_pos[0])); s++)
        camCapability->min_focus_pos[s] = min_focus_pos[s];
        camCapability->max_focus_pos[s] = max_focus_pos[s];

    /* supported exposure compensation */
    camCapability->exposure_compensation_min = exposure_compensation_min;
    camCapability->exposure_compensation_max = exposure_compensation_max;
    camCapability->exposure_compensation_default = exposure_compensation_default;
    camCapability->exposure_compensation_step = exposure_compensation_step;
    camCapability->exp_compensation_step = exp_compensation_step;

    /* supported video stabilization */
    camCapability->video_stablization_supported = video_stablization_supported;

    /* supported picture sizes */
    for (s = 0; s < picture_sizes_tbl_cnt; s++)
        camCapability->picture_sizes_tbl[s] = picture_sizes_tbl[s];
    camCapability->picture_sizes_tbl_cnt = picture_sizes_tbl_cnt;

    /* capabilities specific to HAL 1 */

    camCapability->modes_supported = modes_supported;
    camCapability->sensor_mount_angle = sensor_mount_angle;

    camCapability->focal_length = focal_length;
    camCapability->hor_view_angle = hor_view_angle;
    camCapability->ver_view_angle = ver_view_angle;

    /* supported preview sizes */
    for (s = 0; s < preview_sizes_tbl_cnt; s++)
        camCapability->preview_sizes_tbl[s] = preview_sizes_tbl[s];
    camCapability->preview_sizes_tbl_cnt = preview_sizes_tbl_cnt;

    /* supported video sizes */
    for (s = 0; s < video_sizes_tbl_cnt; s++)
        camCapability->video_sizes_tbl[s] = video_sizes_tbl[s];
    camCapability->video_sizes_tbl_cnt = video_sizes_tbl_cnt;

    /* supported livesnapshot sizes */
    for (s = 0; s < livesnapshot_sizes_tbl_cnt; s++)
        camCapability->livesnapshot_sizes_tbl[s] = livesnapshot_sizes_tbl[s];
    camCapability->livesnapshot_sizes_tbl_cnt = livesnapshot_sizes_tbl_cnt;

    /* supported HFR */
    for (s = 0; s < hfr_tbl_cnt; s++)
        camCapability->hfr_tbl[s] = hfr_tbl[s];
    camCapability->hfr_tbl_cnt = hfr_tbl_cnt;

    /* supported preview formats */
    for (s = 0; s < supported_preview_fmt_cnt; s++)
        camCapability->supported_preview_fmts[s] = supported_preview_fmts[s];
    camCapability->supported_preview_fmt_cnt = supported_preview_fmt_cnt;

    /* supported picture formats */
    for (s = 0; s < supported_picture_fmt_cnt; s++)
        camCapability->supported_picture_fmts[s] = supported_picture_fmts[s];
    camCapability->supported_picture_fmt_cnt = supported_picture_fmt_cnt;

    /* dimension and supported output format of raw dump from camif */
    camCapability->raw_dim = raw_dim;
    for (s = 0; s < supported_raw_fmt_cnt; s++)
        camCapability->supported_raw_fmts[s] = supported_raw_fmts[s];
    camCapability->supported_raw_fmt_cnt = supported_raw_fmt_cnt;

    /* supported focus algorithms */
    for (s = 0; s < supported_focus_algos_cnt; s++)
        camCapability->supported_focus_algos[s] = supported_focus_algos[s];
    camCapability->supported_focus_algos_cnt = supported_focus_algos_cnt;

    camCapability->auto_wb_lock_supported = auto_wb_lock_supported;
    camCapability->zoom_supported = zoom_supported;
    camCapability->smooth_zoom_supported = smooth_zoom_supported;
    camCapability->auto_exposure_lock_supported = auto_exposure_lock_supported;
    camCapability->video_snapshot_supported = video_snapshot_supported;

    camCapability->max_num_roi = max_num_roi;
    camCapability->max_num_focus_areas = max_num_focus_areas;
    camCapability->max_num_metering_areas = max_num_metering_areas;
    camCapability->max_zoom_step = max_zoom_step;

    /* QCOM specific control */
    camCapability->brightness_ctrl = brightness_ctrl;
    camCapability->sharpness_ctrl = sharpness_ctrl;
    camCapability->contrast_ctrl = contrast_ctrl;
    camCapability->saturation_ctrl = saturation_ctrl;
    camCapability->sce_ctrl = sce_ctrl;

    //camCapability->hdr_bracketing_setting = hdr_bracketing_setting;

    camCapability->qcom_supported_feature_mask = qcom_supported_feature_mask;
    camCapability->padding_info = padding_info;

    camCapability->min_num_pp_bufs = min_num_pp_bufs;
    camCapability->min_required_pp_mask = min_required_pp_mask;
}

}; // namespace qcamera

#define LOG_TAG "QCamera2K920"

#include "QCamera2Injector.h"

namespace qcamera {

#define FRONT_CAMERA 0
#define BACK_CAMERA 1

uint8_t QCamera2Injector::auto_hdr_supported = 1;

/* supported iso modes */
size_t QCamera2Injector::supported_iso_modes_cnt = 7;
cam_iso_mode_type QCamera2Injector::supported_iso_modes[] = {
    CAM_ISO_MODE_AUTO,
    CAM_ISO_MODE_DEBLUR,
    CAM_ISO_MODE_100,
    CAM_ISO_MODE_200,
    CAM_ISO_MODE_400,
    CAM_ISO_MODE_800,
    CAM_ISO_MODE_1600
};

/* supported exposure time */
int32_t QCamera2Injector::min_exposure_time = 200;
int32_t QCamera2Injector::max_exposure_time = 2000000;

/* supported flash modes */
size_t QCamera2Injector::supported_flash_modes_cnt = 4;
cam_flash_mode_t QCamera2Injector::supported_flash_modes[] = {
    CAM_FLASH_MODE_OFF,
    CAM_FLASH_MODE_AUTO,
    CAM_FLASH_MODE_ON,
    CAM_FLASH_MODE_TORCH
};

/* supported zoom ratios */
size_t QCamera2Injector::zoom_ratio_tbl_cnt = 49;
uint32_t QCamera2Injector::zoom_ratio_tbl[] = {
    100,102,104,107,109,
    112,114,117,120,123,
    125,128,131,135,138,
    141,144,148,151,155,
    158,162,166,170,174,
    178,182,186,190,195,
    200,204,209,214,219,
    224,229,235,240,246,
    251,257,263,270,276,
    282,289,296,303
};

/* supported effect modes */
size_t QCamera2Injector::supported_effects_cnt = 12;
cam_effect_mode_type QCamera2Injector::supported_effects[] = {
    CAM_EFFECT_MODE_OFF,
    CAM_EFFECT_MODE_MONO,
    CAM_EFFECT_MODE_NEGATIVE,
    CAM_EFFECT_MODE_SOLARIZE,
    CAM_EFFECT_MODE_SEPIA,
    CAM_EFFECT_MODE_POSTERIZE,
    CAM_EFFECT_MODE_WHITEBOARD,
    CAM_EFFECT_MODE_BLACKBOARD,
    CAM_EFFECT_MODE_AQUA,
    CAM_EFFECT_MODE_EMBOSS,
    CAM_EFFECT_MODE_SKETCH,
    CAM_EFFECT_MODE_NEON
};

/* supported scene modes */
size_t QCamera2Injector::supported_scene_modes_cnt = 20;
cam_scene_mode_type QCamera2Injector::supported_scene_modes[] = {
    CAM_SCENE_MODE_OFF,
    CAM_SCENE_MODE_AUTO,
    CAM_SCENE_MODE_LANDSCAPE,
    CAM_SCENE_MODE_SNOW,
    CAM_SCENE_MODE_BEACH,
    CAM_SCENE_MODE_SUNSET,
    CAM_SCENE_MODE_NIGHT,
    CAM_SCENE_MODE_PORTRAIT,
    CAM_SCENE_MODE_BACKLIGHT,
    CAM_SCENE_MODE_SPORTS,
    CAM_SCENE_MODE_ANTISHAKE,
    CAM_SCENE_MODE_FLOWERS,
    CAM_SCENE_MODE_CANDLELIGHT,
    CAM_SCENE_MODE_FIREWORKS,
    CAM_SCENE_MODE_PARTY,
    CAM_SCENE_MODE_NIGHT_PORTRAIT,
    CAM_SCENE_MODE_THEATRE,
    CAM_SCENE_MODE_ACTION,
    CAM_SCENE_MODE_AR,
    CAM_SCENE_MODE_HDR
};

/* supported auto exposure modes */
size_t QCamera2Injector::supported_aec_modes_cnt = 5;
cam_auto_exposure_mode_type QCamera2Injector::supported_aec_modes[] = {
    CAM_AEC_MODE_FRAME_AVERAGE,
    CAM_AEC_MODE_CENTER_WEIGHTED,
    CAM_AEC_MODE_SPOT_METERING,
    CAM_AEC_MODE_SPOT_METERING_ADV,
    CAM_AEC_MODE_CENTER_WEIGHTED_ADV
};

/* supported fps ranges */
size_t QCamera2Injector::fps_ranges_tbl_cnt = 1;
cam_fps_range_t QCamera2Injector::fps_ranges_tbl[] = {
    {7.5f, 30.0f, 7.5f, 30.0f}
};

/* supported antibanding modes */
size_t QCamera2Injector::supported_antibandings_cnt = 4;
cam_antibanding_mode_type QCamera2Injector::supported_antibandings[] = {
    CAM_ANTIBANDING_MODE_OFF,
    CAM_ANTIBANDING_MODE_60HZ,
    CAM_ANTIBANDING_MODE_50HZ,
    CAM_ANTIBANDING_MODE_AUTO
};

/* supported white balance modes */
size_t QCamera2Injector::supported_white_balances_cnt = 9;
cam_wb_mode_type QCamera2Injector::supported_white_balances[] = {
    CAM_WB_MODE_AUTO,
    CAM_WB_MODE_INCANDESCENT,
    CAM_WB_MODE_FLUORESCENT,
    CAM_WB_MODE_WARM_FLUORESCENT,
    CAM_WB_MODE_DAYLIGHT,
    CAM_WB_MODE_CLOUDY_DAYLIGHT,
    CAM_WB_MODE_TWILIGHT,
    CAM_WB_MODE_SHADE,
    CAM_WB_MODE_CCT
};

/* supported manual wb cct */
int32_t QCamera2Injector::min_wb_cct = 2000;
int32_t QCamera2Injector::max_wb_cct = 8000;

/* supported focus modes */
size_t QCamera2Injector::supported_focus_modes_cnt = 6;
cam_focus_mode_type QCamera2Injector::supported_focus_modes[] = {
    CAM_FOCUS_MODE_AUTO,
    CAM_FOCUS_MODE_INFINITY,
    CAM_FOCUS_MODE_MACRO,
    CAM_FOCUS_MODE_CONTINOUS_VIDEO,
    CAM_FOCUS_MODE_CONTINOUS_PICTURE,
    CAM_FOCUS_MODE_MANUAL
};

/* supported manual focus position */
int32_t QCamera2Injector::min_focus_pos[] = {
    //index, dac
    0, 0
};
int32_t QCamera2Injector::max_focus_pos[] = {
    47, 1023
};

/* supported exposure compensation */
int32_t QCamera2Injector::exposure_compensation_min = -12;
int32_t QCamera2Injector::exposure_compensation_max = 12;
int32_t QCamera2Injector::exposure_compensation_default = 0;
float QCamera2Injector::exposure_compensation_step = 0.166667f;
cam_rational_type_t QCamera2Injector::exp_compensation_step = {1, 6};

/* supported video stabilization */
uint8_t QCamera2Injector::video_stablization_supported = 0;

/* supported picture sizes */
size_t QCamera2Injector::picture_sizes_tbl_cnt = 31;
cam_dimension_t QCamera2Injector::picture_sizes_tbl[] = {
    {5328, 3000},
    {4864, 2736},
    {4208, 3000},
    {4000, 3000},
    {4096, 2160},
    {3840, 2160},
    {3664, 2748},
    {4224, 2376},
    {3840, 2160},
    {3280, 2460},
    {3200, 2400},
    {2832, 2124},
    {3264, 1836},
    {3200, 1800},
    {2592, 1944},
    {2560, 1440},
    {2048, 1536},
    {1920, 1440},
    {1920, 1080},
    {1600, 1200},
    {1440, 1080},
    {1280, 768},
    {1280, 720},
    {1024, 768},
    {800, 600},
    {800, 480},
    {720, 480},
    {640, 480},
    {352, 288},
    {320, 240},
    {176, 144}
};

/* capabilities specific to HAL 1 */

int32_t QCamera2Injector::modes_supported = CAM_MODE_2D;
uint32_t QCamera2Injector::sensor_mount_angle = 0;

float QCamera2Injector::focal_length = 4.3f;
float QCamera2Injector::hor_view_angle = 69.6f;
float QCamera2Injector::ver_view_angle = 42.6f;

/* supported preview sizes */
size_t QCamera2Injector::preview_sizes_tbl_cnt = 21;
cam_dimension_t QCamera2Injector::preview_sizes_tbl[] = {
    {3840, 2160},
    {2560, 1440},
    {1920, 1440},
    {1920, 1080},
    {1440, 1080},
    {1280, 720},
    {960, 720},
    {960, 540},
    {864, 480},
    {800, 480},
    {768, 432},
    {720, 480},
    {640, 480},
    {640, 360},
    {576, 432},
    {480, 320},
    {384, 288},
    {352, 288},
    {320, 240},
    {240, 160},
    {176, 144}
};

/* supported video sizes */
size_t QCamera2Injector::video_sizes_tbl_cnt = 13;
cam_dimension_t QCamera2Injector::video_sizes_tbl[] = {
    {3840, 2160},
    {2560, 1440},
    {1920, 1440},
    {1920, 1080},
    {1280, 720},
    {864, 480},
    {800, 480},
    {720, 480},
    {640, 480},
    {480, 320},
    {352, 288},
    {320, 240},
    {176, 144}
};

/* supported livesnapshot sizes */
size_t QCamera2Injector::livesnapshot_sizes_tbl_cnt = 19;
cam_dimension_t QCamera2Injector::livesnapshot_sizes_tbl[] = {
    {4000, 3000},
    {3200, 2400},
    {2592, 1944},
    {2560, 1440},
    {2048, 1536},
    {1920, 1440},
    {1920, 1080},
    {1600, 1200},
    {1280, 768},
    {1280, 720},
    {1024, 768},
    {800, 600},
    {864, 480},
    {800, 480},
    {720, 480},
    {640, 480},
    {352, 288},
    {320, 240},
    {176, 144}
};

/* supported HFR */
size_t QCamera2Injector::hfr_tbl_cnt = 0;
cam_hfr_info_t QCamera2Injector::hfr_tbl[] = {
    //{CAM_HFR_MODE_120FPS, {1280, 720}, 0, livesnapshot_sizes_tbl_cnt, livesnapshot_sizes_tbl}
};

/* supported preview formats */
size_t QCamera2Injector::supported_preview_fmt_cnt = 3;
cam_format_t QCamera2Injector::supported_preview_fmts[] = {
    CAM_FORMAT_YUV_420_NV21,
    CAM_FORMAT_YUV_420_YV12,
    CAM_FORMAT_YUV_420_NV12_VENUS
};

/* supported picture formats */
size_t QCamera2Injector::supported_picture_fmt_cnt = 1;
cam_format_t QCamera2Injector::supported_picture_fmts[] = {
    CAM_FORMAT_JPEG
};

/* dimension and supported output format of raw dump from camif */
cam_dimension_t QCamera2Injector::raw_dim = {5328, 3000};
size_t QCamera2Injector::supported_raw_fmt_cnt = 1;
cam_format_t QCamera2Injector::supported_raw_fmts[] = {
    CAM_FORMAT_BAYER_QCOM_RAW_10BPP_GBRG
};

/* supported focus algorithms */
size_t QCamera2Injector::supported_focus_algos_cnt = 4;
cam_focus_algorithm_type QCamera2Injector::supported_focus_algos[] = {
    CAM_FOCUS_ALGO_AUTO,
    CAM_FOCUS_ALGO_SPOT,
    CAM_FOCUS_ALGO_CENTER_WEIGHTED,
    CAM_FOCUS_ALGO_AVERAGE
};


uint8_t QCamera2Injector::auto_wb_lock_supported = 1;
uint8_t QCamera2Injector::zoom_supported = 1;
uint8_t QCamera2Injector::smooth_zoom_supported = 0;
uint8_t QCamera2Injector::auto_exposure_lock_supported = 1;
uint8_t QCamera2Injector::video_snapshot_supported = 0;

uint8_t QCamera2Injector::max_num_roi = 5;
uint8_t QCamera2Injector::max_num_focus_areas = 1;
uint8_t QCamera2Injector::max_num_metering_areas = 5;
uint8_t QCamera2Injector::max_zoom_step = 48;

/* QCOM specific control */
cam_control_range_t QCamera2Injector::brightness_ctrl = {0, 6, 3, 1};
cam_control_range_t QCamera2Injector::sharpness_ctrl = {0, 36, 10, 6};
cam_control_range_t QCamera2Injector::contrast_ctrl = {0, 10, 3, 1};
cam_control_range_t QCamera2Injector::saturation_ctrl = {0, 10, 4, 1};
cam_control_range_t QCamera2Injector::sce_ctrl = {-100, 100, 0, 10};

/* QCOM HDR specific control. Indicates number of frames and exposure needs for the frames */
//cam_hdr_bracketing_info_t QCamera2Injector::hdr_bracketing_setting;

uint32_t QCamera2Injector::qcom_supported_feature_mask = 1151;
cam_padding_info_t QCamera2Injector::padding_info = {0, 0, 0};

uint32_t QCamera2Injector::min_num_pp_bufs = 3;
uint32_t QCamera2Injector::min_required_pp_mask = 0;


}; // namespace qcamera

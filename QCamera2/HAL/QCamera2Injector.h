#ifndef __QCAMERA2INJECTOR_H__
#define __QCAMERA2INJECTOR_H__

#include <utils/Log.h>
#include <QCameraParameters.h>

namespace qcamera {

class QCamera2Injector {

private:
    static uint8_t auto_hdr_supported; //ok?

    /* supported iso modes */
    static size_t supported_iso_modes_cnt; //ok
    static cam_iso_mode_type supported_iso_modes[CAM_ISO_MODE_MAX]; //ok

    /* supported exposure time */
    static int32_t min_exposure_time;
    static int32_t max_exposure_time;

    /* supported flash modes */
    static size_t supported_flash_modes_cnt;
    static cam_flash_mode_t supported_flash_modes[CAM_FLASH_MODE_MAX];

    /* supported zoom ratios */
    static size_t zoom_ratio_tbl_cnt;
    static uint32_t zoom_ratio_tbl[MAX_ZOOMS_CNT];

    /* supported effect modes */
    static size_t supported_effects_cnt;
    static cam_effect_mode_type supported_effects[CAM_EFFECT_MODE_MAX];

    /* supported scene modes */
    static size_t supported_scene_modes_cnt;
    static cam_scene_mode_type supported_scene_modes[CAM_SCENE_MODE_MAX];

    /* supported auto exposure modes */
    static size_t supported_aec_modes_cnt;
    static cam_auto_exposure_mode_type supported_aec_modes[CAM_AEC_MODE_MAX];

    /* supported fps ranges */
    static size_t fps_ranges_tbl_cnt;                              /* fps ranges table size */
    static cam_fps_range_t fps_ranges_tbl[MAX_SIZES_CNT];          /* fps ranges table */

    /* supported antibanding modes */
    static size_t supported_antibandings_cnt;
    static cam_antibanding_mode_type supported_antibandings[CAM_ANTIBANDING_MODE_MAX];

    /* supported white balance modes */
    static size_t supported_white_balances_cnt;
    static cam_wb_mode_type supported_white_balances[CAM_WB_MODE_MAX];

    /* supported manual wb cct */
    static int32_t min_wb_cct;
    static int32_t max_wb_cct;

    /* supported focus modes */
    static size_t supported_focus_modes_cnt;
    static cam_focus_mode_type supported_focus_modes[CAM_FOCUS_MODE_MAX];

    /* supported manual focus position */
    static int32_t min_focus_pos[CAM_MANUAL_FOCUS_MODE_MAX];
    static int32_t max_focus_pos[CAM_MANUAL_FOCUS_MODE_MAX];

    /* supported exposure compensation */
    static int32_t exposure_compensation_min;       /* min value of exposure compensation index */
    static int32_t exposure_compensation_max;       /* max value of exposure compensation index */
    static int32_t exposure_compensation_default;   /* default value of exposure compensation index */
    static float exposure_compensation_step;
    static cam_rational_type_t exp_compensation_step;    /* exposure compensation step value */

    /* supported video stabilization */
    static uint8_t video_stablization_supported; /* flag id video stablization is supported */

    /* supported picture sizes */
    static size_t picture_sizes_tbl_cnt;                           /* picture sizes table size */
    static cam_dimension_t picture_sizes_tbl[MAX_SIZES_CNT];       /* picture sizes table */

    /* capabilities specific to HAL 1 */

    static int32_t modes_supported;                                /* mask of modes supported: 2D, 3D */
    static uint32_t sensor_mount_angle;                            /* sensor mount angle */

    static float focal_length;                                     /* focal length */
    static float hor_view_angle;                                   /* horizontal view angle */
    static float ver_view_angle;                                   /* vertical view angle */

    /* supported preview sizes */
    static size_t preview_sizes_tbl_cnt;                           /* preview sizes table size */
    static cam_dimension_t preview_sizes_tbl[MAX_SIZES_CNT];       /* preiew sizes table */

    /* supported video sizes */
    static size_t video_sizes_tbl_cnt;                             /* video sizes table size */
    static cam_dimension_t video_sizes_tbl[MAX_SIZES_CNT];         /* video sizes table */

    /* supported livesnapshot sizes */
    static size_t livesnapshot_sizes_tbl_cnt;                      /* livesnapshot sizes table size */
    static cam_dimension_t livesnapshot_sizes_tbl[MAX_SIZES_CNT];  /* livesnapshot sizes table */

    /* supported HFR */
    static size_t hfr_tbl_cnt;                                     /* table size for HFR */
    static cam_hfr_info_t hfr_tbl[CAM_HFR_MODE_MAX];               /* HFR table */

    /* supported preview formats */
    static size_t supported_preview_fmt_cnt;
    static cam_format_t supported_preview_fmts[CAM_FORMAT_MAX];

    /* supported picture formats */
    static size_t supported_picture_fmt_cnt;
    static cam_format_t supported_picture_fmts[CAM_FORMAT_MAX];

    /* dimension and supported output format of raw dump from camif */
    static cam_dimension_t raw_dim;
    static size_t supported_raw_fmt_cnt;
    static cam_format_t supported_raw_fmts[CAM_FORMAT_MAX];

    /* supported focus algorithms */
    static size_t supported_focus_algos_cnt;
    static cam_focus_algorithm_type supported_focus_algos[CAM_FOCUS_ALGO_MAX];


    static uint8_t auto_wb_lock_supported;       /* flag if auto white balance lock is supported */
    static uint8_t zoom_supported;               /* flag if zoom is supported */
    static uint8_t smooth_zoom_supported;        /* flag if smooth zoom is supported */
    static uint8_t auto_exposure_lock_supported; /* flag if auto exposure lock is supported */
    static uint8_t video_snapshot_supported;     /* flag if video snapshot is supported */

    static uint8_t max_num_roi;                  /* max number of roi can be detected */
    static uint8_t max_num_focus_areas;          /* max num of focus areas */
    static uint8_t max_num_metering_areas;       /* max num opf metering areas */
    static uint8_t max_zoom_step;                /* max zoom step value */

    /* QCOM specific control */
    static cam_control_range_t brightness_ctrl;  /* brightness */
    static cam_control_range_t sharpness_ctrl;   /* sharpness */
    static cam_control_range_t contrast_ctrl;    /* contrast */
    static cam_control_range_t saturation_ctrl;  /* saturation */
    static cam_control_range_t sce_ctrl;         /* skintone enhancement factor */

    /* QCOM HDR specific control. Indicates number of frames and exposure needs for the frames */
    static cam_hdr_bracketing_info_t hdr_bracketing_setting;

    static uint32_t qcom_supported_feature_mask; /* mask of qcom specific features supported:
                                           * such as CAM_QCOM_FEATURE_SUPPORTED_FACE_DETECTION*/
    static cam_padding_info_t padding_info;      /* padding information from PP */
    static uint32_t min_num_pp_bufs;             /* minimum number of buffers needed by postproc module */
    static uint32_t min_required_pp_mask;        /* min required pp feature masks for ZSL.
                                           * depends on hardware limitation, i.e. for 8974,
                                           * sharpness is required for all ZSL snapshot frames */

    /* capabilities specific to HAL 3 */
#if 0
    float min_focus_distance;
    float hyper_focal_distance;

    float focal_lengths[CAM_FOCAL_LENGTHS_MAX];
    uint8_t focal_lengths_count;

    float apertures[CAM_APERTURES_MAX];
    uint8_t apertures_count;

    float filter_densities[CAM_FILTER_DENSITIES_MAX];
    uint8_t filter_densities_count;

    uint8_t optical_stab_modes[CAM_OPT_STAB_MAX];
    uint8_t optical_stab_modes_count;

    cam_dimension_t lens_shading_map_size;
    float lens_shading_map[3 * CAM_MAX_MAP_WIDTH *
              CAM_MAX_MAP_HEIGHT];

    cam_dimension_t geo_correction_map_size;
    float geo_correction_map[2 * 3 * CAM_MAX_MAP_WIDTH *
              CAM_MAX_MAP_HEIGHT];

    float lens_position[3];

    /* nano seconds */
    int64_t exposure_time_range[2];

    /* nano seconds */
    int64_t max_frame_duration;

    cam_color_filter_arrangement_t color_arrangement;

    float sensor_physical_size[2];

    /* Dimensions of full pixel array, possibly including
       black calibration pixels */
    cam_dimension_t pixel_array_size;
    /* Area of raw data which corresponds to only active
       pixels; smaller or equal to pixelArraySize. */
    cam_rect_t active_array_size;

    /* Maximum raw value output by sensor */
    int32_t white_level;

    /* A fixed black level offset for each of the Bayer
       mosaic channels */
    int32_t black_level_pattern[4];

    /* Time taken before flash can fire again in nano secs */
    int64_t flash_charge_duration;

    /* Maximum number of supported points in the tonemap
       curve */
    int32_t max_tone_map_curve_points;

    /* supported formats */
    size_t supported_scalar_format_cnt;
    cam_format_t supported_scalar_fmts[CAM_FORMAT_MAX];

    /* The minimum frame duration that is supported for above
       raw resolution */
    int64_t raw_min_duration;

    size_t supported_sizes_tbl_cnt;
    cam_dimension_t supported_sizes_tbl[MAX_SIZES_CNT];

    /* The minimum frame duration that is supported for each
     * resolution in availableProcessedSizes. Should correspond
     * to the frame duration when only that processed stream
     * is active, with all processing set to FAST */
    int64_t min_duration[MAX_SIZES_CNT];

    uint32_t max_face_detection_count;

    uint8_t histogram_supported;
    /* Number of histogram buckets supported */
    int32_t histogram_size;
    /* Maximum value possible for a histogram bucket */
    int32_t max_histogram_count;

    cam_dimension_t sharpness_map_size;

    /* Maximum value possible for a sharpness map region */
    int32_t max_sharpness_map_value;

    cam_scene_mode_overrides_t scene_mode_overrides[CAM_SCENE_MODE_MAX];

    /*Autoexposure modes for camera 3 api*/
    size_t supported_ae_modes_cnt;
    cam_ae_mode_type supported_ae_modes[CAM_AE_MODE_MAX];

    /* picture sizes need scale*/
    size_t scale_picture_sizes_cnt;
    cam_dimension_t scale_picture_sizes[MAX_SCALE_SIZES_CNT];

    uint8_t flash_available;

    cam_rational_type_t base_gain_factor;    /* sensor base gain factor */
    /* AF Bracketing info */
    cam_af_bracketing_t  ubifocus_af_bracketing_need;
    /* opti Zoom info */
    cam_opti_zoom_t      opti_zoom_settings_need;
    /* true Portrait info */
    cam_true_portrait_t  true_portrait_settings_need;
    /* FSSR info */
    cam_fssr_t      fssr_settings_need;
    /* AF bracketing info for multi-touch focus*/
    cam_af_bracketing_t  mtf_af_bracketing_parm;
    /* Sensor type information */
    cam_sensor_type_t sensor_type;
#endif

public:
    static void inject(cam_capability_t *camCapability, int cameraId);
};

};

#endif /* __QCAMERA2INJECTOR_H__ */

#ifndef __QCAMERA2INJECTOR_H__
#define __QCAMERA2INJECTOR_H__

#include <utils/Log.h>
#include <QCameraParameters.h>

namespace qcamera {

class QCamera2Injector {

public:
    static void inject(cam_capability_t *camCapability, int cameraId);
};

};

#endif /* __QCAMERA2INJECTOR_H__ */

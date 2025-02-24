#ifndef _CAMERA_SYSTEM_H_
#define _CAMERA_SYSTEM_H_

#include "Engine/Systems/System.h"

class CameraSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

#endif
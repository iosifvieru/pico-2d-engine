#ifndef _MOVEMENT_SYSTEM_H_
#define _MOVEMENT_SYSTEM_H_


#include "Engine/Systems/System.h"

class MovementSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override;
};

#endif
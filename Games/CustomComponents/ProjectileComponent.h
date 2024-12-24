#ifndef _PROJECTILE_COMPONENT_H_
#define _PROJECTILE_COMPONENT_H_

#include "Engine/Components/Component.h"

class ProjectileComponent : public Component {
public:
    int life_time = 10;

    ProjectileComponent(int life_time) : life_time(life_time) {};
    ~ProjectileComponent() = default;

    const char* get_component_name() {
        return "ProjectileComponent";
    };
};

#endif
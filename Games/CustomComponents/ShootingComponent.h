#ifndef _SHOOTING_COMPONENT_
#define _SHOOTING_COMPONENT_

#include "Engine/Components/Component.h"

class ShootingComponent : public Component {
public:
    int ammo = 30;
    int cooldown = 10;

    ShootingComponent(){};
    ~ShootingComponent() = default;

    ShootingComponent(int ammo, int cooldown){
        this->ammo = ammo;
        this->cooldown = cooldown;
    };

    const char* get_component_name() {
        return "ShootingComponent";
    };
};

#endif
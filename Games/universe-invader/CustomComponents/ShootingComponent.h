#ifndef _SHOOTING_COMPONENT_
#define _SHOOTING_COMPONENT_

#include "Engine/Components/Component.h"

class ShootingComponent : public Component {
public:
    int16_t ammo = 30;
    int16_t cooldown = 10;

    ShootingComponent(){};
    ~ShootingComponent(){
        
    }

    ShootingComponent(int ammo, int cooldown){
        this->ammo = ammo;
        this->cooldown = cooldown;
        
    };

    ShootingComponent(const ShootingComponent& other){
        this->ammo = other.ammo;
        this->cooldown = other.cooldown;
    }

    ShootingComponent operator=(const ShootingComponent& other){
        this->ammo = other.ammo;
        this->cooldown = other.cooldown;
        return *this;
    }

    const char* get_component_name() {
        return "ShootingComponent";
    };
};

#endif
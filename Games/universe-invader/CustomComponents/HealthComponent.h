#ifndef _HEALTH_COMPONENT_H_
#define _HEALTH_COMPONENT_H_

#include "Engine/Components/Component.h"

class HealthComponent : public Component {
public:
    int16_t health = 100;

    HealthComponent() {};
    ~HealthComponent() = default;

    HealthComponent(int16_t health){
        this->health = health;
    }

    const char* get_component_name() {
        return "HealthComponent";
    };
};

#endif
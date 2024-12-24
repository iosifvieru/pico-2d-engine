#ifndef _PROJECTILE_COMPONENT_H_
#define _PROJECTILE_COMPONENT_H_

#include "Engine/Components/Component.h"
#include "Engine/Logger/Logger.h"

class ProjectileComponent : public Component {
public:
    int16_t life_time = 10;

    ProjectileComponent(int life_time) : life_time(life_time) {
        Logger::log("ProjectileComponent()");
    };

    ~ProjectileComponent(){
        Logger::log("~ProjectileComponent()");
    }

    ProjectileComponent operator=(const ProjectileComponent& other){
        this->life_time = other.life_time;
        return *this;
    }

    ProjectileComponent(const ProjectileComponent& other){
        this->life_time = other.life_time;
    }

    const char* get_component_name() {
        return "ProjectileComponent";
    };
};

#endif
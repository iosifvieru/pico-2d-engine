#ifndef _VELOCITY_COMPONENT_H_
#define _VELOCITY_COMPONENT_H_

#include "Engine/Components/Component.h"
#include "Engine/Logger/Logger.h"

class VelocityComponent : public Component {
public:
    int16_t v_x = 0;
    int16_t v_y = 0;

    VelocityComponent(int16_t x, int16_t y) : v_x(x), v_y(y) {
        Logger::log("VelocityComponent()");
    };

    VelocityComponent(const VelocityComponent& other){
        this->v_x = other.v_x;
        this->v_y = other.v_y;
        Logger::log("VelocityComponent(const& other)");
    };

    VelocityComponent operator=(const VelocityComponent& other){
        this->v_x = other.v_x;
        this->v_y = other.v_y;
        Logger::log("VelocityComponent operator=");
        return *this;
    }

    VelocityComponent() {};

    ~VelocityComponent() {
        Logger::log("~VelocityComponent()");
    };

    const char* get_component_name() {
        return "VelocityComponent";
    }
};

#endif

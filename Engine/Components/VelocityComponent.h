#ifndef _VELOCITY_COMPONENT_H_
#define _VELOCITY_COMPONENT_H_

#include "Engine/Components/Component.h"

class VelocityComponent : public Component {
public:
    int8_t v_x = 0;
    int8_t v_y = 0;

    VelocityComponent(int8_t x, int8_t y) : v_x(x), v_y(y) {};
    VelocityComponent(const VelocityComponent& other){
        this->v_x = other.v_x;
        this->v_y = other.v_y;
    };

    VelocityComponent operator=(const VelocityComponent& other){
        this->v_x = other.v_x;
        this->v_y = other.v_y;

        return *this;
    }

    VelocityComponent() {};

    ~VelocityComponent() {};

    std::string get_component_name() {
        return "VelocityComponent";
    }
};

#endif

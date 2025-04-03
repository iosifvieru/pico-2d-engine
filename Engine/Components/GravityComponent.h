#ifndef _GRAVITY_COMPONENT_H_
#define _GRAVITY_COMPONENT_H_

#include "Engine/Components/Component.h"

#define MAX_GRAVITY 5.0f

class GravityComponent : public Component {
public:
    float gravity = 0.05f;
    bool is_falling = false;
    bool is_grounded = false;

    GravityComponent(){
        this->gravity = 0.05f;
    }

    GravityComponent(float gravity){
        this->gravity = gravity;
    }

    const char* get_component_name() const {
        return "GravityComponent";
    };
};

#endif
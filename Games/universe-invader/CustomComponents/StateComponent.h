#ifndef _STATE_COMPONENT_H_
#define _STATE_COMPONENT_H_

#include "Engine/Components/Component.h"

enum States {
    Idle,
    Moving,
    Shooting,
    Dead
};

class StateComponent : public Component {
public:
    States state;

    StateComponent() {
        this->state = States::Idle;
    };

    ~StateComponent() = default;


    const char* get_component_name() {
        return "StateComponent";
    }
};

#endif
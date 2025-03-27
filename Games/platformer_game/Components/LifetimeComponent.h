#ifndef _LIFETIME_COMPONENT_H_
#define _LIFETIME_COMPONENT_H_

#include "Engine/Components/Component.h"

class LifetimeComponent : public Component {
public:
    int time = 0;

    LifetimeComponent(int time): time(time) {}

    const char* get_component_name() {
        return "LifetimeComponent";
    };
};

#endif
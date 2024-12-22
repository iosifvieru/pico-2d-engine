#ifndef _POSITION_COMPONENT_H_
#define _POSITION_COMPONENT_H_

#include "Engine/Components/Component.h"


class PositionComponent : public Component {
public:
    uint16_t x = 0;
    uint16_t y = 0;
    uint16_t z = 0;
    uint16_t angle = 0;

    PositionComponent() {};
    PositionComponent(uint16_t x, uint16_t y, uint16_t z, uint16_t angle) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->angle = angle;
        Logger::log("PositionComponent()");
    };

    ~PositionComponent(){
        Logger::log("~PositionComponent()");
    };

    PositionComponent(const PositionComponent& other){
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->angle = other.angle;
    };

    PositionComponent operator=(const PositionComponent& other){
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->angle = other.angle;

        return *this;
    }

    std::string get_component_name() {
        return "PositionComponent";
    }
};


#endif
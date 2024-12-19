#ifndef _SQUARE_COMPONENT_H_
#define _SQUARE_COMPONENT_H_

#include "Engine/Components/Component.h"

class SquareComponent : public Component {
public:
    uint16_t min_x = 0;
    uint16_t min_y = 0;
    uint16_t max_x = 0;
    uint16_t max_y = 0;

    SquareComponent() {};
    ~SquareComponent() {};

    SquareComponent(uint16_t min_x, uint16_t min_y, uint16_t max_x, uint16_t max_y){
        this->min_x = min_x;
        this->min_y = min_y;
        this->max_x = max_x;
        this->max_y = max_y;
    }

    SquareComponent(const SquareComponent& other){
        this->min_x = other.min_x;
        this->max_x = other.max_x;
        this->min_y = other.min_y;
        this->max_y = other.max_y;
    }

    SquareComponent operator=(const SquareComponent& other){
        this->min_x = other.min_x;
        this->max_x = other.max_x;
        this->min_y = other.min_y;
        this->max_y = other.max_y;

        return *this;
    }

    std::string get_component_name() {
        return "SquareComponent";
    }
};

#endif
#ifndef _SQUARE_COMPONENT_H_
#define _SQUARE_COMPONENT_H_

#include "Engine/Components/Component.h"


/* square collider component. */
class SquareComponent : public Component {
private:
    uint16_t x = 0;
    uint16_t y = 0;
    uint16_t width = 0;
    uint16_t height = 0;
public:
    bool is_visible = true;
    bool collided = false;

    SquareComponent() {};
    ~SquareComponent() {};

    SquareComponent(uint16_t min_x, uint16_t min_y, uint16_t width, uint16_t height){
        this->x = min_x;
        this->y = min_y;
        this->width = width;
        this->height = height;
    }

    SquareComponent(const SquareComponent& other){
        this->x = other.x;
        this->y = other.y;
        this->width = other.width;
        this->height = other.height;
    }

    SquareComponent operator=(const SquareComponent& other){
        this->x = other.x;
        this->y = other.y;
        this->width = other.width;
        this->height = other.height;
        return *this;
    }

    void set_visibility(bool value){
        this->is_visible = value;
    }

    void set_x(uint16_t x){
        this->x = x;
    }

    void set_y(uint16_t y){
        this->y = y;
    }

    void set_width(uint16_t width){
        this->width = width;
    }

    void set_height(uint16_t height){
        this->height = height;
    }

    uint16_t get_max_x(){
        return this->x + this->width;
    }

    uint16_t get_max_y(){
        return this->y + this->height;
    }

    uint16_t get_x(){
        return this->x;
    }

    uint16_t get_y(){
        return this->y;
    }

    uint16_t get_height(){
        return this->height;
    }

    uint16_t get_width() {
        return this->width;
    }

    bool has_collided(const SquareComponent& other){
        if((this->x + this->width) < other.x || this->x > (other.x + other.width)){
            return false;
        }

        if((this->y + this->height) < other.y || this->y > (other.y + other.height)){
            return false;
        }

        return true;
    }

    const char* get_component_name() {
        return "SquareComponent";
    }
};

#endif
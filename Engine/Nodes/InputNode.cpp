#include "Engine/Nodes/InputNode.h"
#include "pico/stdlib.h"

InputNode::InputNode(uint16_t x, uint16_t y) : Node(x, y){
    //
    gpio_init(8);
    gpio_set_dir(8, GPIO_IN);
    gpio_pull_up(8);

    gpio_init(14);
    gpio_set_dir(14, GPIO_IN);
    gpio_pull_up(14);
}

InputNode::~InputNode(){

}

// temporary implementation.
// just for testing some things out.
void InputNode::update(){
    bool is_pressed_x = !gpio_get(8);

    if(is_pressed_x){
        this->x += 5;

        this->x = this->x % 128;
    }

    bool is_pressed_y = !gpio_get(14);

    if(is_pressed_y){
        this->y += 5;

        this->y = this->y % 128;
    }
}

void InputNode::render(Canvas& canvas){
    //
}
#ifndef _SQUARE_COLLIDER_H_
#define _SQUARE_COLLIDER_H_

#include "Engine/Nodes/Node.h"
#include "Engine/Components/Components.h"

class SquareCollider : public Node {

public:
    SquareComponent* square_collider = nullptr;
    bool is_visible = false;

    SquareCollider(){};
    ~SquareCollider(){
        if(square_collider != nullptr){
            delete square_collider;
        }
    }
    SquareCollider(SquareComponent* square_component) : square_collider(square_component) {};
    
    bool has_collided(SquareCollider* another_collider) {
        SquareComponent* another_square = another_collider->square_collider;
        if (square_collider->max_x < another_square->min_x ||
            square_collider->min_x > another_square->max_x) {
                return false;
        }
        if (square_collider->max_y < another_square->min_y ||
            square_collider->min_y > another_square->max_y) {
                return false;
        }
        return true;
    };

    std::string get_component_name() override {
        return "SquareCollider";
    };
};

#endif

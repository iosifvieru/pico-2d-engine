#ifndef _MOVEMENT_NODE_H_
#define _MOVEMENT_NODE_H_

#include "Engine/Nodes/Node.h"
#include "Engine/Components/Components.h"

class MovementNode : public Node {
public:
    PositionComponent* position = nullptr;
    VelocityComponent* velocity = nullptr;

    MovementNode() {};
    MovementNode(PositionComponent* position, VelocityComponent* velocity) : position(position), velocity(velocity) {};
    ~MovementNode() {
        
        if(velocity != nullptr){
            delete velocity;
        }
    };

    std::string get_component_name() {
        return "MovementNode";
    }
};

#endif
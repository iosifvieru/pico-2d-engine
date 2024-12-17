#ifndef _RENDER_NODE_H_
#define _RENDER_NODE_H_

#include "Engine/Nodes/Node.h"
#include "Engine/Components/Components.h"

class RenderNode : public Node {
public:
    PositionComponent* position = nullptr;
    SpriteComponent* sprite = nullptr;

    RenderNode() {};
    RenderNode(PositionComponent* position, SpriteComponent* sprite) : position(position), sprite(sprite) {};
    ~RenderNode() {
        if(position != nullptr){
            delete position;
        }

        if(sprite != nullptr){
            delete sprite;
        }
    };

    std::string get_component_name() {
        return "RenderNode";
    }
};

#endif
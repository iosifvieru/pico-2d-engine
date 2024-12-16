#ifndef _RENDER_NODE_H_
#define _RENDER_NODE_H_

#include "Engine/Nodes/Node.h"
#include "Engine/Components/Components.h"

class RenderNode : public Node {
public:
    bool is_visible = true;
    PositionComponent* position = nullptr;
    SpriteComponent* sprite = nullptr;

    RenderNode() {};
    RenderNode(PositionComponent* position, SpriteComponent* sprite) : position(position), sprite(sprite) {};
    ~RenderNode() override = default;

    std::string get_component_name() {
        return "RenderNode";
    }

    void set_visibility(bool value) {
        this->is_visible = value;
    }
};

#endif
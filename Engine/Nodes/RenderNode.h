#ifndef _RENDER_NODE_H_
#define _RENDER_NODE_H_

#include "Engine/Nodes/Node.h"
#include "Engine/Components/Components.h"

class RenderNode : public Node {
public:
    PositionComponent* position = nullptr;
    SpriteComponent* sprite = nullptr;

    ~RenderNode() override = default;
};

#endif
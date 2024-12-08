#ifndef _INPUT_NODE_H_
#define _INPUT_NODE_H_

#include "Node.h"


class InputNode : public Node {
public:
    InputNode(uint16_t x, uint16_t y);
    ~InputNode();

    void update() override;
    void render(Canvas& canvas) override;
};

#endif
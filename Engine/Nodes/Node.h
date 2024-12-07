#ifndef _NODE_H_
#define _NODE_H_

#include "Engine/Canvas/Canvas.h"

class Node {
    virtual void update() = 0;
    virtual void render(Canvas& canvas) = 0;
    virtual ~Node() = default;
};

#endif

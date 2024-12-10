#ifndef _SPRITE_NODE_H_
#define _SPRITE_NODE_H_

#include "Node.h"

class SpriteNode : public Node {
private:
    const uint16_t* sprite;
    uint16_t width, height;

    int rotationAngle = 0;
    /* x, y are inherited */
public:
    SpriteNode(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint16_t* sprite);
    //SpriteNode(uint16_t* sprite);
    ~SpriteNode();

    void update() override;
    void render(Canvas& canvas) override;
};

#endif
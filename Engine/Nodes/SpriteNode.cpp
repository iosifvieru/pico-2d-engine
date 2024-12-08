
#include "SpriteNode.h"

SpriteNode::SpriteNode(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint16_t* sprite) : Node(x, y){
    if(sprite == nullptr){
        return;
    }

    /* i don t think this should be removed since it points to the sprite variable. */
    this->sprite = sprite;

    this->width = width;
    this->height = height;
    
    // logging?
}

SpriteNode::~SpriteNode(){
    //
}

void SpriteNode::render(Canvas& canvas){
    if(scale_factor == 1){
        canvas.draw_sprite(this->x, this->y, width, height, sprite);
    } else {
        canvas.draw_sprite(this->x, this->y, this->scale_factor, width, height, sprite);
    }
    
}

void SpriteNode::update(){
    //
}
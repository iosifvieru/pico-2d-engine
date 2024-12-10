
#include "SpriteNode.h"
#include <cmath>

SpriteNode::SpriteNode(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint16_t* sprite) : Node(x, y){
    if(sprite == nullptr){
        return;
    }

    /* i don t think this should be removed since it points to the sprite variable. */
    this->sprite = sprite;

    this->width = width;
    this->height = height;
    
    // logging?

    this->rotationAngle = 0;
}

SpriteNode::~SpriteNode(){
    //
}

void SpriteNode::render(Canvas& canvas) {
    if (!sprite) {
        return;
    }

    float centerX = x + width / 2.0;
    float centerY = y + height / 2.0;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            float localX = j - width / 2.0;
            float localY = i - height / 2.0;

            float radians = rotationAngle * M_PI / 180.0;
            float rotatedX = localX * std::cos(radians) - localY * std::sin(radians);
            float rotatedY = localX * std::sin(radians) + localY * std::cos(radians);

            int screenX = static_cast<int>(centerX + rotatedX);
            int screenY = static_cast<int>(centerY + rotatedY);

            uint16_t color = sprite[i * width + j];

            // Render the rotated pixel
            canvas.set_pixel(screenX, screenY, color);
        }
    }
}


void SpriteNode::update(){
    this->rotationAngle += 15;

    this->rotationAngle = rotationAngle % 360;
}
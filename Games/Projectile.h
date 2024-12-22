#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/SquareComponent.h"

#include "Engine/Entity/Entity.h"
#include "Engine/Engine.h"

uint16_t projectile_sprite[10] = {
    0xffc0, 0xffc0,
    0xffc0, 0xffc0,
    0xef49, 0xef49,
    0xef49, 0xef49,
    0xef49, 0xef49
};

class Projectile : public Entity {
private:
    PositionComponent* position;
    VelocityComponent* velocity;
    SpriteComponent* sprite;
    SquareComponent* square;
    
    int lifespan = 40;
public:
    Projectile(int x, int y, int speed) {
        position = new PositionComponent(x, y, 0, 0);
        velocity = new VelocityComponent(0, speed);
        sprite = new SpriteComponent(2, 5, projectile_sprite);
        
        square = new SquareComponent(position->x, position->y,
            sprite->width, sprite->height);

        this->add_component(position);
        this->add_component(velocity);
        this->add_component(sprite);
        this->add_component(square);
    };
    ~Projectile() = default;

    void update(){
        if(square->collided == true || lifespan-- <= 0){
            Engine::getInstance().remove_entity(this);
        }
    };
};

#endif
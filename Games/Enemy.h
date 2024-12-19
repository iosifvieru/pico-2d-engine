#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Engine/Entity/Entity.h"

#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/VelocityComponent.h"

#include "Engine/Engine.h"

uint16_t enemy_sprite[4] = {
    0xf800, 0xf800, 0xf800, 0xf800
};

class Enemy : public Entity {
private:
    PositionComponent* position;
    SpriteComponent* sprite;
    VelocityComponent* velocity;
    int lifespan = 50;
public:
    SquareComponent* collision;
    Enemy(int x, int y) {
        position = new PositionComponent(x, y, 0, 0);
        sprite = new SpriteComponent(2, 2, enemy_sprite);
        velocity = new VelocityComponent(0, -2);
        
        collision = new SquareComponent(position->x, position->y, 
                    sprite->width, sprite->height
        );

        this->add_component(position);
        this->add_component(sprite);
        this->add_component(velocity);
        this->add_component(collision);
    };

    ~Enemy() = default;

    void update() {
        lifespan--;

        if(lifespan <= 0){
            Engine::getInstance().remove_entity(this);
        }

        if(collision->collided == true){
            velocity->v_y = 0;
            velocity->v_x = 0;
        }
    };

    void set_velocity(uint8_t x, uint8_t y){
        velocity->v_x = x;
        velocity->v_y = y;
    };

    void set_lifespan(int lifespan){
        this->lifespan = lifespan;
    }
};

#endif
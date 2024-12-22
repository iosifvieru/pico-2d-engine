#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Engine/Entity/Entity.h"

#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/SquareComponent.h"

#include "Engine/Engine.h"

#include "Games/Assets.h"

uint16_t enemy_sprite[16] = {
    0xf800, 0xf800, 0xf800, 0xf800,
    0xf800, 0xf800, 0xf800, 0xf800,
    0xf800, 0xf800, 0xf800, 0xf800,
    0xf800, 0xf800, 0xf800, 0xf800
};

class Enemy : public Entity {
private:
    PositionComponent* position;
    SpriteComponent* sprite;

    int health = 100;
public:
    SquareComponent* collision;
    Enemy(int x, int y) {
        position = new PositionComponent(x, y, 0, 0);
        sprite = new SpriteComponent(4, 4, enemy_sprite);
        
        collision = new SquareComponent(position->x, position->y, 
                    sprite->width, sprite->height
        );

        this->add_component(position);
        this->add_component(sprite);
        this->add_component(collision);
    };

    ~Enemy() = default;

    void update() {
        if(collision->collided == true){
            Engine::getInstance().remove_entity(this);
         //   this->health -= 50;
            collision->is_visible = true;

        }

        if(this->health <= 0){
            Engine::getInstance().remove_entity(this);
        }
    };
};

#endif
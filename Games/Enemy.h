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
    Enemy(int x, int y) {
        position = new PositionComponent(x, y, 0, 0);
        sprite = new SpriteComponent(2, 2, enemy_sprite);
        velocity = new VelocityComponent(0, -2);

        this->add_component(position);
        this->add_component(sprite);
        this->add_component(velocity);
    };

    ~Enemy() = default;

    void update() {
        lifespan--;

        if(lifespan <= 0){
            Engine::getInstance().remove_entity(this);
        }
    };
};

#endif
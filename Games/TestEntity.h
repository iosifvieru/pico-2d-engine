#ifndef _TEST_ENTITY_H_
#define _TEST_ENTITY_H_

#include "Engine/Entity/Entity.h"

#include "Engine/Drivers/InputDriver/Keyboard.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/SquareComponent.h"

#include "Engine/Engine.h"
#include "Games/Enemy.h"

uint16_t player_texture[4] = {
    0x15AF, 0xAFFF, 0x1FBB, 0x10AA
};

class TestEntity : public Entity {
private:
    PositionComponent* position;
    SpriteComponent* sprite;
    VelocityComponent* velocity;
    SquareComponent* collision;
public:
    TestEntity(){
        position = new PositionComponent(50, 125, 0, 0);
        sprite = new SpriteComponent(2, 2, player_texture);
        velocity = new VelocityComponent(0, 0);

        collision = new SquareComponent(position->x, position->y, 
                    sprite->width, sprite->height
        );

        this->add_component(position);
        this->add_component(sprite);
        this->add_component(velocity);
        this->add_component(collision);

        Keyboard::getInstance().config(8);
        Keyboard::getInstance().config(14);
    }

    /* destructor does nothing because the base class will clean up. */
    ~TestEntity() = default;

    void update() {
        this->velocity->v_x = 0;
        this->velocity->v_y = 0;
        if(Keyboard::getInstance().is_pressed(8)){
            this->velocity->v_x = -5;
        }

        if(Keyboard::getInstance().is_pressed(14)){
            this->velocity->v_x = 5;
        }

        if(Keyboard::getInstance().is_pressed(13)){
            Enemy* projectile = new Enemy(this->position->x , this->position->y - 4);
            Engine::getInstance().add_entity(projectile);
        }
    };
};

#endif
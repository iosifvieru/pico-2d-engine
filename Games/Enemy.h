#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Engine/Entity/Entity.h"
#include "Engine/Nodes/RenderNode.h"
#include "Engine/Nodes/MovementNode.h"

#define enemy_velocity_speed 2

uint16_t enemy_texture[4] = {
    0xf800, 0xf800,
    0xf800, 0xf800
};

SpriteComponent* enemy_sprite = new SpriteComponent(2, 2, enemy_texture);
VelocityComponent* enemy_velocity = new VelocityComponent(enemy_velocity_speed, 0);

class Enemy : public Entity {
private:
    uint16_t counter = 0;
public:
    Enemy(uint16_t x, uint16_t y) : Entity() {
        PositionComponent* enemy_position = new PositionComponent(x, y, 0, 0);
        
        RenderNode* render_node = new RenderNode(enemy_position, enemy_sprite);

        /* movement for enemies. */
        MovementNode* movement = new MovementNode(enemy_position, enemy_velocity);

        this->add_component(render_node);
        this->add_component(movement);
    };
    ~Enemy() {

    };

    void update() override {
        PositionComponent* position = ((MovementNode*) this->get_component("MovementNode"))->position;
        position->x %= 128;
    }
};

#endif
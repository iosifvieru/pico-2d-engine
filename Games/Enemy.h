#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Engine/Entity/Entity.h"
#include "Engine/Nodes/RenderNode.h"
#include "Engine/Nodes/MovementNode.h"

uint16_t enemy_texture[4] = {
    0xf800, 0xf800,
    0xf800, 0xf800
};

class Enemy : public Entity {
public:
    Enemy(uint16_t x, uint16_t y) : Entity() {
        PositionComponent* enemy_position = new PositionComponent(x, y, 0, 0);
        SpriteComponent* enemy_sprite = new SpriteComponent(2, 2, enemy_texture);
        
        RenderNode* render_node = new RenderNode(enemy_position, enemy_sprite);

        this->add_component(render_node);
    };
    ~Enemy() {

    };

    void update() override {
        //
    }
};

#endif
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Engine/Entity/Entity.h"
#include "Engine/Nodes/RenderNode.h"
#include "Engine/Nodes/MovementNode.h"
#include <memory>

#define enemy_velocity_speed 2

uint16_t enemy_texture[9] = {
    0xf800, 0xf800, 0xf800,
    0xf800, 0xf800, 0xf800,
    0xf800, 0xf800, 0xf800
};

SpriteComponent* enemy_sprite = new SpriteComponent(3, 3, enemy_texture);
VelocityComponent* enemy_velocity = new VelocityComponent(0, 0);

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

        SquareCollider* sq = new SquareCollider(new SquareComponent(
            enemy_position->x, enemy_position->y, 
            enemy_position->x + enemy_sprite->width, enemy_position->y + enemy_sprite->height
            ));
        
        sq->is_visible = 1;

        this->add_component(sq);
    };
    ~Enemy() {

    };

    void update() override {
        PositionComponent* position = ((MovementNode*) this->get_component("MovementNode"))->position;
        position->x %= 128;

        SquareCollider* sq = (SquareCollider*) this->get_component("SquareCollider");
        MovementNode* movement_node = (MovementNode*) this->get_component("MovementNode");

        if(sq == nullptr) return;
        if(movement_node == nullptr) return;

        sq->square_collider->min_x = movement_node->position->x;
        sq->square_collider->min_y = movement_node->position->y;

        sq->square_collider->max_x = sq->square_collider->min_x + 2;
        sq->square_collider->max_y = sq->square_collider->min_y + 2;

        if(sq->is_visible == true){
            Engine::getInstance().remove_entity(this);
        }
    }
};

#endif
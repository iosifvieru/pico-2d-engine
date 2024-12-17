#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Engine/Entity/Entity.h"
#include "Engine/Nodes/RenderNode.h"
#include "Engine/Nodes/MovementNode.h"
#include "Engine/Nodes/SquareCollider.h"

#define projectile_velocity_value -1

uint16_t projectile_texture[4] = {
    0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF
};

class Projectile : public Entity {
private:
    int lifespan = 50;
    RenderNode* renderNode;
    MovementNode* movementNode;

public:
    Projectile(uint16_t x, uint16_t y) : Entity() {
        PositionComponent* pos = new PositionComponent(x, y, 0, 0);
        SpriteComponent* sprite = new SpriteComponent(2, 2, projectile_texture);

        renderNode = new RenderNode(pos, sprite);
        movementNode = new MovementNode(pos, new VelocityComponent(0, -5));


        SquareCollider* sq = new SquareCollider(new SquareComponent(
            pos->x, pos->y, 
            pos->x + renderNode->sprite->width, pos->y + renderNode->sprite->height
            ));
        
        this->add_component(renderNode);
        this->add_component(movementNode);

        this->add_component(sq);
    };
    ~Projectile() {
        delete renderNode;
        delete movementNode;
    };

    void update() override {
        lifespan--;

        SquareCollider* sq = (SquareCollider*) this->get_component("SquareCollider");
        if(sq == nullptr) return;

        sq->square_collider->min_x = movementNode->position->x;
        sq->square_collider->min_y = movementNode->position->y;

        sq->square_collider->max_x = sq->square_collider->min_x + renderNode->sprite->width;
        sq->square_collider->max_y = sq->square_collider->min_y + renderNode->sprite->height;

        if(lifespan <= 0){
            Engine::getInstance().remove_entity(this);
        }

        if(sq->is_visible == 1){
            Engine::getInstance().remove_entity(this);
        }
    }
};


#endif
#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Engine/Entity/Entity.h"
#include "Engine/Nodes/RenderNode.h"
#include "Engine/Nodes/MovementNode.h"

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
        movementNode = new MovementNode(pos, new VelocityComponent(0, -2));

        this->add_component(renderNode);
        this->add_component(movementNode);
    };
    ~Projectile() {
        delete renderNode;
        delete movementNode;
    };

    void update() override {
        lifespan--;

        if(lifespan <= 0){
            Engine::getInstance().remove_entity(this);
        }
    }
};


#endif
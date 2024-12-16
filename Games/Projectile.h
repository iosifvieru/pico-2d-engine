#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "Engine/Entity/Entity.h"
#include "Engine/Nodes/RenderNode.h"
#include "Engine/Nodes/MovementNode.h"

uint16_t projectile_texture[4] = {
    0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF
};

class Projectile : public Entity {
private:
    int lifespan = 100;
public:
    Projectile(uint16_t x, uint16_t y) : Entity() {
        PositionComponent* projectile_position = new PositionComponent(x, y, 0, 0);
        SpriteComponent* projectile_sprite = new SpriteComponent(2, 2, projectile_texture);
        
        RenderNode* render_node = new RenderNode(projectile_position, projectile_sprite);

        VelocityComponent* projectile_velocity = new VelocityComponent(0, -1);
        MovementNode* movement = new MovementNode(projectile_position, projectile_velocity);

        this->add_component(render_node);
        this->add_component(movement);
    };
    ~Projectile() {

    };

    void update() override {
        /*
        should detect colision and stuff.
        */

       lifespan--;

       if(lifespan <= 0){
            RenderNode* rn = (RenderNode*)this->get_component("RenderNode");
            if(rn == nullptr){
                return;
            }

            rn->is_visible = false;
       }
    }
};


#endif
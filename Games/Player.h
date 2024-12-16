#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Engine/Entity/Entity.h"
#include "Engine/Nodes/RenderNode.h"
#include "Engine/Nodes/MovementNode.h"

#include "Engine/Drivers/InputDriver/Keyboard.h"

#define W_KEY 15
#define S_KEY 13
#define A_KEY 8
#define D_KEY 14

uint16_t player_texture[4] = {
    0xF11F, 0xF22F,
    0xB11F, 0xBBBB
};

class Player : public Entity {
public:
    Player() : Entity(){
        /* renderable part */
        PositionComponent* player_position = new PositionComponent(60, 120, 0, 0);
        SpriteComponent* player_sprite = new SpriteComponent(2, 2, player_texture);
        
        RenderNode* render_node = new RenderNode(player_position, player_sprite);

        /* movement part */
        VelocityComponent* player_velocity = new VelocityComponent(0, 0);
        MovementNode* movement = new MovementNode(player_position, player_velocity);

        this->add_component(render_node);
        this->add_component(movement);
    };

    ~Player(){

    };

    void update() override {
        Keyboard& keyboard = Keyboard::getInstance();
        MovementNode* movement_node = (MovementNode*) this->get_component("MovementNode");

        if(movement_node == nullptr){
            return;
        }

        movement_node->velocity->v_x = 0;
        movement_node->velocity->v_y = 0;


        if(keyboard.is_pressed(D_KEY)){
            movement_node->velocity->v_x = 5;
        }

        if(keyboard.is_pressed(A_KEY)){
            movement_node->velocity->v_x = -5;
        }
    }
};

#endif
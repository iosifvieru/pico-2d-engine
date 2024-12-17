#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Engine/Logger/Logger.h"

#include "Engine/Entity/Entity.h"
#include "Engine/Nodes/RenderNode.h"
#include "Engine/Nodes/MovementNode.h"
#include "Engine/Nodes/SquareCollider.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"

#include "Games/Projectile.h"

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
        Logger::log("Player()");

        /* renderable part */
        PositionComponent* player_position = new PositionComponent(60, 120, 0, 0);
        SpriteComponent* player_sprite = new SpriteComponent(2, 2, player_texture);
        
        RenderNode* render_node = new RenderNode(player_position, player_sprite);

        /* movement part */
        VelocityComponent* player_velocity = new VelocityComponent(0, 0);
        MovementNode* movement = new MovementNode(player_position, player_velocity);

        SquareCollider* sq = new SquareCollider(new SquareComponent(
            player_position->x, player_position->y, 
            player_position->x + player_sprite->width, player_position->y + player_sprite->height
            ));

        this->add_component(render_node);
        this->add_component(movement);
        this->add_component(sq);
        
        Keyboard& keyboard = Keyboard::getInstance();
        keyboard.config(W_KEY);
        keyboard.config(S_KEY);
        keyboard.config(A_KEY);
        keyboard.config(D_KEY);
    };

    ~Player(){
        Logger::log("~Player()");
        Engine::getInstance().remove_entity(this);
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

        if(keyboard.is_pressed(S_KEY)){
            PositionComponent* p1 = new PositionComponent(movement_node->position->x, movement_node->position->y, 0, 0);
            Engine::getInstance().add_entity(new Projectile(p1->x, p1->y));
        }

        /* test */
        SquareCollider* sq = (SquareCollider*) this->get_component("SquareCollider");
        if(sq == nullptr) return;

        sq->square_collider->min_x = movement_node->position->x;
        sq->square_collider->min_y = movement_node->position->y;

        sq->square_collider->max_x = sq->square_collider->min_x + 2;
        sq->square_collider->max_y = sq->square_collider->min_y + 2;
    }
};

#endif
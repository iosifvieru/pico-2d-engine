#ifndef _PLAYER_SYSTEM_H_
#define _PLAYER_SYSTEM_H_

#include "Engine/Systems/System.h"
#include "Engine/Components/TagComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/SquareComponent.h"
#include "Games/platformer_game/Components/LifetimeComponent.h"

#include "Engine/Drivers/InputDriver/Keyboard.h"
#include "Games/platformer_game/Keys.h"

#include "Games/platformer_game/Player.h"

#define GRAVITY 0.05f
#define MAX_GRAVITY 5.0f
#define JUMP_FORCE -1.5f
#define BULLET_SPEED 2.1f

void shoot(float x, float y, bool flip = false){
    Entity* bullet = new Entity();
    bullet->add_component(new PositionComponent(x, y));

    if(flip == true){
        bullet->add_component(bullet_frame1_flipped);
        bullet->add_component(new VelocityComponent(-BULLET_SPEED, 0));
    } else {
        bullet->add_component(bullet_frame1);
        bullet->add_component(new VelocityComponent(BULLET_SPEED, 0));
    }
    bullet->add_component(new LifetimeComponent(60));

    Engine::getInstance().add_entity(bullet);
}

class PlayerSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) {
        static bool flip = false;
        static bool falling = false;

        Keyboard& keyboard = Keyboard::getInstance();
        
        TagComponent* tag = (TagComponent*) player->get_component("TagComponent");
        if (tag == nullptr || tag->tag != TAG::PLAYER) return;

        VelocityComponent* v = (VelocityComponent*) player->get_component("VelocityComponent");
        if (v == nullptr) return;

        SquareComponent* sq = (SquareComponent*) player->get_component("SquareComponent");

        PositionComponent* p = (PositionComponent*) player->get_component("PositionComponent");
        if(p == nullptr) return;

        SpriteComponent* s = (SpriteComponent*) player->get_component("SpriteComponent");
        if(s == nullptr) return;

        if (sq != nullptr && sq->collided) {
            v->v_y = 0;
            falling = false;
        } else {
            falling = true;
            v->v_y += GRAVITY;
            if(v->v_y > MAX_GRAVITY) v->v_y = MAX_GRAVITY;

            if(flip){
                player->remove_component(s);
                player->add_component(player_falling_flipped);                
            }
        }

        if (keyboard.is_pressed(W) && sq != nullptr && sq->collided) {
           v->v_y = JUMP_FORCE;
        }

        if (keyboard.is_pressed(D) && !keyboard.is_pressed(A)) {
            v->v_x = 1;
            flip = false;

            if(!falling){
                player->remove_component(s);
                player->add_component(player_frame1);
            }
        } 
        else if (keyboard.is_pressed(A) && !keyboard.is_pressed(D)) {
            v->v_x = -1;
            flip = true;

            if(!falling){
                player->remove_component(s);
                player->add_component(player_frame1_flipped);
            }
        } 
        else {
            v->v_x = 0;
        }

        if(keyboard.is_pressed_once(S)){
            if(flip){
                player->remove_component(s);
                player->add_component(player_shooting_flipped);
            } else {
                player->remove_component(s);
                player->add_component(player_shooting);
            }

            
            shoot(p->x + 3, p->y, flip);
        }
    }
};

#endif

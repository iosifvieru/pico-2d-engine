#include "Games/pong/PongSystems/InputSystem.h"

#include "Engine/Random.h"

#define UP_KEY 8
#define DOWN_KEY 14
#define SPEED 6

/* 
    checks for input and moves the player's position. 
*/
void InputSystem::update(const std::vector<Entity*>& entities){
    Keyboard& keyboard = Keyboard::getInstance();

    for(const auto& entity : entities){
        VelocityComponent* velocity = (VelocityComponent*) entity->get_component("VelocityComponent");
        if(velocity == nullptr) continue;

        TagComponent* tag_component = (TagComponent*) entity->get_component("TagComponent");
        if(tag_component == nullptr) continue;

        SquareComponent* square = (SquareComponent*) entity->get_component("SquareComponent");
        if(square == nullptr) continue;

        PositionComponent* position = (PositionComponent*) entity->get_component("PositionComponent");
        if(!position) continue;

        if(tag_component->tag == TAG::PLAYER){
            velocity->v_y = 0;

            if(keyboard.is_pressed(UP_KEY)){
                velocity->v_y = -SPEED;
            }

            if(keyboard.is_pressed(DOWN_KEY)){
                velocity->v_y = SPEED;
            }
        }

        if(tag_component->tag == TAG::ENEMY){
            PositionComponent* ball_position = get_ball_position();
            if(!ball_position) continue;

            velocity->v_y = 0;
            if(position->y > ball_position->y){
                velocity->v_y = -1;
            }

            if(position->y < ball_position->y){
                velocity->v_y = 1;
            }

            if(position->y == ball_position->y){
                velocity->v_y = 0;
            }
        }

        if(tag_component->tag == TAG::ENTITY){
            PositionComponent* ball_position = get_ball_position();

            if(ball_position->y <= 0 || ball_position->y >= 128){
                velocity->v_y = -velocity->v_y;
            }
        }
    }
}
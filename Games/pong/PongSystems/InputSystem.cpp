#include "Games/pong/PongSystems/InputSystem.h"

#include "Engine/Random.h"

#define UP_KEY 8
#define DOWN_KEY 14
#define SPEED 6

bool goal = false;

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

            if (position->y <= 2) {
                position->y = 0;
                if (velocity->v_y < 0) {
                    velocity->v_y = 0;
                }
            }

            if (square->get_max_y() >= 128) {
                if (velocity->v_y > 0) {
                    velocity->v_y = 0;
                }
            }
        }

        if(tag_component->tag == TAG::ENEMY){
            PositionComponent* ball_position = get_ball_position();
            if(!ball_position) continue;

            if(position->y > ball_position->y){
                velocity->v_y = -1;
            } else if(position->y < ball_position->y){
                velocity->v_y = 1;
            } else if(position->y == ball_position->y){
                velocity->v_y = 0;
            }
        
            if(square->get_max_y() >= 128){
                velocity->v_y = 0;
                if (ball_position->y < position->y) {
                    velocity->v_y = -1;
                } else {
                    velocity->v_y = 0;
                }
            }
        }

        if(tag_component->tag == TAG::ENTITY){
            PositionComponent* ball_position = get_ball_position();
            SquareComponent* ball_collision = get_ball_collision();

            if(ball_position->y <= 2 || ball_position->y + ball_collision->get_height() >= 128){
                velocity->v_y = -velocity->v_y;
            }

            if(ball_collision->collided && ball_position->x + ball_collision->get_width() >= 128){
                velocity->v_x = -velocity->v_x;
            }

            if(ball_collision->collided && ball_position->x <= 0){
                velocity->v_x = -velocity->v_x;
                velocity->v_y += (rnd() % 2) - 1;
            }

            if(ball_position->x < 0){
                ball_reset(50, 50);
            }

            if(ball_position->x > 128){
                ball_reset(50, 50);
            }
        }
    }
}
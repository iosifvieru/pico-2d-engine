#include "Games/pong/Systems/PlayerSystem.h"

void PongPlayerSystem::update(const std::vector<Entity*>& entities){
    Keyboard& keyboard = Keyboard::getInstance();

    for(const auto& entity: entities){
        TagComponent* tag = (TagComponent*)entity->get_component("TagComponent");
        if(tag == nullptr || tag->tag != TAG::PLAYER) continue;
        
        PositionComponent* pos = (PositionComponent*) entity->get_component("PositionComponent");
        if(pos == nullptr) continue;

        VelocityComponent* velocity = (VelocityComponent*) entity->get_component("VelocityComponent");
        if(velocity == nullptr) continue;            

        if(pos->y <= Y_TOP_LIMIT){
            pos->y = Y_TOP_LIMIT;
            velocity->v_y = 0;
        }

        if(pos->y + PADDLE_HEIGHT >= Y_BOTTOM_LIMIT){
            pos->y = Y_BOTTOM_LIMIT - PADDLE_HEIGHT;
            velocity->v_y = 0;
        }

        if(keyboard.is_pressed(W)){
            velocity->v_y = PLAYER_SPEED;
        }

        else if(keyboard.is_pressed(S)){
            velocity->v_y = -PLAYER_SPEED;
        }
    }
}

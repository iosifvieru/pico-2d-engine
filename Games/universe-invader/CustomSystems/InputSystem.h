#ifndef _INPUT_SYSTEM_H_
#define _INPUT_SYSTEM_H_

#include "Engine/Systems/System.h"
#include "Engine/Drivers/InputDriver/Keyboard.h"
#include "Engine/Components/VelocityComponent.h"

#include "Games/universe-invader/CustomComponents/TagComponent.h"

#define LEFT_KEY 8
#define RIGHT_KEY 14
#define PLAYER_SPEED 8


class InputSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) {
        for(const auto& entity: entities){
            TagComponent* tag_component = (TagComponent*) entity->get_component("TagComponent");
            /* skipping non player entities. */
            if(tag_component == nullptr ||
                tag_component->tag != TAG::PLAYER
            ) continue;

            VelocityComponent* velocity = (VelocityComponent*) entity->get_component("VelocityComponent");
            if(velocity == nullptr) continue;

            velocity->v_x = 0;
            /* moving left */
            if(Keyboard::getInstance().is_pressed(LEFT_KEY)){
                velocity->v_x = -PLAYER_SPEED;
            }

            if(Keyboard::getInstance().is_pressed(RIGHT_KEY)){
                velocity->v_x = PLAYER_SPEED;
            }
        }
    }
};

#endif
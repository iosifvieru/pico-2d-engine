#ifndef _ENEMY_MOVEMENT_SYSTEM_H_
#define _ENEMY_MOVEMENT_SYSTEM_H_

#include "Engine/Systems/System.h"

#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Games/universe-invader/CustomComponents/TagComponent.h"
#include "Games/universe-invader/CustomComponents/StateComponent.h"

#include "Engine/Random.h"

/*
needs a position component and a velocity component.
*/

class EnemySystem : public System {
public:
    void update(const std::vector<Entity*>& entities) {
        for(const auto& entity : entities){
            PositionComponent* position = (PositionComponent*) entity->get_component("PositionComponent");
            VelocityComponent* velocity = (VelocityComponent*) entity->get_component("VelocityComponent");
            TagComponent* tag = (TagComponent*) entity->get_component("TagComponent");
            StateComponent* enemy_state = (StateComponent*) entity->get_component("StateComponent");
            HealthComponent* health_component = (HealthComponent*) entity->get_component("HealthComponent");
            if(position == nullptr || velocity == nullptr || 
                tag == nullptr || enemy_state == nullptr ||
                health_component == nullptr) continue;
            
            /* skipping non enemy entities. */
            if(tag->tag != TAG::ENEMY) continue;

            /* defining the enemy behaviour */
            if(enemy_state->state == States::Idle){
                velocity->v_x = 1;

                if(position->x > 100){
                    enemy_state->state = States::Moving;
                }
            }

            if(enemy_state->state == States::Moving){
                velocity->v_x = -1;

                if(position->x <= 10){
                    enemy_state->state = States::Idle;
                }
            }

            if(health_component->health <= 0){
                enemy_state->state = States::Dead;
            }

            if(enemy_state->state == States::Dead){
                Engine::getInstance().remove_entity(entity);
            }

        }

    };
};

#endif
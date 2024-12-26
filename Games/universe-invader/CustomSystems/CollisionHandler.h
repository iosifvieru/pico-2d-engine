#ifndef _COLLISION_HANDLER_H_
#define _COLLISION_HANDLER_H_

#include "Engine/Components/SquareComponent.h"

#include "Games/universe-invader/CustomComponents/TagComponent.h"
#include "Engine/Systems/System.h"

#include "Engine/Engine.h"
#include "Games/universe-invader/Game.h"
#include "Games/universe-invader/CustomComponents/HealthComponent.h"


class CollisionHandler : public System {
public:
    void update(const std::vector<Entity*>& entities) {
        for(const auto& entity : entities){
            if(entity == nullptr) continue;

            TagComponent* tag_component = (TagComponent*) entity->get_component("TagComponent");
            SquareComponent* collision = (SquareComponent*) entity->get_component("SquareComponent");
            if(tag_component == nullptr || collision == nullptr) continue;

            if(tag_component->tag == TAG::ENEMY && collision->collided == true){
                HealthComponent* health_component = (HealthComponent*) entity->get_component("HealthComponent");
                if(health_component == nullptr){
                    Engine::getInstance().remove_entity(entity);
                } else {
                    health_component->health -= 20;
                }
            }

            if(tag_component->tag == TAG::PROJECTILE && collision->collided == true){
                Engine::getInstance().remove_entity(entity);
            }

            /* other behaviours.. */
        }
    }
};

#endif
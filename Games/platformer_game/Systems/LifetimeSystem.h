#ifndef _LIFETIME_SYSTEM_H_
#define _LIFETIME_SYSTEM_H_

#include "Engine/Engine.h"
#include "Engine/Systems/System.h"
#include "Games/platformer_game/Components/LifetimeComponent.h"

class LifetimeSystem : public System {
public:
    void update(const std::vector<Entity*>& entities) {
        for(const auto& entity: entities){
            LifetimeComponent* lf = (LifetimeComponent*) entity->get_component("LifetimeComponent");

            lf->time--;

            if(lf->time <= 0){
                Engine::getInstance().remove_entity(entity);
            }
        }
    }
};


#endif
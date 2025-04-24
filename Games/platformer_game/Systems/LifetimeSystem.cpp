
#include "Games/platformer_game/Systems/LifetimeSystem.h"

void LifetimeSystem::update(const std::vector<Entity*>& entities) {
    for(const auto& entity: entities){
        LifetimeComponent* lf = (LifetimeComponent*) entity->get_component("LifetimeComponent");

        lf->time--;

        if(lf->time <= 0){
            Engine::getInstance().remove_entity(entity);
        }
    }
}
#ifndef _PROJECTILE_SYSTEM_H_
#define _PROJECTILE_SYSTEM_H_

#include "Engine/Systems/System.h"
#include "Games/universe-invader/CustomComponents/ProjectileComponent.h"

#include "Engine/Components/PositionComponent.h"
#include "Engine/Engine.h"

#include "Engine/Logger/Logger.h"
#include "Games//universe-invader/Game.h"

class ProjectileSystem : public System {
    void update(const std::vector<Entity*>& entities){
        for(const auto& entity : entities){
            if(entity == nullptr) continue;

            ProjectileComponent* projectile_component = (ProjectileComponent*) entity->get_component("ProjectileComponent");
            if(projectile_component == nullptr) continue;

            if(projectile_component->life_time >= 0){
                projectile_component->life_time--;
            } else {
                Engine::getInstance().remove_entity(entity);
            }
        }
    }
};

#endif
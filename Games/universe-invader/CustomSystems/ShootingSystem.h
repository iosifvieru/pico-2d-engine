#ifndef _SHOOTING_SYSTEM_H_
#define _SHOOTING_SYSTEM_H_

#include "Engine/Systems/System.h"
#include "Games/universe-invader/CustomComponents/ShootingComponent.h"
#include "Engine/Components/PositionComponent.h"

// just for test
#include "Engine/Drivers/InputDriver/Keyboard.h"    
#include "Engine/Logger/Logger.h"

#include "Games/universe-invader/Game.h"

class ShootingSystem : public System {
    void update(const std::vector<Entity*>& entities){
        //Logger::log("Am intrat in shooting system.");
        for(const auto& entity : entities){
            if(entity == nullptr) continue;
            PositionComponent* position = (PositionComponent*) entity->get_component("PositionComponent");
            ShootingComponent* shooting_component = (ShootingComponent*) entity->get_component("ShootingComponent");
            if(shooting_component == nullptr || position == nullptr) continue;

            if(Keyboard::getInstance().is_pressed(13)){
                if(shooting_component->ammo > 0){
                    shooting_component->ammo--;

                    create_projectile(position->x, position->y - 5);
                }
            }
        }
        //Logger::log("Ies din shooting system.");
    }
};

#endif
#ifndef _SHOOTING_SYSTEM_H_
#define _SHOOTING_SYSTEM_H_

#include "Engine/Systems/System.h"
#include "Games/CustomComponents/ShootingComponent.h"
#include "Engine/Components/PositionComponent.h"

// just for test
#include "Engine/Drivers/InputDriver/Keyboard.h"    

#include "Games/Game.h"

class ShootingSystem : public System {
    void update(const std::vector<Entity*>& entities){
        for(const auto& entity : entities){
            ShootingComponent* shooting_component = (ShootingComponent*) entity->get_component("ShootingComponent");
            if(shooting_component == nullptr) continue;

            PositionComponent* position = (PositionComponent*) entity->get_component("PositionComponent");
            if(position == nullptr) continue;

            if(Keyboard::getInstance().is_pressed(13) && shooting_component->ammo > 0){
                shooting_component->ammo--;

                create_projectile(position->x, position->y);
            }
        }
    }
};

#endif
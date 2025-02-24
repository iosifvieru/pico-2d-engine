#include "Engine/Systems/MovementSystem.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/PositionComponent.h"

void MovementSystem::update(const std::vector<Entity*>& entities){
    for(const auto& entity: entities){
        PositionComponent* p = (PositionComponent*) (entity->get_component("PositionComponent"));
        if(p == nullptr) continue;

        VelocityComponent* velocity = (VelocityComponent*)(entity->get_component("VelocityComponent"));
        if(velocity == nullptr) continue;

        p->x += velocity->v_x;
        p->y += velocity->v_y;

        if (p->x < 0) p->x = 0;
        if (p->y < 0) p->y = 0;
    }
}
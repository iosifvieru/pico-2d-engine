#include "Engine/Systems/CameraSystem.h"

#include "Engine/Components/CameraComponent.h"
#include "Engine/Components/PositionComponent.h"

#include "Engine/Logger/Logger.h"

void CameraSystem::update(const std::vector<Entity*>& entities){
    for(const auto& entity: entities){
        PositionComponent* p = (PositionComponent*) (entity->get_component("PositionComponent"));
        if(p == nullptr) continue;

        CameraComponent* camera = (CameraComponent*) entity->get_component("CameraComponent");
        if(camera == nullptr) continue;

        camera->x = p->x - (camera->width / 2);
        camera->y = p->y - (camera->height / 2);

        if (camera->x < 0) camera->x = 0;
        if (camera->y < 0) camera->y = 0;

        Logger::log("CameraX: %d, CameraY: %d", camera->x, camera->y);
    }
}
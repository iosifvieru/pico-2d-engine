#include "Engine/Systems/CameraSystem.h"

#include "Engine/Components/CameraComponent.h"
#include "Engine/Components/PositionComponent.h"

#include "Engine/Logger/Logger.h"

void CameraSystem::update(const std::vector<Entity*>& entities) {
    for (const auto& entity : entities) {
        CameraComponent* camera = (CameraComponent*)entity->get_component("CameraComponent");
        if (camera == nullptr) continue;

        PositionComponent* p = (PositionComponent*)entity->get_component("PositionComponent");
        if (p == nullptr) continue;

        float targetX = p->x - (camera->width / 2) + 8;
        float targetY = p->y - (camera->height / 2) + 8;

        float smoothingFactor = 0.05f;
        camera->x += (targetX - camera->x) * smoothingFactor;
        camera->y += (targetY - camera->y) * smoothingFactor;

        if (camera->x < 0) camera->x = 0;
        if (camera->y < 0) camera->y = 0;

        float maxX = 16 * 8;
        float maxY = 16 * 8;

        if (camera->x > maxX) camera->x = maxX;
        if (camera->y > maxY) camera->y = maxY;
    }
}

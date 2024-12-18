#include "Engine/Systems/CollisionSystem.h"
#include "Engine/Nodes/SquareCollider.h"

void CollisionSystem::update(std::list<Entity*> entities) {
    for (auto it1 = entities.begin(); it1 != entities.end(); ++it1) {
        Entity* entity1 = *it1;
        if (!entity1->has_component("SquareCollider")) continue;

        SquareCollider* collider1 = (SquareCollider*)entity1->get_component("SquareCollider");
        if (collider1 == nullptr) continue;

        for (auto it2 = entities.begin(); it2 != entities.end(); ++it2) {
            Entity* entity2 = *it2;
            if (!entity2->has_component("SquareCollider")) continue;

            if (entity1 == entity2) continue;

            SquareCollider* collider2 = (SquareCollider*)entity2->get_component("SquareCollider");
            if (collider2 == nullptr) continue;

            collider1->is_visible = collider1->has_collided(collider2);
            collider2->is_visible = collider1->is_visible;
            
        }
    }
}

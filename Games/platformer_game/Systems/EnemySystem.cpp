
#include "Games/platformer_game/Systems/EnemySystem.h"

void EnemySystem::update(const std::vector<Entity*>& entities) {
    if(player == nullptr){ return; }
    for(const auto& entity : entities){
        /* if the entity is not an enemy -> moving to the next. */
        TagComponent* tag = (TagComponent*) entity->get_component("TagComponent"); 
        if(tag->tag != TAG::ENEMY || tag == nullptr) continue;

        PositionComponent* player_position = (PositionComponent*) player->get_component("PositionComponent");
        if(!player_position) break;

        PositionComponent* enemy_position = (PositionComponent*) entity->get_component("PositionComponent");
        if(!enemy_position) continue;

        VelocityComponent* enemy_velocity = (VelocityComponent*) entity->get_component("VelocityComponent");
        if(!enemy_velocity) continue;

        if(enemy_position->x < player_position->x){
            enemy_velocity->v_x = ENEMY_SPEED;
        } else if(enemy_position->x > player_position->x) {
            enemy_velocity->v_x = -ENEMY_SPEED; 
        } else {
            enemy_velocity->v_x = 0;
        }
    }
}


#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/SpriteComponent.h"
#include "Engine/Components/VelocityComponent.h"
#include "Engine/Components/SquareComponent.h"

#include "CustomComponents/ShootingComponent.h"
#include "CustomComponents/ProjectileComponent.h"

#include "Games/universe-invader/Game.h"

#include "Assets.h"

#include "Engine/Logger/Logger.h"
#include "Games/universe-invader/CustomComponents/TagComponent.h"
#include "Games/universe-invader/CustomComponents/HealthComponent.h"

uint16_t enemy_texture[4] = {
    0xfffe, 0xfffe, 0xfffe, 0xfffe
};

SpriteComponent* enemy_sprite = new SpriteComponent(2, 2, enemy_texture);
SpriteComponent* player_sprite = new SpriteComponent(16, 16, aircraft);

VelocityComponent* bullet_velocity = new VelocityComponent(0, -2);

TagComponent* shared_enemy_tag = new TagComponent(TAG::ENEMY);
TagComponent* shared_bullet_tag = new TagComponent(TAG::PROJECTILE);

void game_init(){
    if(enemy_sprite){
        enemy_sprite->make_shared(true);
        Logger::log("AM facut enemy sprite shared.");
    }
    if(player_sprite){
        player_sprite->make_shared(true);
        Logger::log("AM facut player sprite shared.");
    }
    if(bullet_velocity){
        bullet_velocity->make_shared(true);
        Logger::log("AM facut bullet velocity shared.");
    }

    if(shared_enemy_tag){
        shared_enemy_tag->make_shared(true);
    }
    if(shared_bullet_tag){
        shared_bullet_tag->make_shared(true);
    }
}

void create_enemy(uint16_t x, uint16_t y){
    Entity* e = new Entity();
    
    PositionComponent* position = new PositionComponent(x, y, 0, 0);

    e->add_component(new PositionComponent(x, y, 0, 0));
    e->add_component(enemy_sprite);
    e->add_component(shared_enemy_tag);
    
    e->add_component(new SquareComponent(position->x, position->y, 2, 2));
    e->add_component(new HealthComponent(100));
    Engine::getInstance().add_entity(e);
}

void create_player(uint16_t x, uint16_t y){
    Entity* e = new Entity();
    
    e->add_component(new PositionComponent(x, y, 0, 0));
    e->add_component(player_sprite);

    e->add_component(new ShootingComponent(50, 0));

    Engine::getInstance().add_entity(e);
}

void create_projectile(uint16_t x, uint16_t y){
    Entity* e = new Entity();

    e->add_component(new PositionComponent(x, y, 0, 0));
    e->add_component(enemy_sprite);
    e->add_component(bullet_velocity);

    e->add_component(new ProjectileComponent(100));
    e->add_component(new SquareComponent(0, 0, 2, 2));
    e->add_component(shared_bullet_tag);

    if(e == nullptr) return;
    Logger::log("Am creat proiectil");

    Engine::getInstance().add_entity(e);
}
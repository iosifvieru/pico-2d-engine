#include "Games/platformer_game/Systems/PlayerSystem.h"

void shoot(float x, float y, bool flip = false){
    Entity* bullet = Entity::create();
    if(bullet == nullptr) return;
    
    bullet->add_component(new PositionComponent(x, y));

    if(flip == true){
        bullet->add_component(bullet_frame1_flipped);
        bullet->add_component(new VelocityComponent(-BULLET_SPEED, 0));
    } else {
        bullet->add_component(bullet_frame1);
        bullet->add_component(new VelocityComponent(BULLET_SPEED, 0));
    }
    bullet->add_component(new LifetimeComponent(60));

    Engine::getInstance().add_entity(bullet);
}

void PlayerSystem::update(const std::vector<Entity*>& entities) {
    Keyboard& keyboard = Keyboard::getInstance();

    VelocityComponent* v = (VelocityComponent*) player->get_component("VelocityComponent");
    SquareComponent* sq = (SquareComponent*) player->get_component("SquareComponent");
    PositionComponent* p = (PositionComponent*) player->get_component("PositionComponent");
    SpriteComponent* s = (SpriteComponent*) player->get_component("SpriteComponent");
    GravityComponent* g = (GravityComponent*) player->get_component("GravityComponent");

    if(!v || !p || !sq || !s || !g) return;

    if (keyboard.is_pressed(W) && sq != nullptr && sq->collided) {
        if(g->is_grounded)
            v->v_y = JUMP_FORCE;
    }

    if (keyboard.is_pressed(D) && !keyboard.is_pressed(A)) {
            v->v_x = 1;
    } 
    else if (keyboard.is_pressed(A) && !keyboard.is_pressed(D)) {
        v->v_x = -1;
    } 
    else {
        v->v_x = 0;
    }

    if(keyboard.is_pressed_once(S)){           
        shoot(p->x + 3, p->y, false);
    }
}


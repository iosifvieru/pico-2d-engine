#include "Games/pong/Systems/BallSystem.h"


void ball_reset(){
    PositionComponent* pos = (PositionComponent*) Ball->get_component("PositionComponent");
    if(pos == nullptr) return;

    VelocityComponent* v = (VelocityComponent*) Ball->get_component("VelocityComponent");
    if(v == nullptr) return;

    v->v_y = 0;
    v->v_x = 0;

    pos->x = BALL_START_X;
    pos->y = BALL_START_Y;

    has_scored = true;
}

void BallSystem::update(const std::vector<Entity*>& entities){
    if(has_scored) return;
    if(Ball == nullptr) return;

    PositionComponent* pos = (PositionComponent*) Ball->get_component("PositionComponent");
    if(pos == nullptr) return;

    VelocityComponent* v = (VelocityComponent*) Ball->get_component("VelocityComponent");
    if(v == nullptr) return;

    SquareComponent* square = (SquareComponent*) Ball->get_component("SquareComponent");
    if(square == nullptr) return;

    float ball_random = (rnd() % BALL_RANDOMNESS) / 1000.0;

    switch(square->collision_side){
        case CollisionSide::RIGHT:
            v->v_x = -BALL_SPEED - ball_random;
            break;
        case CollisionSide::LEFT:
            v->v_x = BALL_SPEED + ball_random;
            break;
        case CollisionSide::TOP:
            v->v_y = BALL_SPEED + ball_random;
            break;
        case CollisionSide::BOTTOM:
            v->v_y = -BALL_SPEED - ball_random;
            break;
        default:
            break;
    }

    if(pos->x <= 0){
        ball_reset();

        ENEMY_SCORE += 1;
    }

    if(pos->x >= X_RIGHT_LIMIT){
        ball_reset();

        PLAYER_SCORE += 1;
    }
    
    Logger::log("ball collision: %d", square->collision_side);
}
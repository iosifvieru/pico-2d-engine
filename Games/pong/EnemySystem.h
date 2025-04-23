#ifndef _PONG_ENEMY_SYSTEM_H_
#define _PONG_ENEMY_SYSTEM_H_

#include "Engine/Systems/System.h"
#include "Engine/Components/PositionComponent.h"
#include "Engine/Components/VelocityComponent.h"

#include "Games/pong/Globals.h"

class PongEnemySystem : public System {
public:
    void update(const std::vector<Entity*>& entities) override {
        if (Enemy == nullptr || Ball == nullptr) return;

        PositionComponent* enemy_pos = (PositionComponent*)Enemy->get_component("PositionComponent");
        PositionComponent* ball_pos  = (PositionComponent*)Ball->get_component("PositionComponent");

        VelocityComponent* enemy_vel = (VelocityComponent*)Enemy->get_component("VelocityComponent");

        if (!enemy_pos || !ball_pos || !enemy_vel) return;

        float enemy_center = enemy_pos->y + PADDLE_HEIGHT / 2.0f;
        float ball_center  = ball_pos->y + BALL_HEIGHT / 2.0f;

        if (abs(enemy_center - ball_center) < PADDLE_HEIGHT / 4.0f) {
            enemy_vel->v_y = 0;
        } else if (enemy_center < ball_center) {
            enemy_vel->v_y = PLAYER_SPEED - 0.15;
        } else {
            enemy_vel->v_y = -PLAYER_SPEED + 0.15;
        }

        if (enemy_pos->y < Y_TOP_LIMIT) {
            enemy_pos->y = Y_TOP_LIMIT;
        }
        if (enemy_pos->y + PADDLE_HEIGHT > Y_BOTTOM_LIMIT) {
            enemy_pos->y = Y_BOTTOM_LIMIT - PADDLE_HEIGHT;
        }
    }
};

#endif

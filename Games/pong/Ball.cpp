#include "Games/pong/Ball.h"

void create_ball(uint16_t x, uint16_t y, int8_t speed){
    Entity* ball = new Entity();

    PositionComponent* position = new PositionComponent(x, y, 0, 0);
    if(position == nullptr){ return; }

    ball->add_component(position);

    VelocityComponent* velocity = new VelocityComponent(0, -speed);
    if(velocity == nullptr) return;

    ball->add_component(velocity);

    SpriteComponent* sprite = new SpriteComponent(3, 3, ball_sprite);
    if(sprite == nullptr) return;
    ball->add_component(sprite);

    TagComponent* tag = new TagComponent(TAG::ENTITY);
    if(tag == nullptr) return;
    ball->add_component(tag);

    SquareComponent* square = new SquareComponent(position->x, position->y, sprite->width, sprite->height);
    if(square == nullptr) return;

    ball->add_component(square);

    Engine::getInstance().add_entity(ball);
}

/* 
    this only works because i know for sure that there is only one "BALL" in the game. 

    basically returns the first entity it finds.
*/
PositionComponent* get_ball_position(){
    for(const auto& entity: Engine::getInstance().get_entities()){
        TagComponent* tag = (TagComponent*) entity->get_component("TagComponent");
        if(tag == nullptr) continue;

        if(tag->tag == TAG::ENTITY){
            return (PositionComponent*) entity->get_component("PositionComponent");
        }
    }

    return nullptr;
}
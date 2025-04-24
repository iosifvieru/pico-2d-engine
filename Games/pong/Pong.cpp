
#include "Games/pong/Pong.h"

/* fast pointers to entities */
Entity* Pong_UI = nullptr;
Entity* Ball = nullptr;
Entity* Enemy = nullptr;

void load_walls(){
    Entity* top_wall = Entity::create();
    if(top_wall == nullptr) return;

    top_wall->add_component(new PositionComponent(0, -2));
    top_wall->add_component(new SquareComponent(0, 0, 128, 4));

    Engine::getInstance().add_entity(top_wall);

    Entity* bottom_wall = Entity::create();
    if(bottom_wall == nullptr) return;

    bottom_wall->add_component(new PositionComponent(0, 130));
    bottom_wall->add_component(new SquareComponent(0, 0, 128, 4));
    Engine::getInstance().add_entity(bottom_wall);
}

void load_player(int x, int y){
    Entity* p = Entity::create();
    if(p == nullptr) return;
    Logger::log("Can't initialize player.");

    p->add_component(new PositionComponent(x, y));
    p->add_component(new SquareComponent(0, 0, PADDLE_WIDTH, PADDLE_HEIGHT));
    p->add_component(new TagComponent(TAG::PLAYER));
    p->add_component(new VelocityComponent(0, 0));

    Engine::getInstance().add_entity(p);
}

void load_enemy(int x, int y){
    Entity* e = Entity::create();
    if(e == nullptr) return;
    Logger::log("Can't initialize enemy.");

    e->add_component(new PositionComponent(x, y));
    e->add_component(new SquareComponent(0, 0, PADDLE_WIDTH, PADDLE_HEIGHT));
    e->add_component(new VelocityComponent(0,0));
    
    Engine::getInstance().add_entity(e);

    Enemy = e;
}

void load_ball(int x, int y){
    Entity* b = Entity::create();
    if(b == nullptr) return;
    Logger::log("Can't initialize ball.");

    b->add_component(new PositionComponent(x, y));
    b->add_component(new SquareComponent(0, 0, BALL_WIDTH, BALL_HEIGHT));
    b->add_component(new VelocityComponent(-0.5, 0.5));

    Engine::getInstance().add_entity(b);
    Ball = b;
}

void load_UI(){
    Entity* score = Entity::create();
    if(score == nullptr) return;

    std::string score_text = std::to_string(PLAYER_SCORE) + ":" + std::to_string(ENEMY_SCORE);
    score->add_component(new TextComponent(64 - ((score_text.size()-1) / 2) * FONT_WIDTH, FONT_HEIGHT, score_text));

    Engine::getInstance().add_entity(score);
    Pong_UI = score;
}

void pong_init(){
    /* reference to display */
    Display& display = ST7735::getInstance();

    /* creating a canvas */
    BufferedCanvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());

    Keyboard& keyboard = Keyboard::getInstance();
    keyboard.config(W);
    keyboard.config(S);
    keyboard.config(A);
    
    /* render system */
    RenderSystem* render_system = new RenderSystem(canvas, &display);
    Engine::getInstance().add_system(render_system);
    Engine::getInstance().add_system(new CollisionSystem());

    Engine::getInstance().add_system(new MovementSystem());

    load_walls();
    load_player(PLAYER_START_X, PLAYER_START_Y);
    load_enemy(ENEMY_START_X, ENEMY_START_Y);
    load_ball(BALL_START_X, BALL_START_Y);
    load_UI();

    ball_reset();
    has_scored = true;

    Engine::getInstance().add_system(new PongPlayerSystem());
    Engine::getInstance().add_system(new PongUISystem());
    Engine::getInstance().add_system(new BallSystem());
    Engine::getInstance().add_system(new PongGameSystem());
    Engine::getInstance().add_system(new PongEnemySystem());

    Logger::log("Game initialized.");
}

#include "Menu.h"
#include "Engine/Drivers/DisplayDriver/ST7735.h"


std::list<std::string> games = {"Platformer", "Pong"};

void config_keyboard(){
    Keyboard& keyboard = Keyboard::getInstance();
    keyboard.config(W);
    keyboard.config(S);
    keyboard.config(ENTER);
}

/* display initialization */
void config_display(){
    Display& display = ST7735::getInstance();
    BufferedCanvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());
    Engine::getInstance().add_system(new RenderSystem(canvas, &display));
}

void config_game_list(){
/*
    going through all the games in the list and create an entity.
*/
    int i = 3;
    for(std::string game: games){
        Entity* e = Entity::create();
        if(e == nullptr) break;

        e->add_component(new TextComponent(20, i * FONT_HEIGHT, game));
        Engine::getInstance().add_entity(e);

        i += 1;
    }
}

void config_title(){
    Entity* pico_text = Entity::create();
    if(pico_text == nullptr) return;

    pico_text->add_component(new TextComponent((128/2) - 3.5 * FONT_WIDTH, 12, "Pico 2D"));
    Engine::getInstance().add_entity(pico_text);
}

void load_menu() {
    config_display();
    config_title();
    config_game_list();
    config_keyboard();

    Engine::getInstance().add_system(new MenuSystem());
}
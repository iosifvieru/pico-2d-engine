#include "Engine.h"

#include <algorithm>

Engine* Engine::instance = nullptr;

Engine::Engine(){

}

Engine::~Engine(){
    // will clean up someday.
}

void Engine::add_entity(Entity* entity){
    if(entity == nullptr){
        return;
    }

    this->entities.push_back(entity);
}

void Engine::remove_entity(Entity* entity){
    if(entity == nullptr){
        return;
    }

    deleted_entities.push_back(entity);
}

void Engine::add_system(System* system){
    if(system == nullptr){
        return;
    }

    this->systems.push_back(system);
}


void Engine::remove_system(System* system){
    return;
}

void Engine::update(){
    for(const auto& system : this->systems){
        system->update(this->entities);
    }

    delete_entities();
}

void Engine::delete_entities() {
    for (const auto& entity : deleted_entities) {
        if(entity == nullptr) continue;

        entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
        delete entity;
    }
    deleted_entities.clear();
}

void Engine::run(uint8_t framerate){
    uint64_t frame_time_us = 1000000 / framerate;
    uint64_t previous_time = time_us_64();

    /* engine reference for fast update call */
    Engine& engine = Engine::getInstance();

    /* game loop */
    while(1){
        uint64_t current_time = time_us_64();
        uint64_t elapsed_time = current_time - previous_time;

        if(elapsed_time >= frame_time_us){
            /* update all systems */
            engine.update();
            
            previous_time = current_time;
            elapsed_time = time_us_64() - current_time;
            if(elapsed_time < frame_time_us){
                sleep_us(frame_time_us - elapsed_time);
            }
        }
    }
}
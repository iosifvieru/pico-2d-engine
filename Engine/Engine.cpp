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
    Logger::log("Am sters nod. ");
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
    for(auto& system : this->systems){
        system->update(this->entities);
    }
    
    for(auto& entity : this->entities){
        entity->update();
    }
    
    delete_entities();
}

void Engine::delete_entities(){
    for (auto* entity : deleted_entities) {
        if(entity == nullptr) continue;

        Logger::log("SUNT IN DELETE ENTITIES.");
        this->entities.remove(entity);
        delete entity;
        entity = nullptr;
    }
    deleted_entities.clear();

    Logger::log("IES DIN DELETE ENTITIES.");
}
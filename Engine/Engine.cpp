#include "Engine.h"

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
    return;
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
}
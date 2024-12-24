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
        //Logger::log("ENTITATEA ESTE NULL.");
        return;
    }

    this->entities.push_back(entity);
    //Logger::log("AM ADAUGAT ENTITATEA IN ENGINE.");
}

void Engine::remove_entity(Entity* entity){
    if(entity == nullptr){
        return;
    }

    deleted_entities.push_back(entity);
    //Logger::log("Am sters nod. ");
}

void Engine::add_system(System* system){
    if(system == nullptr){
        return;
    }

    this->systems.push_back(system);

    //Logger::log("AM adaugat system/");
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

        //Logger::log("SUNT IN DELETE ENTITIES.");
        //this->entities.remove(entity);
        entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
        delete entity;
        //entity = nullptr;
    }
    deleted_entities.clear();

}
#include "Engine/Entity/Entity.h"
#include "Engine/Logger/Logger.h"

#include <algorithm>
#include "string.h"

uint16_t Entity::no_entities = 0;

Entity::Entity(){
    Logger::log("Entity()");
    no_entities++;

    Logger::log("There are %d entities!", no_entities);
}

Entity* Entity::create(){
    if (no_entities >= MAX_NO_ENTITIES) {
        Logger::log("Entity limit exceeded!");
        return nullptr;
    }
    return new Entity();
}

Entity::~Entity(){
    Logger::log("~Entity()");
    no_entities--;
    
    for(const auto& component: this->components) {
        /* if a component is shared that's on you. */
        if(component == nullptr || (component->is_shared() == true)) continue;
        
        delete component;
    }

    this->components.clear();
}

void Entity::add_component(Component* component) {
    if(component == nullptr) return;
    if(this->has_component(component->get_component_name())) {
        Logger::log("[Entity]: exista deja o componenta de acest tip.");
        return;
    }
    this->components.push_back(component);
}

void Entity::remove_component(Component* component) {
    if (component == nullptr) return;
    components.erase(std::remove(components.begin(), components.end(), component), components.end());
}

/* Returns the first occurance of the component you are looking for, otherwise returns nullptr. */
const Component* Entity::get_component(const char* component_name) {
    /* iterates through all the components */
    for(const auto& component : this->components){
        if(component == nullptr) continue;

        /* checks for the right component */
        if(strcmp(component->get_component_name(), component_name) == 0){
            return component;
        }
    }
    return nullptr;
}

bool Entity::has_component(const char* component_name){
    for(const auto& component : this->components){
        if(component == nullptr) continue;
        if(strcmp(component->get_component_name(), component_name) == 0){
            return true;
        }
    }
    return false;
}
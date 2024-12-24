#include "Engine/Entity/Entity.h"
#include "Engine/Logger/Logger.h"

#include <algorithm>

uint16_t Entity::no_entities = 0;

Entity::Entity(){
    Logger::log("Entity()");
    no_entities++;
}

Entity::~Entity(){
    Logger::log("~Entity()");
    no_entities--;
    
    for(auto* component: this->components) {
        /* if a component is shared that's on you. */
        if(component == nullptr || (component->is_shared() == true)) continue;
        delete component;
    }

    this->components.clear();
}

void Entity::add_component(Component* component) {
    if(component == nullptr){
        Logger::log("add_component -> node is null.");
        return;
    }

    this->components.push_back(component);
    Logger::log("Nod adaugat cu succes.");

}

void Entity::remove_component(Component* component) {
    if (component == nullptr) {
        return;
    }

    //this->components.remove(components);
    components.erase(std::remove(components.begin(), components.end(), component), components.end());
}

Component* Entity::get_component(std::string component_name) {
    for(const auto& component : this->components){
        if(component->get_component_name() == component_name){
            return component;
        }
    }

    return nullptr;
}

bool Entity::has_component(std::string component_name){
    for(const auto& component : this->components){
        if(component->get_component_name() == component_name){
            return true;
        }
    }
    return false;
}
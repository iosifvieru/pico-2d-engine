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
    
    for(auto* node: nodes) {
        if(node == nullptr) continue;
        delete node;
    }

    this->nodes.clear();
}

void Entity::add_component(Component* node) {
    if(node == nullptr){
        Logger::log("add_component -> node is null.");
        return;
    }

    this->nodes.push_back(node);
    Logger::log("Nod adaugat cu succes.");

}

void Entity::remove_component(Component* node) {
    if (node == nullptr) {
        return;
    }

    this->nodes.remove(node);
}

Component* Entity::get_component(std::string component_name) {
    for(auto& node : this->nodes){
        if(node->get_component_name() == component_name){
            return node;
        }
    }

    return nullptr;
}

bool Entity::has_component(std::string component_name){
    for(auto& node : this->nodes){
        if(node->get_component_name() == component_name){
            return true;
        }
    }
    return false;
}
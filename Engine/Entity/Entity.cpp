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
}

void Entity::add_component(Node* node) {
    if(node == nullptr){
        return;
    }

    this->nodes.push_back(node);
}

void Entity::remove_component(Node* node) {
    if (node == nullptr) {
        return;
    }

    this->nodes.remove(node);
}

Node* Entity::get_component(std::string component_name) {
    for(auto* node : this->nodes){
        if(node->get_component_name() == component_name){
            return node;
        }
    }

    return nullptr;
}

bool Entity::has_component(std::string component_name){
    for(auto* node : this->nodes){
        if(node->get_component_name() == component_name){
            return true;
        }
    }
    return false;
}
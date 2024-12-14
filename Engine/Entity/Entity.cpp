#include "Engine/Entity/Entity.h"

Entity::Entity(){
    //
}

Entity::~Entity(){
    for(auto& node : this->nodes){
        delete node.second;
    }
    
    this->nodes.clear();
}

void Entity::add_component(std::string component_name, Node* node) {
    if(node == nullptr){
        return;
    }

    this->nodes[component_name] = node;
}

void Entity::remove_component(std::string component_name) {
    this->nodes.erase(component_name);
}

Node* Entity::get_component(std::string component_name) {
    return this->nodes[component_name];
}

bool Entity::has_component(std::string component_name){
    if(this->nodes.find(component_name) != this->nodes.end()){
        return true;
    }
    return false;
}
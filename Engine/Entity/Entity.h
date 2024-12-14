#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <map>
#include <string>
#include "Engine/Nodes/Node.h"

class Entity {
private:
    std::map<std::string, Node*> nodes;
public:
    Entity();
    ~Entity();
    
    Entity(const Entity& e) = delete;

    void add_component(std::string component_name, Node* node);
    void remove_component(std::string component_name);
    Node* get_component(std::string component_name);

    bool has_component(std::string component_name);
};

#endif
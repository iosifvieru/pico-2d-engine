#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include <string>
#include "Engine/Nodes/Node.h"
#include "pico/stdlib.h"

#define MAX_NO_ENTITIES 10000

class Entity {
private:
    std::vector<Node*> nodes;
public:
    Entity();
    ~Entity();
    
    Entity(const Entity& e) = delete;

    static uint16_t no_entities;

    void add_component(Node* node);
    void remove_component(std::string component_name);
    Node* get_component(std::string component_name);

    bool has_component(std::string component_name);

    virtual void update() = 0;
};


#endif
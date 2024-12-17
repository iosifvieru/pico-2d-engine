#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <list>
#include <string>
#include "Engine/Nodes/Node.h"
#include "pico/stdlib.h"

#define MAX_NO_ENTITIES 10000

class Entity {
private:
    /* components */
    std::list<Node*> nodes;

public:
    Entity();
    ~Entity();
    
    Entity(const Entity& e) = delete;

    /* static variable counting the entity number. */
    static uint16_t no_entities;

    /* adds a component to the entity */
    void add_component(Node* node);

    /* removes a component. */
    void remove_component(Node* node);

    /* returns a certain component. */
    Node* get_component(std::string component_name);

    /* returns true / false if the entity has a certain component. */
    bool has_component(std::string component_name);

    /* updates the entity */
    virtual void update() = 0;


};
#endif
#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <list>
#include <string>

#include "Engine/Components/Component.h"
#include "pico/stdlib.h"

#define MAX_NO_ENTITIES 10000

class Entity {
private:
    /* components */
    std::list<Component*> nodes;
public:

    Entity();
    ~Entity();

    Entity(const Entity& e) = delete;

    /* static variable counting the entity number. */
    static uint16_t no_entities;

    /* adds a component to the entity */
    void add_component(Component* node);

    /* removes a component. */
    void remove_component(Component* node);

    /* returns a certain component. */
    Component* get_component(std::string component_name);

    /* returns true / false if the entity has a certain component. */
    bool has_component(std::string component_name);

    /* updates the entity */
    virtual void update() = 0;
};
#endif
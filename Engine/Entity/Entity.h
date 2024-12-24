#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include <string>

#include "Engine/Components/Component.h"
#include "pico/stdlib.h"

#define MAX_NO_ENTITIES 10000

class Entity {
private:
    /* components */
    std::vector<Component*> components;

    bool flag = true;
public:

    Entity();
    ~Entity();

    Entity(const Entity& e) = delete;

    bool is_flagged() { return this->flag; }
    void set_flag(bool value) { 
        this->flag = value; 
        //printf("am setat pe %d", value);
    }
    
    /* static variable counting the entity number. */
    static uint16_t no_entities;

    /* adds a component to the entity */
    void add_component(Component* components);

    /* removes a component. */
    void remove_component(Component* components);

    /* returns a certain component. */
    Component* get_component(const char* component_name);

    /* returns true / false if the entity has a certain component. */
    bool has_component(std::string component_name);
};
#endif
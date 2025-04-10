#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include <string>

#include "Engine/Components/Component.h"
#include "pico/stdlib.h"

#define MAX_NO_ENTITIES 500

class Entity {
private:
    /* components */
    std::vector<Component*> components;

    /* entity flag - no usage for now. */
    bool flag = true;

    /* private constructor for "factory" approach */
    Entity();
public:
    ~Entity();
    Entity(const Entity& e) = delete;

    /* creates an entity - returns nullptr if the entity limit is exceeded. */
    static Entity* create();

    bool is_flagged() { return this->flag; }
    void set_flag(bool value) { this->flag = value; }
    
    /* static variable counting the entity number. */
    static uint16_t no_entities;

    /* adds a component to the entity */
    void add_component(Component* components);

    /* removes a component. */
    void remove_component(Component* components);

    /* returns the first occurance of the component you are looking for, otherwise returns nullptr. */
    const Component* get_component(const char* component_name);

    /* returns true / false if the entity has a certain component. */
    bool has_component(const char* component_name);
};
#endif
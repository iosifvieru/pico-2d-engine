#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <vector>
#include "Engine/Entity/Entity.h"
#include "Engine/Systems/System.h"

class Engine {
private:
    std::vector<System*> systems;
    std::vector<Entity*> entities;

public:
    Engine();
    ~Engine();

    Engine(const Engine& e) = delete;
    
    /* adds an entity to the list. */
    void add_entity(Entity* entity);
    void remove_entity(Entity* entity);

    /* adds a system to the list. */
    void add_system(System* system);
    void remove_system(System* system);

    void update();
};

#endif
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <vector>
#include "Engine/Entity/Entity.h"
#include "Engine/Systems/System.h"

class Engine {
private:
    std::vector<System*> systems;
    std::vector<Entity*> entities;
    std::vector<Entity*> deleted_entities;

    Engine();
    ~Engine();

    Engine(const Engine& e) = delete;

    static Engine* instance;

    void delete_entities();
    
public:
    static Engine& getInstance() {
        if(instance == nullptr){
            instance = new Engine();
        }

        return *instance;
    }
    
    void init(){
        this->systems.reserve(10);
        //this->entities.reserve(600);

    };

    /* adds an entity to the list. */
    void add_entity(Entity* entity);
    void remove_entity(Entity* entity);

    const std::vector<Entity*>& get_entities() const{
        return this->entities;
    }

    /* adds a system to the list. */
    void add_system(System* system);
    void remove_system(System* system);

    void update();

};

#endif
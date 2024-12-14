#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "Engine/Entity/Entity.h"
#include <vector>

/*  
    interface for system.
    has an update function.
*/
class System {
protected:
    std::vector<Entity*> entities;
public:
    virtual void update() = 0;
    virtual ~System() = default;

    void addEntity(Entity* entity){
        if(entity == nullptr){
            return;
        }
        
        this->entities.push_back(entity);
    }

    void removeEntity(Entity* entity){
        //
        ;
    }
};

#endif
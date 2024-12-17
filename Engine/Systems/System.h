#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "Engine/Entity/Entity.h"
#include <list>
#include <memory>

/*  
    interface for system.
    has an update function.
*/
class System {
public:
    virtual void update(std::list<Entity*> entities) = 0;
    virtual ~System() = default;
};

#endif
#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "Engine/Entity/Entity.h"
#include <vector>
#include <memory>

#define MAX_NO_SYSTEMS 50

/*  
    interface for system.
    has an update function.
*/
class System {
public:
    virtual void update(const std::vector<Entity*>& entities) = 0;
    virtual ~System() = default;
};

#endif
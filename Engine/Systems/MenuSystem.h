#ifndef _MENU_SYSTEM_H_
#define _MENU_SYSTEM_H_

#include "Engine/Systems/System.h"

class MenuSystem : public System {
private:
    Entity* arrow = nullptr;
public:
    int game_no = 0; 
    void update(const std::vector<Entity*>& entities) override;

    ~MenuSystem() {

    }
};

#endif
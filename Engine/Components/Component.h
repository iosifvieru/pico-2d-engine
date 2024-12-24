#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>
#include "Engine/Logger/Logger.h"

/*
in this file all the components will be defined for now.
*/

class Component {
private:
    /*
    variable that states the component is shared across multiple other components
    so it won't be automatically deleted.
    */
    bool shared = false;
public:
    virtual ~Component() = default;
    //virtual std::string get_component_name() = 0;
    virtual const char* get_component_name() = 0;

    void make_shared(bool value){
        this->shared = value;
    }

    bool is_shared() {
        return this->shared;
    }
};

#endif
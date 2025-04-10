#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>
#include "Engine/Logger/Logger.h"

/*
Component interface.
*/
class Component {
protected:
    /*
    variable that states the component is shared across multiple other components
    so the memory won't be freed when calling the destructor.
    */
    bool shared = false;
public:
    virtual ~Component() = default;

    /* returns the name of the component */
    virtual const char* get_component_name() const = 0;

    /* makes a component "shared" */
    void make_shared(bool value){ this->shared = value; }

    /* returns a bool with the shared-status of the component. */
    bool is_shared() { return this->shared; }
};

#endif
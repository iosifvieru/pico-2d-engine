#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <string>
#include "Engine/Logger/Logger.h"

/*
in this file all the components will be defined for now.
*/

class Component {
public:
    virtual ~Component() = default;
    virtual std::string get_component_name() = 0;
};

#endif
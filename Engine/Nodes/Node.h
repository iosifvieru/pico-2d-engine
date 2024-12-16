#ifndef _NODE_H_
#define _NODE_H_

#include <string>

class Node {
public:
    virtual ~Node() = default;

    virtual std::string get_component_name() = 0;
};

#endif
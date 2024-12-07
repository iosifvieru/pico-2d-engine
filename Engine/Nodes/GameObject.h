#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "Node.h"
#include <vector> 

class GameObject: public Node {
private:
    std::vector<Node*> nodes;
public:

    void update() override;
    void render(Canvas& canvas) override;
    
};

#endif

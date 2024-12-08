#ifndef _SCENE_NODE_H_
#define _SCENE_NODE_H_

#include "Node.h"

class SceneNode : public Node {
private:
    std::vector<Node*> nodes;

public:
    SceneNode();

    ~SceneNode();

    void add_node(Node* node);
    void remove_node(Node* node);

    void update() override;
    void render(Canvas& canvas) override;
};

#endif
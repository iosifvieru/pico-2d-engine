#ifndef _PLAYER_NODE_H_
#define _PLAYER_NODE_H_

#include "Engine/Nodes/InputNode.h"
#include "Engine/Nodes/SpriteNode.h"

class Player: public Node { 
private:
    Node* sprite;
    InputNode input;

public:
    Player(Node* sprite, InputNode input) : sprite(sprite), input(input), Node(0, 0) {

    };

    ~Player(){

    }

    void update() override {
        input.update();

        this->x = input.get_x();
        this->y = input.get_y();

        sprite->set_x(this->x);
        sprite->set_y(this->y);

        sprite->update();
    }

    void render(Canvas& canvas) override {
        sprite->render(canvas);
    }
};

#endif
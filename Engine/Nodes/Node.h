#ifndef _NODE_H_
#define _NODE_H_

#include "Engine/Canvas/Canvas.h"
#include <vector>

/*
this node represends the base class for all components in the engine.

a node can have different nodes

this node is an abstract class that will be implemented by different other components
*/
class Node {
protected:
    /* list of components shared across every implementation. */
    std::vector<Node*> nodes;

    /* positions */
    uint16_t x;
    uint16_t y;

    /* don't know if i should add the Z dimension so it's commented out for now.*/
    //uint16_t z;
    
public:
    /* constructor */
    Node(uint16_t x = 0, uint16_t y = 0) : x(x), y(y) {
        //

    };

    void add_node(Node* node){
        if(node == nullptr){
            return;
        }

        /* adds it to the nodes vector */
        nodes.push_back(node);
    }

    void remove_node(Node* node){
        if(node == nullptr){
            return;
        }

        /* should remove the node but not yet :) */
    }

    virtual void update() {
        for (Node* node : nodes) {
            if (node) {
                node->update();
            }
        }
    }

    virtual void render(Canvas& canvas) {
        for (Node* node : nodes) {
            if (node) {
                node->render(canvas);
            }
        }
    }
    
    virtual ~Node() {
        for (Node* node : nodes) {
            delete node;
        }
        nodes.clear();
    }

    void set_x(uint16_t x){
        this->x = x;
    }

    void set_y(uint16_t y){
        this->y = y;
    }

    uint16_t get_x(){
        return this->x;
    }

    uint16_t get_y(){
        return this->y;
    }
};

#endif

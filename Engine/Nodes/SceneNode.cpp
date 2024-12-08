#include "Engine/Nodes/SceneNode.h"

/* basic constructor - no arguments*/
SceneNode::SceneNode() : Node(0, 0){

}

/* destructor */
SceneNode::~SceneNode(){
    for (Node* node : this->nodes) {
        if(node != nullptr){
            delete node;
        }
    }
    nodes.clear();
}

/* adds a node in the Scene */
void SceneNode::add_node(Node* node){
    if(node == nullptr){
        return;
    }

    /* adds it to the nodes vector */
    nodes.push_back(node);
}

/* removes a node from the Scene */
void SceneNode::remove_node(Node* node) {
    if(node == nullptr){
        return;
    }

    /* should remove the node but not yet :) */
    //
}

/* updates every node from the node vector */
void SceneNode::update() {
    for (Node* node : this->nodes) {
        if (node) {
            node->update();
        }
    }
}

/* renders every node from the node vector */
void SceneNode::render(Canvas& canvas) {
    for (Node* node : this->nodes) {
        if (node) {
            node->render(canvas);
        }
    }
}
#ifndef _TAG_COMPONENT_H_
#define _TAG_COMPONENT_H_

#include "Engine/Components/Component.h"

enum TAG {
    ENTITY,
    PLAYER,
    ENEMY,
    PROJECTILE
};

class TagComponent : public Component {
public:

    TAG tag = TAG::ENTITY;

    TagComponent() {};
    ~TagComponent() = default;

    TagComponent(TAG tag){
        this->tag = tag;
    }

    TagComponent operator=(const TagComponent& other){
        this->tag = other.tag;
        return *this;
    }

    TagComponent(const TagComponent& other){
        this->tag = other.tag;
    }

    
    const char* get_component_name() const {
        return "TagComponent";
    };
};


#endif
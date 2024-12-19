#ifndef _SPRITE_COMPONENT_H_
#define _SPRITE_COMPONENT_H_

#include "Engine/Components/Component.h"

class SpriteComponent : public Component {
public:
    uint8_t width = 0;
    uint8_t height = 0;
    uint16_t* sprite = nullptr;

    SpriteComponent(){
        this->width = 0;
        this->height = 0;
        this->sprite = nullptr;
    };

    SpriteComponent(uint8_t width, uint8_t height, uint16_t* sprite){
        if(sprite == nullptr){ return; }

        this->width = width;
        this->height = height;
        this->sprite = new uint16_t[this->width*this->height];

        for(int i = 0; i < this->width*this->height; i++){
            this->sprite[i] = sprite[i];
        }
        
        Logger::log("SpriteComponent()");
    }

    SpriteComponent operator=(const SpriteComponent& other){
        if(this == &other) return *this;

        delete[] sprite;

        this->width = other.width;
        this->height = other.height;

        if(other.sprite){
            this->sprite = new uint16_t[this->width*this->height];

            for(int i = 0; i < this->width*this->height; i++){
                this->sprite[i] = sprite[i];
            }
        } else {
            this->sprite = nullptr;
        }

        return *this;
    }

    ~SpriteComponent(){
        // safely delete sprite.
        if(sprite != nullptr){
            delete[] sprite;
        }
        Logger::log("~SpriteComponent()");
    }

    std::string get_component_name() {
        return "SpriteComponent";
    }
};

#endif
#ifndef _SPRITE_COMPONENT_H_
#define _SPRITE_COMPONENT_H_

#include "Engine/Components/Component.h"

class SpriteComponent : public Component {
public:
    uint8_t width = 0;
    uint8_t height = 0;
    
    /* for non shared sprite */
    uint16_t *sprite = nullptr;

    /* for shared sprite */
    const uint16_t* shared_sprite = nullptr;

    SpriteComponent(){
        this->width = 0;
        this->height = 0;
        this->sprite = nullptr;
    };
    
    SpriteComponent(uint8_t width, uint8_t height, const uint16_t* sprite, bool shared){
        if(sprite == nullptr){ return; }

        this->width = width;
        this->height = height;
        this->shared = shared;

        if(this->shared == true){
            this->shared_sprite = sprite;
        } else {
            this->sprite = new uint16_t[this->width * this->height];
            for(int i = 0; i < this->width * this->height; i++) {
                this->sprite[i] = sprite[i];
            }
        }

        Logger::log("SpriteComponent()");
    }

    /* warning: you are about to create a shared sprite component. */
    SpriteComponent(uint8_t width, uint8_t height, const uint16_t* sprite) : SpriteComponent(width, height, sprite, true){}

    SpriteComponent operator=(const SpriteComponent& other){
        if(this == &other) return *this;

        if(this->shared == false){
            delete[] this->sprite;
        }

        this->width = other.width;
        this->height = other.height;

        /* perform a deep copy. */
        if(other.sprite != nullptr){
            for(int i = 0; i < this->width * this->height; i++){
                this->sprite[i] = other.sprite[i];
            }          
        } else {
            this->sprite = nullptr;
        }

        this->shared_sprite = other.shared_sprite;
        return *this;
    }

    ~SpriteComponent(){
        // safely delete sprite.
        if(this->shared == false && this->sprite != nullptr){
            delete[] this->sprite;
        }

        Logger::log("~SpriteComponent()");
    }

    const uint16_t* get_sprite(){
        if(this->shared_sprite != nullptr){
            return this->shared_sprite;
        }

        if(this->sprite != nullptr){
            return this->sprite;
        }

        return nullptr;
    }
    
    void set_sprite(const uint16_t* sprite){
        this->shared_sprite = sprite;
    }

    const char* get_component_name() const {
        return "SpriteComponent";
    }
};

#endif
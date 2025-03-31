#ifndef _TEXT_COMPONENT_H_
#define _TEXT_COMPONENT_H_

#include "Engine/Components/Component.h"
#include "Engine/TextureManager.h"
#include "Engine/Font.h"

class TextComponent : public Component {
public:
    std::string text;
    int x, y;        
        
    static TextureManager tm;

    TextComponent(int x, int y, std::string text): x(x), y(y), text(text){
            //
    }
        
    const char* get_component_name() {
        return "TextComponent";
    };
};

#endif
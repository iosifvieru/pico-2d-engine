#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

#include <cstdint>

class TextureManager {
private:
    const uint16_t* spritesheet;
    uint16_t tile_width, tile_height;
    uint16_t columns, rows;

public:
    TextureManager(const uint16_t* spritesheet, 
                uint16_t spritesheet_width, uint16_t spritesheet_height, 
                uint16_t tile_width, uint16_t tile_height);

    const uint16_t* get_tile(uint16_t index, bool flipped = false);
};

#endif
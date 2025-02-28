
#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

class TextureManager {
private:
    const uint16_t* spritesheet;
    uint8_t tile_width, tile_height;
    uint8_t columns, rows;

public:
    TextureManager(const uint16_t* spritesheet, 
                uint8_t spritesheet_width, uint8_t spritesheet_height, 
                uint8_t tile_width, uint8_t tile_height){
        
        this->spritesheet = spritesheet;
        this->tile_height = tile_height;
        this->tile_width = tile_width;
        this->columns = spritesheet_width / tile_width;
        this->rows = spritesheet_height / tile_height;
    }

    const uint16_t* get_tile(uint8_t index, bool flipped = false) {
        if (index >= columns * rows) {
            return nullptr;
        }

        uint8_t tile_x = index % columns;
        uint8_t tile_y = index / columns;

        uint16_t start_x = tile_x * tile_width;
        uint16_t start_y = tile_y * tile_height;

        uint16_t* tile = new uint16_t[tile_width * tile_height];

        for (int y = 0; y < tile_height; ++y) {
            for (int x = 0; x < tile_width; ++x) {
                int image_index = (start_y + y) * this->columns * this->tile_width + (start_x + x);
                int tile_index = y * tile_width + (flipped ? (tile_width - 1 - x) : x);
                tile[tile_index] = spritesheet[image_index];
            }
        }

        return tile;
    }
};

#endif
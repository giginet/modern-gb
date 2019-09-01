#include <gb/gb.h>
#include "sprite.h"

void move(Sprite* sprite, int dx, int dy) {
    int _x, _y;
    int _i;
    int width, height;

    width = sprite->width;
    height = sprite->height;

    for (_x = 0; _x < width; ++_x) {
        for (_y = 0; _y < height; ++_y) {
            _i = _y * width + _x;
            set_sprite_tile(_i, _i);
            move_sprite(_i, sprite->x + dx + _x * 8, sprite->y + dy + _y * 8);
        }
    }
    sprite->x = sprite->x + dx;
    sprite->y = sprite->y + dy;
}

void register_sprite(Sprite *sprite, int tile_offset) {
    int width = sprite->width;
    int height = sprite->height;
    set_sprite_data(tile_offset, width * height, sprite->pixels);
}

void render_sprite(Sprite *sprite, int tile_offset, int slot) {
    UBYTE _x, _y;
    int tile_index;

    UBYTE _w = sprite->width;
    UBYTE _h = sprite->height;
    for (_x = 0; _x < _w; ++_x) {
        for (_y = 0; _y < _h; ++_y) {
            tile_index = _y * _w + _x;
            set_sprite_tile(slot + tile_index, tile_offset + tile_index);
            move_sprite(slot + tile_index, sprite->x + _x * 8, sprite->y + _y * 8);
        }
    }
}


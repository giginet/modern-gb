#include <gb/gb.h>
#include "sprite.h"

void move(Sprite* sprite, int dx, int dy) {
    int _x, _y;
    int _i;
    int width, height;

    width = sprite->tile->horizontal_count;
    height = sprite->tile->vertical_count;

    for (_x = 0; _x < width; ++_x) {
        for (_y = 0; _y < height; ++_y) {
            _i = _y * width + _x;
            move_sprite(sprite->slot + _i, sprite->x + _x * 8, sprite->y + _y * 8);
        }
    }
    sprite->x = sprite->x + dx;
    sprite->y = sprite->y + dy;
}

void register_tile(TileSet *tile) {
    UBYTE width = tile->horizontal_count;
    UBYTE height = tile->vertical_count;
    set_sprite_data(tile->start_index, width * height, tile->pixels);
}

void render_sprite(Sprite *sprite) {
    UBYTE _x, _y;
    UBYTE tile_index;

    UBYTE _w = sprite->tile->horizontal_count;
    UBYTE _h = sprite->tile->vertical_count;
    for (_x = 0; _x < _w; ++_x) {
        for (_y = 0; _y < _h; ++_y) {
            tile_index = _y * _w + _x;
            set_sprite_tile(sprite->slot + tile_index, sprite->tile->start_index + tile_index);
            move_sprite(sprite->slot + tile_index, sprite->x + _x * 8, sprite->y + _y * 8);
        }
    }
}


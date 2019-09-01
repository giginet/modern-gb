#ifndef SPRITE_H
#define SPRITE_H

typedef struct {
    UBYTE horizontal_count;
    UBYTE vertical_count;
    UBYTE start_index;
    unsigned char *pixels;
} TileSet;

typedef struct {
    UBYTE x;
    int y;
    UBYTE slot;
    TileSet *tile;
} Sprite;

#endif

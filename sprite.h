#ifndef SPRITE_H
#define SPRITE_H

typedef struct {
    UBYTE x;
    UBYTE y;
    UBYTE width;
    UBYTE height;
    UBYTE dx;
    UBYTE dy;
    unsigned char *pixels;
} Sprite;

#endif

#ifndef Sprite
#define Sprite

typedef struct _Sprite {
  UBYTE x;
  UBYTE y;
  UBYTE width;
  UBYTE height;
  unsigned char *pixels;
} Sprite;

#endif

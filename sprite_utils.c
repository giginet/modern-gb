#include <gb/gb.h>

void move(struct Sprite* sprite, int dx, int dy) {
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

void render_sprite(struct Sprite *sprite) {
  int _x, _y;
  int index;

  int width = sprite->width;
  int height = sprite->height;
  set_sprite_data(0, width * 8, sprite->pixels);
  for (_x = 0; _x < width; ++_x) {
    for (_y = 0; _y < height; ++_y) {
      index = _y * width + _x;
      set_sprite_tile(index, index);
      move_sprite(index, sprite->x + _x * 8, sprite->y + _y * 8);
    }
  }
}


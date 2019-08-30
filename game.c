#include <stdio.h>
#include <gb/gb.h>
/* #include "sprite.c" */
#include "pixels.h"
/* #include "sprite_utils.c" */

struct Sprite {
  UBYTE x;
  UBYTE y;
  UBYTE width;
  UBYTE height;
  unsigned char *pixels;
};

void move(struct Sprite *s, int dx, int dy);

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

int main() {
  struct Sprite player;
  player.pixels = player_pixels;
  player.x = 0;
  player.y = 0;
  player.width = 3;
  player.height = 3;

  SPRITES_8x8;

  render_sprite(&player);
  SHOW_SPRITES;

  while(1) {
    if(joypad() & J_RIGHT) {
      move(&player, 1, 0);
    }
    if(joypad() & J_LEFT) {
      move(&player, -1, 0);
    }
    if(joypad() & J_UP) {
      move(&player, 0, -1);
    }
    if(joypad() & J_DOWN) {
      move(&player, 0, 1);
    }
    delay(10);
  }
  return 0;
}

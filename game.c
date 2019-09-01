#include <stdio.h>
#include <gb/gb.h>
#include "sprite.h"
#include "pixels.h"
#include "sprite_utils.c"
#include "bullet.c"

TileSet player_tile;
TileSet bullet_tile;

Sprite bullet;
Sprite bullet2;
Sprite player;

/* struct Sprite *bullets[]; */

void initialize_tile(
        TileSet *tile_set,
        UBYTE vc, 
        UBYTE hc, 
        UBYTE start_index, 
        unsigned char *pixels) {
    tile_set->vertical_count = vc;
    tile_set->horizontal_count = hc;
    tile_set->start_index = start_index;
    tile_set->pixels = pixels;
}

void initialize_tiles() {
    /* initialize_tile(&player_tile, 3, 3, 0, player_pixels); */
    /* initialize_tile(&bullet_tile, 1, 1, 10, bullet_pixels); */
    player_tile.horizontal_count = 3;
    player_tile.vertical_count = 3;
    player_tile.start_index = 0;
    player_tile.pixels = player_pixels;

    bullet_tile.horizontal_count = 1;
    bullet_tile.vertical_count = 1;
    bullet_tile.start_index = 10;
    bullet_tile.pixels = bullet_pixels;

    register_tile(&player_tile);
    register_tile(&bullet_tile);
}

int main() {
    initialize_tiles();

    player.x = 30;
    player.y = 30;
    player.slot = 0;
    player.tile = &player_tile;

    bullet.x = 70;
    bullet.y = 70;
    bullet.slot = 10;
    bullet.tile = &bullet_tile;

    bullet2.tile = &bullet_tile;
    bullet2.x = 100;
    bullet2.y = 100;
    bullet2.slot = 11;

    SPRITES_8x8;

    render_sprite(&player);
    render_sprite(&bullet);
    render_sprite(&bullet2);

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

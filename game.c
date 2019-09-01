#include <stdio.h>
#include <gb/gb.h>
#include "sprite.h"
#include "pixels.h"
#include "sprite_utils.c"
#include "bullet.c"

TileSet player_tile;
TileSet bullet_tile;

// TODO shoot multiple bullets
Sprite bullets[1];
UBYTE bullet_count = 0;
Sprite player;

UBYTE bullet_index;

/*
 * Slot
 * 0 ~ 8 Player
 * 9, 10, 11, 12 Player Bullet
 */

/* struct Sprite *bullets[]; */

void initialize_tiles() {
    player_tile.horizontal_count = 3;
    player_tile.vertical_count = 3;
    player_tile.start_index = 0;
    player_tile.pixels = player_pixels;

    bullet_tile.horizontal_count = 1;
    bullet_tile.vertical_count = 1;
    bullet_tile.start_index = 9;
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

    SPRITES_8x8;

    render_sprite(&player);

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
        if(joypad() & J_A) {
            if (bullet_count < 1) {
                bullets[bullet_count].tile = &bullet_tile;
                bullets[bullet_count].x = player.x + 8;
                bullets[bullet_count].y = player.y;
                bullets[bullet_count].slot = 9 + bullet_count;
                render_sprite(&bullets[bullet_count]);
                ++bullet_count;
            }
        }
        for (bullet_index = 0; bullet_index < bullet_count; ++bullet_index) {
            if (bullets[bullet_index].y > -10) {
                move(&bullets[bullet_index], 0, -5); 
            } else {
                --bullet_count;
            }
        }
        
        delay(10);
        SHOW_SPRITES;
    }
    return 0;
}

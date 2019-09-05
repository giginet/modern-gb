#include <stdio.h>
#include <gb/gb.h>
#include "sprite.h"
#include "pixels.h"
#include "sprite_utils.c"
#include "bullet.c"
#include "bg.h"

TileSet player_tile;
TileSet bullet_tile;
TileSet enemy_tile;

// TODO shoot multiple bullets
Sprite bullets[1];
UBYTE bullet_count = 0;
Sprite player;
Sprite enemy;

UBYTE bullet_index;

/*
 * Slot
 * 0 ~ 8 Player
 * 9, 10, 11, 12 Player Bullet
 * 13 ~ 28 enemy
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

    enemy_tile.horizontal_count = 4;
    enemy_tile.vertical_count = 4;
    enemy_tile.start_index = 10;
    enemy_tile.pixels = enemy_pixels;

    register_tile(&player_tile);
    register_tile(&bullet_tile);
    register_tile(&enemy_tile);
}


void load_background() {
    set_bkg_data(0, 2, bg_tile_data);
    set_bkg_tiles(0, 0, 20, 18, bg_map_data); 
}

int hit_test(int origin_x, int origin_y, int width, int height, int px, int py) {
    if ((origin_x < px) 
            && (px < origin_x + width) 
            && (origin_y < py) 
            && (py < origin_y + height)) {
        return 1;
    }
    return 0;
}

int main() {
    initialize_tiles();

    player.x = 80;
    player.y = 100;
    player.slot = 0;
    player.tile = &player_tile;

    enemy.x = 80;
    enemy.y = 0;
    enemy.slot = 13;
    enemy.tile = &enemy_tile;

    load_background();

    SPRITES_8x8;

    render_sprite(&player);
    render_sprite(&enemy);

    while(1) {
        if(joypad() & J_RIGHT) {
            move_by(&player, 3, 0);
        }
        if(joypad() & J_LEFT) {
            move_by(&player, -3, 0);
        }
        if(joypad() & J_UP) {
            move_by(&player, 0, -3);
        }
        if(joypad() & J_DOWN) {
            move_by(&player, 0, 3);
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
    
        if (enemy.y < 40) {
            move_by(&enemy, 0, 4);
        } else {
            move_to(&enemy, (enemy.x + 3) % 180, enemy.y);
        }

        for (bullet_index = 0; bullet_index < bullet_count; ++bullet_index) {
            if (bullets[bullet_index].y > -10) {
                move_by(&bullets[bullet_index], 0, -5); 
            } else {
                --bullet_count;
            }
            if(hit_test(enemy.x, 
                        enemy.y, 
                        30, 
                        30, 
                        bullets[bullet_index].x, 
                        bullets[bullet_index].y) == 1) {
                move_to(&bullets[bullet_index], 0, -20); 
                move_to(&enemy, (enemy.x + 20) % 150, -20);
            }
        }
        
        delay(10);
        SHOW_SPRITES;
        SHOW_BKG;
    }
    return 0;
}

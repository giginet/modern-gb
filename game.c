#include <stdio.h>
#include <gb/gb.h>
#include "sprite.c"
#include "pixels.h"
#include "sprite_utils.c"
#include "bullet.c"

Sprite bullet;
Sprite player;
/* struct Sprite *bullets[]; */

int main() {

    /* set_sprite_data(0, 2, all_bullet_pixels); */

    player.pixels = bullet_pixels;
    player.x = 30;
    player.y = 30;
    player.width = 1;
    player.height = 1;

    bullet.pixels = bullet_pixels;
    bullet.x = 70;
    bullet.y = 70;
    bullet.width = 1;
    bullet.height = 1;

    register_sprite(&player, 0);
    register_sprite(&bullet, 1);

    SPRITES_8x8;

    render_sprite(&player, 0, 0);
    render_sprite(&bullet, 1, 1);
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

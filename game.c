#include <stdio.h>
#include <gb/gb.h>
#include "sprite.h"
#include "pixels.h"
#include "sprite_utils.c"
#include "bullet.c"

Sprite bullet;
Sprite bullet2;
Sprite player;
/* struct Sprite *bullets[]; */

int main() {
    player.pixels = player_pixels;
    player.x = 30;
    player.y = 30;
    player.width = 3;
    player.height = 3;

    bullet.pixels = bullet_pixels;
    bullet.x = 70;
    bullet.y = 70;
    bullet.width = 1;
    bullet.height = 1;

    bullet2.pixels = bullet_pixels;
    bullet2.x = 100;
    bullet2.y = 100;
    bullet2.width = 1;
    bullet2.height = 1;

    register_sprite(&player, 0);
    register_sprite(&bullet, 10);

    SPRITES_8x8;

    render_sprite(&player, 0, 0);
    render_sprite(&bullet, 10, 10);
    render_sprite(&bullet2, 10, 11);
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

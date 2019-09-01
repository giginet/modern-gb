#include <stdio.h>
#include <gb/gb.h>
#include "sprite.c"
#include "pixels.h"
#include "sprite_utils.c"
#include "bullet.c"

int main() {
    struct Sprite *bullets[];
    struct Sprite bullet;
    struct Sprite player;

    player.pixels = player_pixels;
    player.x = 0;
    player.y = 0;
    player.width = 3;
    player.height = 3;

    SPRITES_8x8;

    render_sprite(&player);

    bullet.x = 30;
    bullet.y = 30;
    createBullet(&bullet);
    /* render_sprite(&bullet); */
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

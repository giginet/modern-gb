#include <stdio.h>
#include <gb/gb.h>

// class Color
// {
// public:
//     UInt08 r;
//     UInt08 g;
//     UInt08 b;
//     
//     Color()
//     {
//         r = g = b = 0;
//     }
//
//     Color(UInt08 n)
//     {
//         r = g = b = n;
//     }
//
//     Color(UInt08 r0, UInt08 g0, UInt08 b0)
//     {
//         r = r0;
//         g = g0;
//         b = b0;
//     }
// };

// Sprite::Sprite(): _x(0), _y(0) {
// }

int main() {
    UINT8 joypad_result;

    /* auto color = new Color(); */

    while(1) {
        joypad_result = joypad();

        if (joypad_result & J_START) {
            printf("PUSH START\n");
        }
        if (joypad_result & J_SELECT) {
            printf("PUSH SELECT\n");
        }
        if (joypad_result & J_B) {
            printf("PUSH B\n");
        }
        if (joypad_result & J_A) {
            printf("PUSH A\n");
        }
        if (joypad_result & J_DOWN) {
            printf("PUSH DOWN\n");
        }
        if (joypad_result & J_UP) {
            printf("PUSH UP\n");
        }
        if (joypad_result & J_LEFT) {
            printf("PUSH LEFT\n");
        }
        if (joypad_result & J_RIGHT) {
            printf("PUSH RIGHT\n");
        }
    }
    return 0;
}

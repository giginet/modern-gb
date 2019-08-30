#include <stdio.h>
#include <gb/gb.h>

void main() {
    UINT8 joypad_result;

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
}

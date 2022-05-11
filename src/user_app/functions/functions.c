#include "functions.h"

/********************************************************************************
 * Sets the state for all LEDs
 ********************************************************************************/
void led_toggle_all(uint8_t state) {
    for(int i = 0; i <= ROWS; i++) {
        for(int j = 0; j <= LINES; j++) {
            setPixel(i, j, state);
        }
    }
} 
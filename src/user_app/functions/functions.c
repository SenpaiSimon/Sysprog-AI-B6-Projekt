#include "functions.h"

/********************************************************************************
 * Sets the state for all LEDs
 ********************************************************************************/
void led_set_all(uint8_t state) {
    for(int i = 0; i <= DIMENSIONS.rows; i++) {
        for(int j = 0; j <= DIMENSIONS.lines; j++) {
            setPixel(i, j, state);
        }
    }
} 
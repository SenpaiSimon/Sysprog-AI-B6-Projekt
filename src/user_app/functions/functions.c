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

/********************************************************************************
 * Sets the state for all LEDs in one Row
 ********************************************************************************/
void led_set_row(uint8_t row, uint8_t set) {
    for(int i = 1; i <= DIMENSIONS.rows; i++) {
        setPixel(row, i, set);
    }
}

/********************************************************************************
 * Sets the state for all LEDs in one Line
 ********************************************************************************/
void led_set_line(uint8_t line, uint8_t set) {
    for(int i = 1; i <= DIMENSIONS.lines; i++) {
        setPixel(line, i, set);
    }
}

/********************************************************************************
 * Sweep through the matrix side by side
 ********************************************************************************/
void led_snake(int speed) {
    led_set_all(0);

    for(int i = 1; i <= DIMENSIONS.lines; i+=2) {
        // move right
        for(int j = 1; j <= DIMENSIONS.rows; j++) {
            setPixel(j, i, 1);
            usleep(speed*1000);
            setPixel(j, i, 0);
        }
        // move back left
        for(int j = DIMENSIONS.rows; j >= 1; j--) {
            setPixel(j, i+1, 1);
            usleep(speed*1000);
            setPixel(j, i+1, 0);
        }
    }
}
#ifndef __MATRIX_CONTROLLER__
#define __MATRIX_CONTROLLER__

/********************************************************************************
 * Includes from external Librarys
 ********************************************************************************/

/********************************************************************************
 * Includes from internal Librarys
 ********************************************************************************/
#include "../gpio_inits/gpio_init.h"

/********************************************************************************
 * Functions
 ********************************************************************************/

/********************************************************************************
 * Sets the state of a pixel | 1 = on 0 = off
 ********************************************************************************/
static void setPixel(int row, int line, int state) {
    if(row > ROWS && row <= 0) {
        printk(KERN_ERR "Row: %d out of range", row);
        return;
    } else if (line > LINES && line <= 0) {
        printk(KERN_ERR "Line: %d out of range", line);
        return;
    }

    gpio_set_value(hPin_arr[row - 1], state);
    gpio_set_value(lPin_arr[line - 1], state);
}

/********************************************************************************
 * Returns the state of a pixel | 1 = on 0 = off
 ********************************************************************************/
static uint8_t getPixelState(uint8_t row, uint8_t line) {
    if(row > ROWS && row <= 0) {
        printk(KERN_ERR "Row: %d out of range", row);
        return 2;
    } else if (line > LINES && line <= 0) {
        printk(KERN_ERR "Line: %d out of range", line);
        return 2;
    }

    return gpio_get_value(hPin_arr[row - 1]) && gpio_get_value(lPin_arr[line - 1]);
}   

#endif
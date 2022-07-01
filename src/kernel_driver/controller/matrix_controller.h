#ifndef __MATRIX_CONTROLLER__
#define __MATRIX_CONTROLLER__

/********************************************************************************
 * Includes from external Librarys
 ********************************************************************************/

/********************************************************************************
 * Includes from internal Librarys
 ********************************************************************************/
#include "../gpio_inits/gpio_init.h"
#include "../ioct_cmd.h"

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
    gpio_set_value(lPin_arr[line - 1], !state);
}

/********************************************************************************
 * Returns the state of a pixel | 1 = on 0 = off
 ********************************************************************************/
static int getPixelState(int row, int line) {
    if(row > ROWS && row <= 0) {
        printk(KERN_ERR "Row: %d out of range\n", row);
        return 2;
    } else if (line > LINES && line <= 0) {
        printk(KERN_ERR "Line: %d out of range\n", line);
        return 2;
    }

    return gpio_get_value(hPin_arr[row - 1]) && !gpio_get_value(lPin_arr[line - 1]);
}  

/********************************************************************************
 * Draw all pixels which are set in the given array
 ********************************************************************************/
static void drawAllPixels(int drawMatrix[ROWS][LINES]) {
    // draw everything
    for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < LINES; j++) {
            // toggle whole lines
			setPixel(i + 1, j + 1, drawMatrix[i][j]);
			// setPixel(i + 1, j + 1, 1);
		}
        for(int j = 0; j < LINES; j++) {
            // toggle whole lines
			setPixel(i + 1, j + 1, 0);
		}
	}
}

#endif
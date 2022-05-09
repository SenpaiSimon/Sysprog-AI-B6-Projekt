#ifndef __GPIO_INIT_H__
#define __GPIO_INIT_H__

/********************************************************************************
 * Includes from external Librarys
 ********************************************************************************/
#include <linux/kern_levels.h>
#include <linux/gpio.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <stdbool.h>

/********************************************************************************
 * Includes from internal Librarys
 ********************************************************************************/
#include "gpio_pins.h"

/********************************************************************************
 * Functions
 ********************************************************************************/

/********************************************************************************
 * Inits all the needed GPIO pins for the Matrix
 * The steps which are followed for each pin are
 * 1. Check if the GPIO is valid
 * 2. Request the GPIO 
 * 3. Set the direction of the GPIO to output and state when effective
 * 4. Export the GPIO with no direction change
 ********************************************************************************/
static void init_all_gpios(void) {
    // Active HIGH Drivers
    for(int i = 0; i < ROWS; i++) {
        if(!gpio_is_valid(hPin_arr[i])) {
            printk(KERN_ERR "Err, Pin No %d not valid!\r\n", hPin_arr[i]);
            return;
        } else {
            if(gpio_request(hPin_arr[i], hPin_arr_names[i])) {
                printk(KERN_ERR "Err, Pin No %d request failed!\r\n", hPin_arr[i]);
                return;
            } else {
                if(gpio_direction_output(hPin_arr[i], 1)) {
                    printk(KERN_ERR "Err, Pin No %d set direction failed!\r\n", hPin_arr[i]);
                    return;
                } else {
                    if(gpio_export(hPin_arr[i], false)) {
                        printk(KERN_ERR "Err, Pin No %d export failed!\r\n", hPin_arr[i]);
                        return;
                    }
                }
            }
        }
    }

    // Active LOW Driver
    for(int i = 0; i < LINES; i++) {
        if(!gpio_is_valid(lPin_arr[i])) {
            printk(KERN_ERR "Err, Pin No %d not valid!\r\n", lPin_arr[i]);
            return;
        } else {
            if(gpio_request(lPin_arr[i], lPin_arr_names[i])) {
                printk(KERN_ERR "Err, Pin No %d request failed!\r\n", lPin_arr[i]);
                return;;
            } else {
                if(gpio_direction_output(lPin_arr[i], 0)) {
                    printk(KERN_ERR "Err, Pin No %d set direction failed!\r\n", lPin_arr[i]);
                    return;
                } else {
                    if(gpio_export(lPin_arr[i], false)) {
                        printk(KERN_ERR "Err, Pin No %d export failed!\r\n", lPin_arr[i]);
                        return;
                    }
                }
            }
        }
    }

    printk(KERN_INFO "Init done");
}

/********************************************************************************
 * Unexports and frees all the GPIO which where used before
 ********************************************************************************/
static void exit_all_gpios(void) {
    for(int i = 0; i < ROWS; i++) {
        gpio_unexport(hPin_arr[i]);
        gpio_free(hPin_arr[i]);
    }

    for(int i = 0; i < LINES; i++) {
        gpio_unexport(lPin_arr[i]);
        gpio_free(lPin_arr[i]);
    }
}

#endif
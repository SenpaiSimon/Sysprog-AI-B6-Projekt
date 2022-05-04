#include "gpio_init.h"

// TODO is rows right? for these?
int hPin_arr[ROWS] = {H_GPIO_1, H_GPIO_2, H_GPIO_3, H_GPIO_4, H_GPIO_5, H_GPIO_6};
char hPin_arr_names[ROWS][10] = {"H_GPIO_1", "H_GPIO_2", "H_GPIO_3", "H_GPIO_4", "H_GPIO_5", "H_GPIO_6"};
int lPin_arr[LINES] = {L_GPIO_1, L_GPIO_2, L_GPIO_3, L_GPIO_4, L_GPIO_5, L_GPIO_6};
char lPin_arr_names[LINES][10] = {"L_GPIO_1", "L_GPIO_2", "L_GPIO_3", "L_GPIO_4", "L_GPIO_5", "L_GPIO_6"};

static void init_all_gpios(void) {
    // HIGH Drivers
    for(int i = 0; i < ROWS; i++) {
        if(!gpio_is_valid(hPin_arr[i])) {
            printk("Err, Pin No %d not valid!\r\n", hPin_arr[i]);
            break;
        } else {
            if(gpio_request(hPin_arr[i], hPin_arr_names[i])) {
                printk("Err, Pin No %d request failed!\r\n", hPin_arr[i]);
                break;
            } else {
                if(gpio_direction_output(hPin_arr[i], 0)) {
                    printk("Err, Pin No %d set direction failed!\r\n", hPin_arr[i]);
                    break;
                } else {
                    if(gpio_export(hPin_arr[i], false)) {
                        printk("Err, Pin No %d export failed!\r\n", hPin_arr[i]);
                        break;
                    }
                }
            }
        }
    }

    // LOW Drivers
    for(int i = 0; i < LINES; i++) {
        if(!gpio_is_valid(lPin_arr[i])) {
            printk("Err, Pin No %d not valid!\r\n", lPin_arr[i]);
            break;
        } else {
            if(gpio_request(lPin_arr[i], lPin_arr_names[i])) {
                printk("Err, Pin No %d request failed!\r\n", lPin_arr[i]);
                break;
            } else {
                if(gpio_direction_output(lPin_arr[i], 1)) {
                    printk("Err, Pin No %d set direction failed!\r\n", lPin_arr[i]);
                    break;
                } else {
                    if(gpio_export(lPin_arr[i], false)) {
                        printk("Err, Pin No %d export failed!\r\n", lPin_arr[i]);
                        break;
                    }
                }
            }
        }
    }
}

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
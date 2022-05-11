#ifndef __FUNCTIONS__
#define __FUNCTIONS__

/********************************************************************************
 * Includes from external Librarys
 ********************************************************************************/
#include <stdint.h>

/********************************************************************************
 * Includes from internal Librarys
 ********************************************************************************/
#include "../led_controller/controller.h"
#include "../../kernel_driver/gpio_inits/gpio_pins.h"

/********************************************************************************
 * External Global Variables
 ********************************************************************************/
extern dimensions_t DIMENSIONS;

/********************************************************************************
 * Function Prototypes
 ********************************************************************************/
void led_set_all(uint8_t state);

#endif
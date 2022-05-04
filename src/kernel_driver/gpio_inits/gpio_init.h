#ifndef GPIO_INIT_H
#define GPIO_INIT_H

/********************************************************************************
 * Includes from external Librarys
 ********************************************************************************/
#include <kern_levels.h>

/********************************************************************************
 * Includes from internal Librarys
 ********************************************************************************/
#include "gpio_pins.h"
#include "stdbool.h"

/********************************************************************************
 * Function Prototypes
 ********************************************************************************/
static void init_all_gpios(void);
static void exit_all_gpios(void);

#endif
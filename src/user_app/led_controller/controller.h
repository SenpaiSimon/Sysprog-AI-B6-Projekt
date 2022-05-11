#ifndef __CONTROLLER__
#define __CONTROLLER__

/********************************************************************************
 * Includes from external Librarys
 ********************************************************************************/
#include <stdint.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/********************************************************************************
 * Includes from internal Librarys
 ********************************************************************************/
#include "../../kernel_driver/ioct_cmd.h"

/********************************************************************************
 * Function Prototypes
 ********************************************************************************/
void setPixel(uint8_t row, uint8_t line, uint8_t state);
uint8_t getPixelState(uint8_t row, uint8_t line);

#endif
#ifndef __APP_H__
#define __APP_H__

/********************************************************************************
 * Includes from external Librarys
 ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

/********************************************************************************
 * Includes from internal Librarys
 ********************************************************************************/
#include "../kernel_driver/ioct_cmd.h"
#include "./led_controller/controller.h"
#include "./functions/functions.h"

/********************************************************************************
 * Function Prototypes
 ********************************************************************************/
int readNumber(char *input);

#endif
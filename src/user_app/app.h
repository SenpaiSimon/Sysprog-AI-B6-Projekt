#ifndef APP_H
#define APP_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

// Defines
#define CMD_1 _IOW('a', 'a', int32_t)
#define CMD_2 _IOW('a', 'b', int32_t)
#define CMD_3 _IOW('a', 'c', int32_t)

#endif
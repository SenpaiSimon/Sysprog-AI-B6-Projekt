// Includes
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

// Defines
#define CMD_1 _IOR('a', 'a', int32_t*)
#define CMD_2 _IOR('a', 'b', int32_t*)
#define CMD_3 _IOR('a', 'c', int32_t*)

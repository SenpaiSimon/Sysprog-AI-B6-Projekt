#include "controller.h"

/********************************************************************************
 * Returns the dimensions of the Matrix in the Kernel Driver
 ********************************************************************************/
dimensions_t getDims() {
    // set default values
    dimensions_t dims;
    dims.lines = -1;
    dims.rows = -1;

    // Open the Device for use
	int fd = open("/dev/led_matrix", O_RDWR);
	if(fd < 0) {
		printf("Cannot open device file\n");
		return dims;
	}

    // Pass the data
    ioctl(fd, GET_DIMS, &dims);

    return dims;
}

/********************************************************************************
 * Sets the state of a pixel | 1 = on 0 = off
 ********************************************************************************/
int setPixel(uint8_t row, uint8_t line, uint8_t state) {
    // Open the Device for use
	int fd = open("/dev/led_matrix", O_RDWR);
	if(fd < 0) {
		printf("Cannot open device file\n");
		return -1;
	}

    // generate the data and pass it
    state_t input;
    input.row = row;
    input.line = line;
    input.state = state;

    ioctl(fd, SET_PIXEL, &input);

    // close the device after use
	close(fd);
}

/********************************************************************************
 * Returns the state of a pixel | 1 = on 0 = off
 ********************************************************************************/
uint8_t getPixelState(uint8_t row, uint8_t line) {
    // Open the Device for use
	int fd = open("/dev/led_matrix", O_RDWR);
	if(fd < 0) {
		printf("Cannot open device file\n");
		return -1;
	}

    // generate the data and pass it
    state_t input;
    input.row = row;
    input.line = line;

    ioctl(fd, READ_PIXEL, &input);

    // close the device after use
	close(fd);

    return input.state;
}
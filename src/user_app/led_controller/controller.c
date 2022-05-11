#include "controller.h"

void setPixel(uint8_t row, uint8_t line, uint8_t state) {
    // Open the Device for use
	int fd = open("/dev/led_matrix", O_RDWR);
	if(fd < 0) {
		printf("Cannot open device file\n");
		return;
	}

    //IOCT Command here
    state_t input;
    input.row = row;
    input.line = line;
    input.state = state;

    ioctl(fd, SET_PIXEL, &input);

    // close the device after use
	close(fd);
}

uint8_t getPixelState(uint8_t row, uint8_t line) {
    //IOCT Command here
}
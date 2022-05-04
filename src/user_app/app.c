#include "app.h"

int main(void)
{
    // Open the Device for use
	int fd = open("/dev/led_matrix", O_RDWR);
	if(fd < 0) {
		printf("Cannot open device file\n");
		return 0;
	}

    // actions 
    // TODO
	int8_t state = 0;

	for(int i = 0; i < 10; i++) {
		ioctl(fd, CMD_1, state);
	}

    // close the device after use
	close(fd);
	return EXIT_SUCCESS;
}

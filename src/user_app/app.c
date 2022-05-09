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
	state set;
	set.line = 2;
	set.row = 1;
	set.state = 1;

	//ioctl(fd, SET_PIXEL, &set);

    // close the device after use
	close(fd);
	return EXIT_SUCCESS;
}

#include "app.h"

dimensions_t DIMENSIONS;

int main(void)
{
    // get the dimensions for use in functions.c
    DIMENSIONS = getDims();

    // while(1) {
    //     led_snake(50);
    // }
    led_set_all(0);
    
	return EXIT_SUCCESS;
}

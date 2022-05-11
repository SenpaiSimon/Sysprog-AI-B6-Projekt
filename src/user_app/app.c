#include "app.h"

dimensions_t DIMENSIONS;

int main(void)
{
    // get the dimensions for use in functions.c
    DIMENSIONS = getDims();
    
	return EXIT_SUCCESS;
}

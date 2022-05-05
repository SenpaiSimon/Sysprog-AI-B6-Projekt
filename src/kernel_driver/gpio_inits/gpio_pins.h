#ifndef __GPIO_PINS__
#define __GPIO_PINS__

/********************************************************************************
 * How many Rows and lines are in the Chart
 ********************************************************************************/
#define ROWS 6
#define LINES 6

/********************************************************************************
 * Active High GPIOs
 ********************************************************************************/
#define H_GPIO_1 2
#define H_GPIO_2 3
#define H_GPIO_3 4 
#define H_GPIO_4 5
#define H_GPIO_5 6
#define H_GPIO_6 7

/********************************************************************************
 * Active Low GPIOs
 ********************************************************************************/
#define L_GPIO_1 22
#define L_GPIO_2 23
#define L_GPIO_3 24 
#define L_GPIO_4 25
#define L_GPIO_5 26
#define L_GPIO_6 27

/********************************************************************************
 * Pin Arrays
 ********************************************************************************/
static int hPin_arr[ROWS] = {H_GPIO_1, H_GPIO_2, H_GPIO_3, H_GPIO_4, H_GPIO_5, H_GPIO_6};
static char hPin_arr_names[ROWS][10] = {"H_GPIO_1", "H_GPIO_2", "H_GPIO_3", "H_GPIO_4", "H_GPIO_5", "H_GPIO_6"};
static int lPin_arr[LINES] = {L_GPIO_1, L_GPIO_2, L_GPIO_3, L_GPIO_4, L_GPIO_5, L_GPIO_6};
static char lPin_arr_names[LINES][10] = {"L_GPIO_1", "L_GPIO_2", "L_GPIO_3", "L_GPIO_4", "L_GPIO_5", "L_GPIO_6"};

#endif
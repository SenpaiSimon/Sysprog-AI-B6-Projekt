#ifndef __GPIO_PINS__
#define __GPIO_PINS__

/********************************************************************************
 * How many Rows and lines are in the Chart
 ********************************************************************************/
#define ROWS 8
#define LINES 8

/********************************************************************************
 * Active High GPIOs
 ********************************************************************************/
#define H_GPIO_1 2
#define H_GPIO_2 3
#define H_GPIO_3 4 
#define H_GPIO_4 5
#define H_GPIO_5 6
#define H_GPIO_6 7
#define H_GPIO_7 8
#define H_GPIO_8 9

/********************************************************************************
 * Active Low GPIOs
 ********************************************************************************/
#define L_GPIO_1 20
#define L_GPIO_2 21
#define L_GPIO_3 22 
#define L_GPIO_4 23
#define L_GPIO_5 24
#define L_GPIO_6 25
#define L_GPIO_7 26
#define L_GPIO_8 27

/********************************************************************************
 * Pin Arrays
 ********************************************************************************/
static int hPin_arr[ROWS] = {H_GPIO_1, H_GPIO_2, H_GPIO_3, H_GPIO_4, H_GPIO_5, H_GPIO_6, H_GPIO_7, H_GPIO_8};
static char hPin_arr_names[ROWS][10] = {"H_GPIO_1", "H_GPIO_2", "H_GPIO_3", "H_GPIO_4", "H_GPIO_5", "H_GPIO_6", "H_GPIO_7", "H_GPIO_8"};
static int lPin_arr[LINES] = {L_GPIO_1, L_GPIO_2, L_GPIO_3, L_GPIO_4, L_GPIO_5, L_GPIO_6, L_GPIO_7, L_GPIO_8};
static char lPin_arr_names[LINES][10] = {"L_GPIO_1", "L_GPIO_2", "L_GPIO_3", "L_GPIO_4", "L_GPIO_5", "L_GPIO_6", "L_GPIO_7", "L_GPIO_8"};

#endif
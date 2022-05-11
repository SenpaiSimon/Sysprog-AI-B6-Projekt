#include "app.h"

dimensions_t DIMENSIONS;

int main(void)
{
    // get the dimensions for use in functions.c
    DIMENSIONS = getDims();

    int running = 1;
    while(running) {
        printf("Select an Action from the Table below to perform:\r\n\r\n");
        printf("1: Set all LEDs [state]\n\r");
        printf("2: Set a single LED [row][line][state]\n\r");
        printf("3: Set a single ROW [row][state]\n\r");
        printf("4: Set a single LINE [line][state]\n\r");
        printf("5: Snake [delay]\n\r");
        printf("9: Exit App and Toggle off\n\r");

        switch(readNumber("Select")) {
            case 1: 
                printf("You selected: Toggle all LEDs\r\n");
                led_set_all(readNumber("Which state to you want"));
            break;

            case 2: 
                printf("You selected: Toggle a single LED\r\n");
                setPixel(readNumber("Row"), readNumber("Line"), readNumber("State"));
            break;

            case 3: 
                printf("You selected: Set a single ROW\r\n");
                led_set_row(readNumber("Row"), readNumber("State"));
            break;

            case 4: 
                printf("You selected: Set a single LINE\r\n");
                led_set_line(readNumber("Line"), readNumber("State"));
            break;

            case 5: 
                printf("You selected: Snake\r\n");
                led_snake(readNumber("Delay"));
            break;

            case 9:
                printf("See you next time!\r\n");
                led_set_all(0);
                running = 0;
            break;

            default:
                printf("Unknown function!\r\n");
        }
    }
    
	return EXIT_SUCCESS;
}

int readNumber(char *input) {
    int userInput;
    char flushInput[10];

    printf("%s: ", input);
    scanf("%i", &userInput);
    scanf("%c", flushInput);
    printf("\033[2J");
    
    return userInput;
}

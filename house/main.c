#include <stdio.h>
#include <windows.h>

int time = 1000;

/*Prints one roof tile based on the width of the house, and width of the roof itself.*/
int printRoofTile(int width, int widthOfHouse) {
    Sleep(time);

    int roofWidth = width * 2 + 1;
    int roofPadding = ((widthOfHouse - roofWidth) / 2) - 1;

    for (int i = 0; i < roofPadding; ++i) {
        printf(" ");
    }

    for (int i = 0; i < roofWidth + 2; ++i) {
        if (i == 0 || i == roofWidth + 1) {
            printf("*");
        } else {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}

/*Prints a line based on the width of the house*/
int printLine(int widthOfHouse) {
    Sleep(time);
    for (int i = 0; i < widthOfHouse; ++i) {
        printf("*");
    }
}

/*Prints a fence based on the width of the fence variable and if the ends with a "-" it will end it so it doesn't look wierd*/
int printFence(int widthOfFence) {
    for (int j = 0; j <= widthOfFence; ++j) {
        printf(j % 2 == 0 ? "-" : "|");
        Sleep(time / 2);
    }
    if (widthOfFence % 2 == 0) {
        printf("|");
    }
}

/*Prints a cool house based on 2 inputs
 input[0] = width of house
 input[1] = width of fence
 */
int printHouse(int input[]) {
    int widthOfHouse = input[0];
    int widthOfFence = input[1];

    for (int j = 0; j < ((widthOfHouse + 1) / 2) - 1; ++j) {
        printf(" ");
    }
    printf("* \n");

    for (int i = 0; i < (widthOfHouse / 2) - 1; ++i) {
        printRoofTile(i, widthOfHouse);
    }

    printLine(widthOfHouse);

    printf("\n");

    for (int i = 0; i < 3; ++i) {
        Sleep(time);
        printf("*");
        for (int j = 0; j < widthOfHouse - 2; ++j) {
            printf(" ");
        }
        printf("*");

        printFence(widthOfFence);

        printf("\n");
    }

    printLine(widthOfHouse);
    printFence(widthOfFence);
}

int main(void) {
    int input[2];
    printf("Enter the width of house: ");
    scanf("%d", &input[0]);

    printf("Enter the width of fence: ");
    scanf("%d", &input[1]);
    printf("\n");

    printHouse(input);
}

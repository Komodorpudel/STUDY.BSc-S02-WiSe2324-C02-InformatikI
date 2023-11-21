#include <stdio.h>

int main () {
    int x = 11;
    int rows = (x-1)/2; // Number of rows needed
    int r = 0;
    int column = 0;

    for (; r < rows; r++) {

        for (; column < x; column++) {
            if (column > r && column < x - r) {
                printf("x");

            }

            else {
                printf(" ");
            }

        }
        column = 0;
        printf("\n");
    }

    return 0;


}
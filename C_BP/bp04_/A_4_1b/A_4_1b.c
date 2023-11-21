#include <stdio.h>

int main () {
    int x = 11;
    int rows = (x+1)/2; // Number of rows needed: 6
    int row = 0;
    int column = 0;

    for (; row < rows; row++) {

        for (; column < x; column++) {
            if (column < row || column >= x - row) {
                printf(" ");

            }

            else {
                printf("x");
            }

        }
        column = 0;
        printf("\n");
    }

    return 0;


}
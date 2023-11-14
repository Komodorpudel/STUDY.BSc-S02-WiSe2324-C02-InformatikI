#include <stdio.h>

int main() {

    int index = 10;

    // rows
    for (int i = 1; i < 11; i++) {

        // Columns
        for (int j = 1; j < 11; j++) {

            if (j < index) {
                printf(" ");
            }

            else {
                printf("+");
            }

            

        }

        index--;

        printf("\n");

    }

    return 0;

}
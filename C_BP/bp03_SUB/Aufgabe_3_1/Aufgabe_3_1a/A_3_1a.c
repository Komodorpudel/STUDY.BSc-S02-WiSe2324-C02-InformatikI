#include <stdio.h>

int main() {

    int number = 1;

    // rows
    for (int i = 1; i < 8; i++) {

        // Columns
        for (int j = 1; j < 8; j++) {

            printf("%i\t", number);

            number++;

        }

        printf("\n");

    }

    return 0;

}
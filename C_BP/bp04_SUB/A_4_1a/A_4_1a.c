#include <stdio.h>

int main ()
{
    int rows = 5;
    int cols = 10;
    int i = 1;
    int j = 1;

    // die Zahlen springen exakt die Anzahl der rows
    for (; i <= rows; i++) {

        for (; j <= cols; j++) {

            /* Auszugebende Zahl */
            printf("%i\t", i + ((j - 1) * rows));
        }

        j = 1;

        printf("\n");
    }

    return 0;

}
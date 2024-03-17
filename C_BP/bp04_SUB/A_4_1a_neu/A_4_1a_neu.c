#include <stdio.h>

int main(void)
{
    int i; /* rows */
    int j; /* columns */

    for (i = 1; i <= 5; i++){
        for (j = 0; j < 5; j++){
            printf("%i\t", i + j * 5);
        }
        printf("\n");
    }

    return 0;

}
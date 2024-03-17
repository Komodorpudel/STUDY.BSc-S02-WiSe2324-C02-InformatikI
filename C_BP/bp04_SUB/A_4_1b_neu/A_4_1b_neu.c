#include <stdio.h>

int main(void)
{
    int i; /* Rows */
    int j; /* Columns */

    for (i = 0; i < 6; i++){
        for(j = 0; j < 11; j++){
            if (i <= j && j < 11 - i){
                printf("x");
            }
            else{
                printf(" ");
            }


        }
        printf("\n");
    }

    return 0;
}
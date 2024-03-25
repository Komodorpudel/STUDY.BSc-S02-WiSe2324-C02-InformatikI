#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gross_minus_klein (int *x, int *y)
{
    if (*x > *y){
        *x = *x - *y;
    }
    else {
        *y = *y - *x;
    }
}

int main(void)
{
    int x;
    int y;
    srand(time(NULL));

    x = rand() % 1001;
    y = rand() % 1001;

    while (x > 0 || y > 0){
        printf("x: %i; y: %i\n", x, y);
        gross_minus_klein(&x, &y);
    }
    printf("Fertig: x: %i; y: %i\n", x, y);

    return 0;

}

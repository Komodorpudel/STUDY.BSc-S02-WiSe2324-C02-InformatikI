#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Prototypem */
void gross_minus_klein(int *x, int *y);

int main(void) {

    int x;
    int y;

    srand(time(NULL));

    x = rand() % 1001;
    y = rand() % 1001;

    printf("Start: x: %i; y: %i\n", x, y);

    while (x > 0 && y > 0) {
        gross_minus_klein(&x, &y);
        printf("x: %i; y: %i\n", x, y);

    }

    printf("x: %i; y: %i", x, y);

    return 0;

}

void gross_minus_klein(int *x, int *y){

    if (*x > *y){
        *x = *x - *y;
    }

    else {
        *y = *y - *x;
    }

}

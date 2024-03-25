#include <stdio.h>
#include <math.h>




int floor_and_ceil(double x, int *f, int *c)
{
    if (f == NULL || c == NULL){
        return 1;
    }

    *f = floor(x);
    *c = ceil(x);

    return 0;

}

int main(void)
{
    double x = -16.321;
    int floor;
    int ceil;

    if(floor_and_ceil(x, &floor, &ceil) == 1){
        printf("Fehler beim Funktionsaufruf, Program wird abgebrochen\n");
        return -1;
    }

    printf("%i, %f, %i\n", floor, x, ceil);
    return 0;

}

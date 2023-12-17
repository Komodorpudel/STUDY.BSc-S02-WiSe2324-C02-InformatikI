#include <stdio.h>
#include <math.h>

/* Prototypen */
int floor_and_ceil (double x, int *f, int *c);


int main(void)
{
    int f;
    int c;
    double x = -16.321;
    int status;

    status = floor_and_ceil(x, &f, &c);

    if (status == 1) {
        printf("Achtung, Variable nicht initialisiert");
    }

    printf("f: %i; c: %i", f, c);

}

int floor_and_ceil (double x, int *f, int *c)
{

    if (f == NULL || c == NULL) {
        return 1;
    }
    else {

        *f = floor(x);
        *c = ceil(x);

    return 0;

    }

}

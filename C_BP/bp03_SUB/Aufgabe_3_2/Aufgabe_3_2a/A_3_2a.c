#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//Functions
double decrement (double x);

int main() {

    double d;
    double e;

    // random number to decrement
    srand(time(NULL));
    d = ((rand() % 91) + 5) / 10;

    e = decrement(d);

    printf("d: %f und decremented: %f", d, e);

}

double decrement (double x){
    int y = x - 1;

    return y;

}
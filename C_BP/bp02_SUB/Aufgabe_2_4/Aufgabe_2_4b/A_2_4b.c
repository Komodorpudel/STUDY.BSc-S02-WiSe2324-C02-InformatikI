#include <stdio.h>

int main () {

    double myDouble = 2.5;

    int myInt = (int) 2.5; // int stored nur die 2, nicht 2.5

    printf("myDouble: %f; myInt: %i\n", myDouble, myInt);

    printf("myDouble: %f; myInt: %i\n", myDouble * 5, myInt * 5);

    return 0;
}
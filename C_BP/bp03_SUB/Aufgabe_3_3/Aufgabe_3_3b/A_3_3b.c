#include <stdio.h>

// Functions
double power3(int n);

int main ()
{

    int i = -10;

    for (; i < 14; i++) {

        printf("fuer n = %i ist der Wert: %f\n", i, power3(i));
    }

    return 0;
}

double power3(int n)
{
    int exponent = n;
    int zahl = 3;
    double ergebnis = 1;

    if (n < 0) {
        n = -n;
    }

    for (; n > 0; n--) {
        ergebnis = ergebnis * zahl;
    }

    if (exponent >= 0) {
        return ergebnis;
    }

    else {
        return (1.0 / ergebnis);
    }
}
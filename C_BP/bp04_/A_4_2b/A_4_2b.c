#include <stdio.h>

// Functions
int fibonacci (int n);

int main ()
{

    printf("%i\n", fibonacci(12));

    return 0;

}

int fibonacci (int n) {

    int f1 = 1;
    int f2 = 1;

    /* Wir starten bei n = 3, erste Berechnung die durchgeführt werden muss */
    int i = 3;

    int fn = 1;

    if (n < 3) {
        return 1;
    }

    for (; i <= n; i++) {

        fn = f1 + f2;

        f1 = f2;
        f2 = fn;
    }

    return fn;
}
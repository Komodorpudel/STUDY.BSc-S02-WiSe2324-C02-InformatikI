#include <stdio.h>

// Functions
int sum_even (int n, int m);

int main ()
{
    int n = 2;
    int m = 6;

    printf("%i", sum_even(n,m));

    return 0;
}

int sum_even (int n, int m)
{
    /* Deklarieren und initialisieren */
    int sum = 0;
    int start = 0;
    int end = 0;

    if (m > n) {
        end = m;
        start = n;
    }
    else {
        end = n;
        start = m;
    }

    for (; start <= end; start++) {

        if (start % 2 == 0) {
            sum = sum + start;
        }
    }

    return sum;

}
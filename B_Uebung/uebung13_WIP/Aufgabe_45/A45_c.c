#include <stdio.h>

/* ----------------------------------------------- */

int algo(int a, int b)
{
    if (b == 1) {
        return a; /* Basisfall: wenn b 1 ist, gib a zurück. */
    }

    else {
        if (b % 3 == 0) {
            return algo(2 * a, b - 1); /* Rekursiver Aufruf, wenn b durch 3 teilbar ist. */
        }
        else {
            return algo(a - 1, b - 1); /* Rekursiver Aufruf, wenn b nicht durch 3 teilbar ist. */
        }
    }
}

/* ----------------------------------------------- */

int main()
{
    int a, b;
    printf("Geben Sie die Werte für a und b ein: ");
    scanf("%d %d", &a, &b);

    printf("Das Ergebnis von algo ist: %d\n", algo(a, b));

    return 0;
}

/* ----------------------------------------------- */

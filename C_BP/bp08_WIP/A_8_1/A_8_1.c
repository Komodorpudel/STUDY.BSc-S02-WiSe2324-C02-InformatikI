#include <stdio.h>

/* Prototypen */

int calc_square (int x);
void squared (int *x);

int main(void)
{

    int x = 10;
    int x_squared;

    printf("calc_square - Ich uebergebe: %i\n", x);
    x_squared = calc_square(x);
    printf("Ich erhalte: %i\n", x_squared);

    printf("squared - Ich uebergebe Adresse von x: %p\n", (void*)&x);
    squared(&x);
    printf("Mein neues x: %i", x);

}

/* Erhät den value von x und returned den quadrierten Wert */
int calc_square (int x)
{

    return x * x;
}


/* Erhält eine Reference zu x und überschreibt den Wert an der Stelle mit dem quadrierten Wert */
void squared (int *x)
{

    *x = *x * *x;
}
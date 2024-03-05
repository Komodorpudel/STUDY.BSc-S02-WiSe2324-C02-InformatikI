#include <stdio.h>

/* Prototype */
int product(int w[], int size);

int main(void)
{
    int w[6] = {1,2,3,4,5,6};

    int size = 3;

    printf("Ergebnis: %i",product(w, size));

    return 0;
}

int product(int w[], int size)
{
    int prod = 1;
    int i = 0;

    for(; i < size; i++) {
        prod = prod * w[i];
    }

    return prod;

}
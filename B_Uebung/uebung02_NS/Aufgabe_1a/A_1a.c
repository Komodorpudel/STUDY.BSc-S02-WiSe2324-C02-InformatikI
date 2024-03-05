#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    printf("n\tsqrt(n)\n");

    for(i = 0; i < 100; i++) {
        printf("%i\t%.2f\n", i, sqrt(i));
    }

    return 0;
}
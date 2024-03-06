#include <stdio.h>

int idiv(int s1, int s2);

int main(void)
{

    printf("%i",idiv(13,7));

    return 0;

}


int idiv(int s1, int s2)
{
    int s3 = 0;

    s1 = s1 - s2; /* Einmal machen wir das auf jeden Fall */

    while (s1 >= 0) {

        s1 = s1 - s2;
        s3 = s3 + 1; /* Wir zählen wie oft s2 in s1 reinpasst */
    }

    return s3;

}

int or(int s1, int s2)
{
    int s3 = 0;

    s3 = s1 || s2; /* Wenn eine der beiden ungleich 0 ist returnen wir 1 */

    return s3;
}

int fibonacci (int s1)
{
    int s2 = 1;
    int s3 = 1;
    int s4 = 0;


    while (s1 > 0) {
        
        s4 = s2;
        s2 = s3;

        s3 = s3 + s4;
        s1 = s1 - 1;

    }

    return s3;
}
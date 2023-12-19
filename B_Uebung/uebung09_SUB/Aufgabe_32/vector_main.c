#include <stdio.h>
#include "read_util.h"
#include "vector.h"

int main(void){

    float x;
    float y;

    float x2;
    float y2;

    /* Eingabe einlesen */
    read_vector(&x, &y);

    /* Normalisiseren */
    vector_norm(&x, &y);

    printf("x: %f; y: %f\n", x, y);
    printf("Length: %f\n", vector_length(x,y));

    /* Weitere 2 Vektoren eingeben: */
    printf("Neuer Vektor 1 eingeben:\n");
    read_vector(&x, &y);
    printf("Neuer Vektor 2 eingeben:\n");
    read_vector(&x2, &y2);

    /* Winkel bestimmen */
    printf("Winkel: %f", vector_angle(x, y, x2, y2));

    return 0;
}

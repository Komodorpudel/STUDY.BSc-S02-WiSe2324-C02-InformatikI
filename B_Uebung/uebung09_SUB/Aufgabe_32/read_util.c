#include <stdio.h>
#include "read_util.h"

#define VALID_INPUT 0
#define INPUT_ERROR 1

int read_vector(float* x, float* y)
{
    int status;
    int c;

    /* Vektor eingeben: */
    do {
        printf("READ - Bitte geben Sie einen Vektor(x,y) ein getrennt durch Leerzeichen:\n");
        status = scanf("%f %f", x, y);

        /* Puffer leeren */
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (status != 2){
            printf("Ungültige Eingabe");
        }
    }
    while (status != 2); /* Scanf returned die anzahl an eingelesenen werten */

    return 0;

}


#include "smatrix.h"
#include <stdio.h>

/* ----------------------------------- */

int main(void)
{
    int rows = 3, cols = 3;
    double *matrix = allocate_matrix(rows, cols);
    double *identity;

    /* Test: Matrixzugriff und -ausgabe */
    *access_matrix(matrix, rows, 1, 1) = 5.0; /* access_matrix gibt mir adresse, mit * gehe ich da hin */
    printf("Matrix nach Setzen eines Wertes:\n");
    print_matrix(matrix, rows, cols);

    /* Test: Einheitsmatrix */
    identity = create_identity_matrix(3);
    printf("Einheitsmatrix:\n");
    print_matrix(identity, 3, 3);

    /* Test: Zeilentausch */
    swap_rows(matrix, cols, 0, 1);
    printf("Matrix nach Zeilentausch:\n");
    print_matrix(matrix, rows, cols);

    /* Speicher freigeben */
    free_matrix(matrix);
    free_matrix(identity);

    return 0;
}

/* ----------------------------------- */

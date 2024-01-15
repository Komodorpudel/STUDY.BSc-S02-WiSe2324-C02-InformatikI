/* main.c */
#include "smatrix.h"
#include <stdio.h>

/* ----------------------------------- */

int main() {
    int rows = 3, cols = 3;
    double *matrix = allocate_matrix(rows, cols);

    /* Test: Matrixzugriff und -ausgabe */
    *access_matrix(matrix, rows, 1, 1) = 5.0;
    printf("Matrix nach Setzen eines Wertes:\n");
    print_matrix(matrix, rows, cols);

    /* Test: Einheitsmatrix */
    double *identity = create_identity_matrix(3);
    printf("Einheitsmatrix:\n");
    print_matrix(identity, 3, 3);

    /* Test: Zeilentausch */
    swap_rows(matrix, rows, cols, 0, 1);
    printf("Matrix nach Zeilentausch:\n");
    print_matrix(matrix, rows, cols);

    /* Speicher freigeben */
    free_matrix(matrix);
    free_matrix(identity);

    return 0;
}

/* ----------------------------------- */

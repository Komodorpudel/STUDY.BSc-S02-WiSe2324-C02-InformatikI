#include "smatrix.h"
#include <stdio.h>
#include <stdlib.h>

/* ----------------------------------- */

double *allocate_matrix(int rows, int cols)
{
    return malloc(rows * cols * sizeof(double));
}

/* Beachte: Einfachzeiger soll zurück, deswegen in dieser form. nur mit doppelzeiger kann ich m[][] erstellen.

Ich muss mir die cols merken. Es gibt keine möglichkeit, das dynamisch rauszufinden*/


/* via Doppelzeiger würde so aussehen:

double **allocate_matrix(int rows, int cols) {
    double **m = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        m[i] = malloc(cols * sizeof(double));
    }
    return m;
}

Zugriff via m[i][j]

äquivalent zu *(*(matrix + i) + j)

 */
/* ----------------------------------- */

double *access_matrix(double *matrix, int rows, int i, int j)
{
    return &matrix[i * rows + j];

    /* Mit i * rows muss ich erstmal in die richtige Row. Mit j dann zur column */
}

/* ----------------------------------- */

double *create_identity_matrix(int size)
{
    /* Erstmal Speicherplatz reservieren */
    double *matrix = allocate_matrix(size, size);

    if (matrix != NULL) {
        int i, j;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {

                /* Wenn Diagonale, dann 1.0 */
                matrix[i * size + j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }
    return matrix;
}

/* ----------------------------------- */

void swap_rows(double *matrix, int cols, int row1, int row2)
{
    int j;
    for (j = 0; j < cols; j++) {

        /* Mit row1 * cols springe ich zur richtigen Reihe */
        double temp = matrix[row1 * cols + j];
        matrix[row1 * cols + j] = matrix[row2 * cols + j];
        matrix[row2 * cols + j] = temp;
    }
}

/* ----------------------------------- */

void print_matrix(double *matrix, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

/* ----------------------------------- */

void free_matrix(double *matrix)
{
    free(matrix);
}

/* ----------------------------------- */

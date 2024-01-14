/* smatrix.c */
#include "smatrix.h"
#include <stdio.h>
#include <stdlib.h>

double *allocate_matrix(int rows, int cols) {
    return (double *)malloc(rows * cols * sizeof(double));
}

double *access_matrix(double *matrix, int rows, int i, int j) {
    return &matrix[i * rows + j];
}

double *create_identity_matrix(int size) {
    double *matrix = allocate_matrix(size, size);
    if (matrix != NULL) {
        int i, j;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                matrix[i * size + j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }
    return matrix;
}

void swap_rows(double *matrix, int rows, int cols, int row1, int row2) {
    int j;
    for (j = 0; j < cols; j++) {
        double temp = matrix[row1 * cols + j];
        matrix[row1 * cols + j] = matrix[row2 * cols + j];
        matrix[row2 * cols + j] = temp;
    }
}

void print_matrix(double *matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

void free_matrix(double *matrix) {
    free(matrix);
}

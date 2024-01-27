#include <stdio.h>

/* --------------------------------------- */

int isSymmetric(double **matrix, int n) { /* Zeiger auf Zeiger */
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; /* Not symmetric */
            }
        }
    }
    return 1; /* Symmetric */
}

/* --------------------------------------- */

int main() {
    int n = 3; /* Example size */
    double a[3][3] = {{1, 2, 3}, {2, 4, 5}, {3, 5, 6}}; /* Example matrix */

    /* Alternativer Ansatz: 1D Array verwenden und Indizes selbst berechnen, dann könnte ich es direkt übergeben an isSymmetric */

    /* Zugriff darauf: *(*(a + i) + j) */
    printf("Testausgabe:\n");
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%lf ", *(*(a + i) + j)); // Zugriff auf das Element [i][j] mit Zeigerarithmetik
        }
        printf("\n");
    }

    /* +++++++++ */

    /* Convert 2D array to a double pointer. */
    double *matrix[3]; /* Deklariere matrix das 3 Zeiger enthällt */
    for (int i = 0; i < n; i++) {
        matrix[i] = a[i];
    }

    /* Check if the matrix is symmetric */
    int result = isSymmetric(matrix, n); /* isSymmetric(a, n) funktioniert nicht, weil a dann zu einem Zeiger auf das erste Element wird, also kein Doppelzeiger */

    if (result == 1) {
        printf("The matrix is symmetric.\n");
    }
    
    else {
        printf("The matrix is not symmetric.\n");
    }
    return 0;
}

/* --------------------------------------- */

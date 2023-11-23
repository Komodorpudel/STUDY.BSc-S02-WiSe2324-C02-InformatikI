#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10 /* Kein spezifischer variablen typ. Einfach eine 10 vor dem Compilen */

/* Funktion zur Initialisierung der Matrix */
void matrix_init(int m[][MAX_SIZE], int n)  /* rows first, then columns  */
{
    int i, j;

    /* durch zeilen loopen */
    for (i = 0; i < n; i++) {

        /* durch spalten loopen */
        for (j = 0; j < n; j++) {

            m[i][j] = rand() % 11;  /* Zufallszahlen zwischen 0 und 10 */

        }
    }
}

/* Funktion zum Drucken der Matrix */
void matrix_print(int m[][MAX_SIZE], int n)
{
    int i, j;

    /* durch reihen loopen */
    for (i = 0; i < n; i++) {

        /* durch spalten loopen */
        for (j = 0; j < n; j++) {

            // Ausgabe
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

/* Funktion zur Addition zweier Matrizen */
void matrix_add(int m1[][MAX_SIZE], int m2[][MAX_SIZE], int n)
{
    int i, j;

    /* Durch Zeilen loopen */
    for (i = 0; i < n; i++) {

        /* Durch Spalten loopen */
        for (j = 0; j < n; j++) {

            /* Addieren */
            m1[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

/* Funktion zur Multiplikation zweier Matrizen */
void matrix_mult(int m1[][MAX_SIZE], int m2[][MAX_SIZE], int n)
{
    /* temporary matrix */
    int temp[MAX_SIZE][MAX_SIZE];
    int i, j, k;

    /* zeilen loopen */
    for (i = 0; i < n; i++) {

        /* spalten loopen */
        for (j = 0; j < n; j++) {

            /* Befüllen */
            temp[i][j] = 0;
            for (k = 0; k < n; k++) {
                temp[i][j] = temp[i][j] + (m1[i][k] * m2[k][j]); /* rows first, then columns  */
            }
        }
    }

    /* Kopieren des Ergebnisses zurück in m1 */
    for (i = 0; i < n; i++) {

        for (j = 0; j < n; j++) {

            m1[i][j] = temp[i][j];
            
        }
    }
}

int main()
{
    int n = 3; /* Größe der Matrizen */
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int i;

    /* Initialisierung des Zufallsgenerators */
    srand((unsigned) time(NULL)); 

    /* Initialisierung der Matrizen */
    matrix_init(matrix1, n);
    matrix_init(matrix2, n);

    /* Ausgabe der initialisierten Matrizen */
    printf("Matrix 1:\n");
    matrix_print(matrix1, n);
    printf("\nMatrix 2:\n");
    matrix_print(matrix2, n);

    /* Addition der Matrizen */
    matrix_add(matrix1, matrix2, n);
    printf("\nMatrix 1 + Matrix 2:\n");
    matrix_print(matrix1, n);

    /* Multiplikation der Matrizen */
    matrix_mult(matrix1, matrix2, n);
    printf("\nMatrix 1 * Matrix 2:\n");
    matrix_print(matrix1, n);

    return 0;
}

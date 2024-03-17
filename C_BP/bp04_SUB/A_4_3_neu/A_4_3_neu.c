#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 7 /* Vorischt, kein Semicolon machen, das wird sonst mit reingezogen */

void matrix_init(int m[][MAX_SIZE], int n)
{ /* Wir müssen C direkt wissen lassen, wie viele Spalten wir brauchen -------- Das ist nur für die zweite Dimension notwendig. Wir verwenden also worst Case zu viele Spalten -> Alternative wäre dynamische Allokation */

    int i;
    int j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            m[i][j] = rand() % 11;
        }
    }

}

void matrix_print(int m[][MAX_SIZE], int n)
{

    int i;
    int j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%i\t", m[i][j]);
        }
        printf("\n");
    }

}

void matrix_add(int m1[][MAX_SIZE], int m2[][MAX_SIZE], int n){

    int i;
    int j;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            m1[i][j] += m2[i][j];
        }
        printf("\n");
    }
}

void matrix_mult(int m1[][MAX_SIZE], int m2[][MAX_SIZE], int n)
{
    /* Vorsicht, bei statischer Allokation muss Größe zur Kompilierzeit bekannt sein, ich kann also nicht einfach n verwenden */
    int m3[MAX_SIZE][MAX_SIZE];
    int i, j, k;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            m3[i][j] = 0;

            /* Eintrag berechnen */
                for (k = 0; k < n; k++){
                    m3[i][j] += m1[i][k] * m2[k][i];
                }
        }
        printf("\n");
    }

    /* m3 auf m1 übertragen */
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            m1[i][j] = m3[i][j];
        }
    }

}

int main(void)
{

    srand(time(NULL));

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
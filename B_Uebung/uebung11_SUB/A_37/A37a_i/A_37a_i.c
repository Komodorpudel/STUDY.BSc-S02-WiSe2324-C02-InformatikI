#include <stdio.h>
#include <stdlib.h>

int main() {
    int **m = malloc(2 * sizeof(int*));
    m[0] = malloc(3 * sizeof(int));
    m[1] = malloc(3 * sizeof(int));

    // Initialisiere das Array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] = i * 3 + j;  // Einfache Zuweisung für Testzwecke
        }
    }

    // Drucke das Array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Gib den Speicher frei
    for (int i = 0; i < 2; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *m = malloc(3 * sizeof(int*));  // Reserviert Speicher für 3 int*-Zeiger

    // Typumwandlung von m zu int**
    int **m_cast = (int**)m;

    m_cast[0] = malloc(3 * sizeof(int));  // Reserviert Speicher für ein Array von 3 ints
    m_cast[1] = malloc(3 * sizeof(int));  // Reserviert Speicher für ein weiteres Array von 3 ints

    // Initialisiere das Array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            m_cast[i][j] = i * 3 + j;
        }
    }

    // Drucke das Array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m_cast[i][j]);
        }
        printf("\n");
    }

    // Gib den Speicher frei
    for (int i = 0; i < 2; i++) {
        free(m_cast[i]);
    }
    free(m);

    return 0;
}

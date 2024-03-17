#include <stdio.h>
#include <math.h>

int main()
{
    int a[4];

    a[0] = 144; // Erste Komponente
    a[1] = (int) sqrt(a[0]); // Zweite Komponente (Quadratwurzel von a[0], gerundet)
    a[2] = a[0] - a[1]; // Dritte Komponente (a[0] minus a[1])
    a[3] = a[2] / 6; // Vierte Komponente (a[2] geteilt durch 6)

    // Ausgabe der Werte
    printf("Erste Komponente: %d\n", a[0]);
    printf("Zweite Komponente (Quadratwurzel): %d\n", a[1]);
    printf("Dritte Komponente (Differenz): %d\n", a[2]);
    printf("Vierte Komponente (Division): %d\n", a[3]);

    return 0;
}

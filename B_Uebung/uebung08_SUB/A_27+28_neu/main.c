#include <stdio.h>
#include <math.h>

#include "geometrie.h"

#define PRINT_POINT(p) printf("(%lf, %lf)\n", p[X], p[Y]);

int main(void) {
    double p1[] = {1, 2};
    double p2[] = {3, 4};
    double line1[2];
    double line2[2];
    double line3[2] = {1, 1};
    double line4[2] = {1, 0};

    /* Teilaufgabe d) - Rundung testen */
    double x = 2.0;
    double y = sqrt(2.0);
    /* Eregebnis: */
    printf("%i\n", x == y * y);
    /* Zu erwarten wäre 2 */

    printf("Ausgabe eines Punktes auf der Kommandozeile:\n");
    PRINT_POINT(p1);

    printf("Ausgabe Abstand zwei Punkte:\n");
    printf("%f\n", distance(p1, p2));

    printf("Gerade berechnen:\n");
    printf("Status: %d\n", calculate_line(line1, p1, p2));
    printf("Steigung: %f, Achsenabschnitt: %f\n", line1[SLOPE], line1[YZERO]);

    printf("Gerade berechnen bei gleichem x:\n");
    printf("Status: %d\n", calculate_line(line2, p2, p2));
    printf("Steigung: %f, Achsenabschnitt: %f\n", line1[SLOPE], line1[YZERO]);

    printf("Testen ob Punkt auf Gerade liegt (ist der Fall):\n");
    printf("Ist auf Linie: %d\n", is_point_on_line(p1, line3));

    printf("Testen ob Punkt auf Gerade liegt (ist nicht der Fall):\n");
    printf("Ist auf Linie: %d\n", is_point_on_line(p1, line4));

    return 0;
}

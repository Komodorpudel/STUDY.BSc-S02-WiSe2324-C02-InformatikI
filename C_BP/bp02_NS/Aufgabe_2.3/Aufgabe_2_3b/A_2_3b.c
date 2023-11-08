#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // dritte Potenz

    double x = 5.0;
    double y = pow (x,3);

    printf("Y: %e\n", y);

    // Tagens
    printf("Tangens:\n");

    double tangent = tan(1.5 * M_PI / 180);

    printf("%e\n", tangent);

    // natürliche Log
    printf("Natuerlicher Log:\n");
    double number = 12345.0;
    printf("%e\n", log(number));

    // Log zur Basis 10
    printf("Log10:\n");
    printf("%e\n", log10(321.0));

    // Wert der Exponentialfunktion
    printf("Exp:\n");
    printf("%f\n", pow(M_E, 11));

    // kleinsten ganzzahligen Wert
    printf("Kleinster ganzzahliger Wert:\n");
    double d = 2.5;
    double square = pow(d,2);
    int result = (int) square; // umwandeln in ganze Zahl (cuttet)
    printf("%i\n", result);

    // größten ganzzahligen Wert
    printf("groester ganzzahliger Wert:\n");
    double l = log10(9999.0);
    int li = (int) l;
    printf("%e\n", l);

    return 0;
}
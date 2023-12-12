#include <stdio.h>
#include "my_math.h"
#include <float.h>
#include <errno.h>
#include <math.h>

double my_pow(double x, int y) {

    /* x ist Basis, y ist Exponent */
    int i = 1;
    double result = 1.0;
    int absY = MY_FABS(y);

    /* Domain Error */
    if (x == 0 && y <= 0) {
        errno = EDOM; /* errno stands for Error Number */
        return 0;
    }

    /* Die Variable errno ist in der Standardbibliothek von C definiert und wird für die Fehlerberichterstattung verwendet. Sie ist in der Header-Datei <errno.h> deklariert. */

    /* EDOM ist ein Fehlercode, der in der C-Standardbibliothek definiert ist. Er steht für "Error Domain" und wird verwendet, um anzuzeigen, dass ein Eingabewert außerhalb des Definitionsbereichs (engl. "domain") einer mathematischen Funktion liegt. Das Makro EDOM ist in der Header-Datei <errno.h> definiert. */

    /* Wenn exponent 0 */
    if (y == 0) {
        return 1.0;
    }

    /* Wenn Basis 0 */
    if (x == 0) {
        return 0.0;
    }

    /* Faktor berechnen */
    for (; i < absY; i++) {

        /* Wenn der nächste Wert größer als DBL_Max wäre: */
        if (y > 0 && result > DBL_MAX / x) {
            errno = ERANGE;
            return x > 0 ? HUGE_VAL : -HUGE_VAL;
        }

        /* Wenn der nächste Wert kleiner als DBL_Min wäre: */
        if (y < 0 && result < DBL_MIN * x) {
            errno = ERANGE;
            return x > 0 ? +0.0 : -0.0;
        }

        result = result * x;

    }

    /* Return */
    if (y < 0) {
        return 1 / result;
    }
    else {
        return result;
    }

}

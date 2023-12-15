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
    /* printf("%i\n", absY); */

    /* Domain Error */
    if (x == 0 && y <= 0) { /* Wir würden 0 durch irgendwas teilen */
        errno = EDOM; /* errno stands for Error Number */
        return 0.0;
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

    /* ++++++++++++++++++++++++++++++++++ */
    /* x hoch y */
    
    /* x pos */
    if (x > 0) {

        for (; i <= absY; i++) {

            /* x >= 1 */
            /* y > 0 */
            /* Überlauf */
            if (x >= 1 && y > 0 && result > DBL_MAX / x) {
                errno = ERANGE;
                return +HUGE_VAL;
            }

            /* x >= 1 */
            /* y < 0 */
            /* Unterlauf */
            if (x >= 1 && y < 0 && result < DBL_MIN / x) {  /* z.B. (2^-100) */
                errno = ERANGE;
                return +0.0;
            }

            /* x < 1 */
            /* y < 0 */
            /* Überlauf */
            if (x < 1 && y < 0 && result > DBL_MAX / x) { /* z.b. 0.5 ^ (-2) = 1 / 0.25 = 4 */
                errno = ERANGE;
                return +HUGE_VAL;
            }

            /* x < 1 */
            /* y > 0 */
            /* Unterlauf */
            if (x < 1 && y >= 1 && result < DBL_MIN / x) { /* z.B. 0.5^2 = 0.25 */
                errno = ERANGE;
                return +0.0;
            }

            if (y > 0) {

            result = result * x;

            }
            else {
                result = result * 1/x;
            }

        }

        return result;

    }

    /* x neg */
    else {

        /* Wenn y gerade ist, dann gleiches Ergebnis wie mit abs(X) */
        if (y % 2 == 0) {

            return my_pow(MY_FABS(x), y);

        }

        /* Wenn y ungerade, dann wird negative Zahl rauskommen */
        else {
        
            return -my_pow(MY_FABS(x),y);
            
        }
    }

}

#include "line_from_points.h"
#include "points.h"
#include "lines.h"

int line_from_points(double g[], double p1[], double p2[])
{
    if (is_equal(p1[X], p2[X])) { /* Hier prüfen, wir nicht ob y gleich ist. Das problem mit Berechnung unten ist, dass Steigung Unendlich eben nicht klappt, ich teile durch 0 */

        return 0;

    }

    /* Steigung ermitteln */
    g[M] = (p2[Y] - p1[Y]) / (p2[X] - p1[X]);

    /* Achenabschnitt ermitteln */
    /* ich gehe zu p1 und ziehe dort die Steigung mal den x Wert ab */
    g[Y0] = p1[Y] - g[M] * p1[X];

    return 1;

}

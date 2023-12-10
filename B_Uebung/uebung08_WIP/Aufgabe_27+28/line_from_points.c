#include "line_from_points.h"

int line_from_points(double g[], double p1[], double p2[]) {
    if (is_equal(p1[X], p2[X])) return 0;
    g[M] = (p2[Y] - p1[Y]) / (p2[X] - p1[X]);
    g[Y0] = p1[Y] - g[M] * p1[X];
    return 1;
}

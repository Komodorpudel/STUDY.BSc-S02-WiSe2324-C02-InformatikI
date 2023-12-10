#include "distance.h"
#include <math.h>

double distance(double p1[], double p2[]) {
    return sqrt(pow(p2[X] - p1[X], 2) + pow(p2[Y] - p1[Y], 2));
}

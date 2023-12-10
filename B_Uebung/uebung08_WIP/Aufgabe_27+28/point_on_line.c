#include "point_on_line.h"

int point_on_line(double point[], double line[]) {
    double y = line[M] * point[X] + line[Y0];
    return is_equal(point[Y], y);
}

#include "point_on_line.h"
#include "lines.h"
#include "points.h"

int point_on_line(double point[], double line[])
{
    /* Wenn ich x in geradengleichung einsetze kommt y raus */
    double y = line[M] * point[X] + line[Y0];

    /* wenn y gleich point-y ist, dann liegt punkt auf der geraden */
    return is_equal(point[Y], y);
}

#include "double_compare.h"
#include <math.h>

int is_equal(double a, double b)
{
    return fabs(a - b) < DIFF; /* float absolute */
}

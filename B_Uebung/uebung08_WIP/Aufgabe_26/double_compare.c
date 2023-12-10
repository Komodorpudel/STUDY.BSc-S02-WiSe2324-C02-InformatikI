#include "double_compare.h"

int is_equal(double a, double b) {
    return fabs(a - b) < EPSILON;
}

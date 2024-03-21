#include <math.h> /* für sqrt und fabs */

#include "geometrie.h"

/* ----------------------------------------------------- */

double distance(double p1[], double p2[])
{
    double part_1;
    double part_2;

    part_1 = pow((p1[X] - p2[X]), 2);
    part_2 = pow((p1[Y] - p2[Y]), 2);

    return sqrt(part_1 + part_2);

}

/* ----------------------------------------------------- */

int is_equal_up_to_error(double x, double y)
{
    return (fabs (x - y) <= EPS);
}

/* ----------------------------------------------------- */

int calculate_line(double p1[], double p2[], double g[])
{
    if(is_equal_up_to_error(p1[X], p2[X])){
        return INVALID;
    }

    g[SLOPE] = ((p2[Y] - p1[Y]) / (p2[X] - p1[X]));
    g[YZERO] = p1[Y] - g[SLOPE] * p1[X];

    return VALID;
}

/* ----------------------------------------------------- */

int is_point_on_line(double p1[], double g[]){

    double y = p1[X] * g[SLOPE] + g[YZERO];

    if (is_equal_up_to_error(y, p1[Y])){
        return VALID;
    }
    else{
        return INVALID;
    }
}

/* ----------------------------------------------------- */

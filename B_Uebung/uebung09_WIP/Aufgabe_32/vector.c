#include <stdio.h>
#include <math.h>

float vector_length(float x, float y)
{
    return sqrt ( (x * x) + (y * y) );
}

void vector_norm(float* x, float* y)
{
    *x = (*x / (vector_length(*x, *y)));
    *y = (*y / (vector_length(*x, *y)));
}

float vector_angle(float x1, float y1, float x2, float y2)
{
    return (acos(x1 * x2 + y1 * y2) / (vector_length(x1, y1) * vector_length(x2, y2))) * (180.0 / M_PI);   
}

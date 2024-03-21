#ifndef GEOMETRIE_H_INCLUDED
#define GEOMETRIE_H_INCLUDED

/* ALlgemeines */
#define VALID 1
#define INVALID 0

/* Teilaufgabe a */
#define LEN_POINT 2
#define X 0
#define Y 0

/* Teilaufgabe c */
#define LEN_LINE 2
#define SLOPE 0
#define YZERO 1

/* Teilaufgabe e */
#define EPS 1E-5 /* 1 * 10^(-5) */


double distance(double p1[], double p2[]);
int is_equal_up_to_error(double x, double y);
int calculate_line(double p1[], double p2[], double g[]);
int is_point_on_line(double p1[], double g[]);

#endif

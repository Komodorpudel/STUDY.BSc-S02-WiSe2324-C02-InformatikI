
#ifndef SMATRIX_H

/* Anfang */
#define SMATRIX_H

/* Funktion zur Speicherreservierung */
double *allocate_matrix(int rows, int cols);

/* Funktion zum Zugriff auf einen Matrixeintrag */
double *access_matrix(double *matrix, int rows, int i, int j);

/* Funktion für Einheitsmatrix */
double *create_identity_matrix(int size);

/* Funktion für Zeilentausch */
void swap_rows(double *matrix, int rows, int cols, int row1, int row2);

/* Funktion für Ausgabe */
void print_matrix(double *matrix, int rows, int cols);

/* Funktion zur Speicherfreigabe */
void free_matrix(double *matrix);

/* Ende */
#endif

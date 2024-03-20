#ifndef A_35_36_H_INCLUDED

/* Anfang */
#define A_35_36_H_INCLUDED

#include <stdlib.h> /* Für dynamische Speicherallokation */
#include <time.h>
#include "print-utils.h"

#define ALIVE 1 /* Symbolische Konstante für lebenden Status */
#define DEAD 0  /* Symbolische Konstante für toten Status */
#define NUM_GENERATIONS 10 /* Symbolische Konstante für die Anzahl von Generationen */

/* Prototypes */
int **field_init(int width, int height);
int random_state(double live_probability);
void print_field(int **field, int width, int height);
int alive_neighbors(int **field, int width, int height, int x, int y);
int **next_state(int **field, int width, int height);
int game_of_life(int **field, int width, int height);

/* Ende */
#endif

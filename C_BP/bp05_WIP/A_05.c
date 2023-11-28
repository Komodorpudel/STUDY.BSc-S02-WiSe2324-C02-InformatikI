#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* --------------------------------------------- */

unsigned int my_interval_rand(unsigned int u, unsigned int o)
{
    unsigned int range;
    unsigned int min;
    unsigned int rand_num;

    /* Testen was größer ist */
    if (u > o) {
        min = o;
        range = u - (o + 1); /* + 1 wegen einschließlich */
    }
    
    else {
        min = u;
        range = o - (u + 1);
    }
    
    rand_num = rand() % range;
    return min + rand_num;
}

/* --------------------------------------------- */

void array_init(unsigned int w[], unsigned int n, unsigned int u, unsigned int o)
{
    unsigned int i;

    for (i = 0; i < n; i++) {
        w[i] = my_interval_rand(u, o);
    }
}

/* --------------------------------------------- */

unsigned int array_second_min(unsigned int w[], unsigned int n)
{
    unsigned int min = UINT_MAX;
    unsigned int second_min = UINT_MAX;
    unsigned int i;

    for (i = 0; i < n; i++) {

        /* Das kleinste tauschen, wenn ich Zahl finde, die kleiner ist als aktuelles min */
        if (w[i] < min) {
            second_min = min;
            min = w[i];
        }

        /* Das zweitkleinste tauschen, wenn ich Zahl finde, die kleiner ist als second_min (Aber größer min)*/
        else if (w[i] < second_min && w[i] != min) {
            second_min = w[i];
        }
    }

    return (second_min == UINT_MAX) ? UINT_MAX : second_min;
}

/* --------------------------------------------- */

int main()
{
    unsigned int numbers[10];
    unsigned int i;
    
    srand(time(NULL));  // Initialisierung des Zufallszahlengenerators

    array_init(numbers, 10, 100000, 999999);

    /* Zeilenweise ausgeben */
    printf("Zahlenfeld:\n");
    for (i = 0; i < 10; i++) {
        printf("%u\n", numbers[i]);
    }

    /* Zweitkleinster Wert speichern */
    unsigned int second_min = array_second_min(numbers, 10);

    /* Ausgeben, falls der Wert nicht UNIT_MAX ist */
    if (second_min != UINT_MAX) {
        printf("Zweitkleinstes Element: %u\n", second_min);
    } else {
        printf("Es gibt kein zweitkleinstes Element.\n");
    }

    return 0;
}

/* --------------------------------------------- */

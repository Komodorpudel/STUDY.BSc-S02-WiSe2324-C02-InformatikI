#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

unsigned int my_interval_rand(unsigned int u, unsigned int o)
{
    unsigned int min;
    unsigned int max;

    /* Min und Max finden */
    if (u > o){
        max = u;
        min = o;
    }
    else {
        max = o;
        min = u;
    }

    /* Zufallszahl generieren und zurückgeben*/
    return (min + rand() % ((max - min) + 1));

}

void array_init(unsigned int w[], unsigned int n, unsigned int u, unsigned int o)
{
    int i;
    for(i = 0; i < n; i++){
        w[i] = my_interval_rand(u, o);
    }
}

unsigned int array_second_min(unsigned int w[], unsigned int n)
{
    unsigned int first_min = UINT_MAX;
    unsigned int second_min = UINT_MAX;
    int i;

    if (n < 2){
        return UINT_MAX;
    }

    for(i = 0; i < n; i++) {
        if (w[i] <= first_min){
            second_min = first_min;
            first_min = w[i];
        }
        else if(w[i] < second_min){
            second_min = w[i];
        }
    }

    return second_min;

}

/* --------------------------------------------- */

int main(void)
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

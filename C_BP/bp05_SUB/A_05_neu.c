#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int main(void){

}

unsigned int my_interval_rand(unsigned int u, unsigned int o)
{
    int i;
    unsigned int min;
    unsigned int max;

    srand(time(NULL));

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
    unsigned int first_min = UNIT_MAX;
    unsigned int second_min = UNIT_MAX;
    int i;

    if (n < 2){
        return UNIT_MAX;
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
#include "print-utils.h"

void clear_field()
{
    int i;
    for (i = 0; i < CLEAR_HEIGHT; i++) {
        printf("\n");
    }
}

void wait_ticks(int ticks)
{
    int i = ticks;
    while (i != 0) {
        --i;
    }
}

void wait(int time)
{
    SLEEP(time);
}

void print_living_cell()
{
    printf("%s", TILE_LIVE);
}

void print_dead_cell()
{
    printf("%s", TILE_DEAD);
}

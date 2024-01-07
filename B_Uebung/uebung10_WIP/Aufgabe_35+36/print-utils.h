#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <stdio.h>
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(t) Sleep(1000 * (t))
    #define TILE_LIVE "O"
    #define TILE_DEAD " "
#else
    #include <unistd.h>
    #define SLEEP(t) sleep(t)
    #define TILE_LIVE "██"
    #define TILE_DEAD "  "
#endif

#define CLEAR_HEIGHT 13

void clear_field(void);
void wait_ticks(int ticks);
void wait(int time);
void print_living_cell(void);
void print_dead_cell(void);

#endif

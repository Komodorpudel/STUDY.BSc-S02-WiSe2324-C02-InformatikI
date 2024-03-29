#ifndef BACKPACK_H_INCLUDED
#define BACKPACK_H_INCLUDED

#include "potion.h"

#define BACKPACK_SIZE 3

typedef struct _backpack {
    potion potions[BACKPACK_SIZE];
    int total_weight;

} backpack;

#endif

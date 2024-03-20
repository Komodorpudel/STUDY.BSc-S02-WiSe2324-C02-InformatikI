#include "random_utils.h"
#include <stdlib.h>

/* ----------------------------------- */

int random_up_to(int upper_bound)
{
    return rand() % (upper_bound + 1);
}

/* ----------------------------------- */

int choose_random(int array[], int array_len)
{
    return array[random_up_to(array_len - 1)];
}

/* ----------------------------------- */

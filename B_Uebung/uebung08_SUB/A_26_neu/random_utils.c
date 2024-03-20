#include <stdlib.h>
#include "random_utils.h"

/* -------------------------------------- */

int random_up_to(int upper_bound)
{
    return rand() % (upper_bound + 1);
}

/* -------------------------------------- */

int choose_random(int array[], int array_len)
{
    int pos = random_up_to(array_len - 1);
    return array[pos];
}

/* -------------------------------------- */

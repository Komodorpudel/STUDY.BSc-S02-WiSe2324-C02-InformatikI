#include <stdlib.h>
#include "list.h"

int list_sum(list m)
{
    if (m == EMPTY_LIST) {
        return 0;
    }
    else {
        return m->element + list_sum(m->next);
    }
}
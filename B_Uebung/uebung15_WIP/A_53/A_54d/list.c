#include <stdlib.h>

#include "list.h"

list list_search(list m, int n)
{
    while (m != EMPTY_LIST) {
        if (m->element == n) {
            return m;
        }
    m = m->next;
    }
    return NULL;
}
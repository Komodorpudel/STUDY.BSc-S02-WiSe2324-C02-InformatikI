#include <stdlib.h>

#include "stack.h"

int stack_push(stack m, int n)
{
    int *new = realloc(m->elements, (m->size + 1) * sizeof(int));
    if (new == NULL) {
    return 0;
    }m
    ->elements = new;
    m->elements[m->size] = n;
    ++(m->size);
    return 1;
}

int stack_pop(stack m, int *success)
{
    int n;
    int *new;
    if (m->size == 0) {
        if (success != NULL) {
            *success = 0;
        }
        return 0;
    }
    n = m->elements[m->size - 1];
    new = realloc(m->elements, (m->size - 1) * sizeof(int));
    if (new == NULL) {
        if (success != NULL) {
        *success = 0;
    }
    return 0;
    }
    m -> elements = new;
    --(m->size);
    if (success != NULL)
    *success = 1;
    return n;
}
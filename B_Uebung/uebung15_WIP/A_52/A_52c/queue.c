#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"

/* ------------------------------- */
queue queue_create(void)
{
    queue q = malloc(sizeof(struct _queue));
    if (q == NULL)
    return NULL;
    q->first = EMPTY_QUEUE;
    q->last = EMPTY_QUEUE;
    return q;
}

/* ------------------------------- */
void queue_destroy(queue q)
{
    if (q != NULL) {
        if (!queue_isempty(q))
            list_destroy(q->first);
            free(q);
    }
}

/* ------------------------------- */
list list_destroy(list l) { /* void würde eigentlich auch gehen */
if (l != EMPTY_LIST) {
        list_destroy(l->next);
        free(l);
    }
return EMPTY_LIST;
}

/* ------------------------------- */
/* Selber gebaut: */
void list_print(list l)
{
    int i = 1;
    while (l != NULL){
        printf("#%i: %i\n", i++, l -> element);
        l = l -> next;
    }
}

/* ------------------------------- */
int queue_first (queue q, int *success)
{
    if (queue_isempty(q)) {
        if (success != NULL)
            *success = 0;
        return 0;
    }
    if (success != NULL)
        *success = 1;
    return (q->first)->element;
}

/* ------------------------------- */
int queue_enter(queue q, int n)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
        return 0;
    new->element = n;
    new->next = EMPTY_QUEUE;

    if (q->last != EMPTY_QUEUE)
        (q->last)->next = new;
    if (q->first == EMPTY_QUEUE)
        q->first = new;

    q->last = new;
    return 1;
}

/* ------------------------------- */
int queue_remove(queue q, int *success)
{
    int success_first;
    list next;
    int n = queue_first(q, &success_first);
    if (!success_first) {
        if (success != NULL)
            *success = 0;
        return 0;
    }
    next = (q->first)->next;

    free(q->first);
    q->first = next;

    if (next == EMPTY_QUEUE)
        q->last = EMPTY_QUEUE;
    if (success != NULL)
        *success = 1;
    return n;
}

/* ------------------------------- */
int queue_isempty(queue q)
{
    return q == NULL;

}

/* ------------------------------- */
int main (void)
{
    int i;
    int pos;
    list l;

    /* Queue erstellen */
    queue my_queue = queue_create();
    if (my_queue == NULL){
        printf("Speicherfehler in queue_create()\n");
        return EXIT_FAILURE;
    }

    /* Befüllen mit 10 Zufallszahlen */
    srand(time(NULL));
    for (i = 0; i < 10; i++){
        if(queue_enter(my_queue, rand() % 10 + 1) == 0){
            printf("Speicherfehler in queue_enter()\n");
            queue_destroy(my_queue);
            return EXIT_FAILURE;
        }

    }

    /* Position des letzten Wertes größer 5 */
    l = my_queue -> first;
    i = 1;
    pos = 0;

    while (l != NULL){
        if (l -> element > 5){ /* Wenn größer 5, dann speicher ich das, durchlaufe aber Liste trotzdem bis zum Ende und überschreibe pos falls notwendig */
            pos = i;
        }
        i++;
        l = l -> next;
    }

    printf("Letzte Pos mit einem Wert > 5 ist: %i\n", pos);

    /* Queue ausgeben: */
    list_print(my_queue -> first);

    queue_destroy(my_queue);

    return EXIT_SUCCESS;

}

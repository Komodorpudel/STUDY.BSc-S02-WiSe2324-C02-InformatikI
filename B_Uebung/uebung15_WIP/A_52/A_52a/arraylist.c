#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arraylist.h"

/* ------------------------------------- */

arraylist *arraylist_create(void)
{
    arraylist *m = malloc(sizeof(arraylist));
    if(m == NULL)
        return NULL;
    m->elements = NULL;
    m->size = 0;
    return m;
}

/* ------------------------------------- */
/* Neues Element an letzter Stelle einfügen (unsortiert) */
int arraylist_insert(arraylist *m, int n)
{
    int *neu = NULL;
    if (arraylist_isempty(m))
        neu = malloc(sizeof(int));
    else
        neu = realloc(m->elements, (m->size + 1) * sizeof(int));
    if(!neu)
        return 0;

    m->elements = neu;
    (m->elements)[m->size] = n;
    ++(m->size);

    return 1;
}

/* ------------------------------------- */
/* Ganze Liste löschen */
void arraylist_destroy(arraylist *m)
{
    /* Wenn elements auf irgendwas zeigt, muss ich das auch noch loswerden */
    if(!arraylist_isempty(m))
        free(m->elements);
    
    /* arraylist selbst loswerden */
    free(m);
}

/* ------------------------------------- */
/* Selber gebaut: */

void arraylist_print(const arraylist *m){

    int i;

    for(i = 0; i < m -> size; i++){
        printf("%i\n", (m -> elements)[i]);
    }

}

/* ------------------------------------- */
/* Selber gebaut: */
int arraylist_isempty(const arraylist *m)
{
    return (m -> elements == NULL);
}


/* ------------------------------------- */

int main (void)
{
    int i;
    int count;

    /* Leere Liste erstellen */
    arraylist *my_list;
    my_list = arraylist_create();

    if (my_list == NULL) {
        printf("Speicherfehler in arraylist_create()");
        return EXIT_FAILURE;
    }

    /* Liste nacheinander mit 10 ganzen Zufallszahlen befüllen */
    srand(time(NULL));

    for(i = 0; i < 10; i++){
        if(arraylist_insert(my_list, rand() % 100 + 1) == 0) {
            printf("Speicherfehler in arraylist_insert");
            arraylist_destroy(my_list);

        }
    }

    /* Anzahl der Zahlen zwischen 25 und 87 ausgeben */
    count = 0;

    for (i = 0; i < my_list -> size; i++){
        if((my_list -> elements)[i] >= 25 && (my_list -> elements)[i] <= 75){
            count = count +1;
        }
    }

    printf("Anzahl Elemente zwischen 25 und 75; %i\n", count);
    arraylist_print(my_list);

    return 0;
}

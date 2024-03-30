#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"


void stack_destroy(stack s);
int is_empty(stack s);
int stack_push(stack *s, int n);
int stack_pop(stack *s); /* Aufdecken und löschen */
int stack_top(stack s); /* nur aufdecken */





/* ------------------------------- */
/* Neues Element hinzufügen */
int stack_push(stack *s, int n)
{ /* Ich bekomme Pointer auf einen Pointer */

    
    /* Speicher für neuen Node */
    node *new = malloc(sizeof(node));
    if (new == NULL){
        printf("Speicherfehler in stack_push\n");
        return EXIT_FAILURE;
    }
    new -> element = n;
    /* Der Zeiger zeigt auf das alte oberste Element */
    new -> next = *s;

    /* Stack zeigt nun auf neuestes oberstes Element */
    *s = new; /* new ist Adresse; *s ist der dereferenzierte Doppelzeiger */

    return 1;
}

/* ------------------------------- */
int stack_top(stack s)
{   /* Nur lesend, deswegen kein Doppelzeiger, sondern nur Zeiger */
    if(s == NULL){
        printf("Stack ist leer\n");
        return 0;
    }

    return s -> element;
}

/* ------------------------------- */

int stack_pop(stack *s)
{   /* Nun bekommenw wir einen Zeiger auf einen Zeiger, weil wir müssen den Zeiger umbiegen auf das Element eins drunter */

    int n;
    stack next;
    if (s == NULL){
        printf("Stack ist leer\n");
        return 0;
    } 

    n = (*s) -> element;
    next = (*s) -> next;

    /* Erste Element entfernen */
    free(*s);

    /* s zeigt nun auf das zweite Element */
    *s = next;
    
    return n;

}

/* ------------------------------- */
int stack_isempty(stack s)
{
    return s == NULL;
}

/* ------------------------------- */

void stack_destroy(stack s)
{
    if (s != NULL){
        if (s -> next != NULL){
            stack_destroy(s -> next);
        }

        free(s);

    }
}

/* ------------------------------- */

int main(void)
{
    stack my_stack = NULL;
    int i;
    int f;

    for (i = 1; i <= 10; i++){
        if(stack_push(&my_stack, i) == 0){
            printf("Speicherfehler in stack_push\n");
            stack_destroy(my_stack);
            return EXIT_FAILURE;
        }
    }

    f = 1;
    while (!stack_isempty(my_stack)){
        f = f * stack_pop(&my_stack);

    }
    printf("10! = %i", f);
    stack_destroy(my_stack);

    return 1;

}

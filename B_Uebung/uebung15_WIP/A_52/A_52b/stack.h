#ifndef STACKS_H_INCLUDED
#define STACKS_H_INCLUDED

#define EXIT_FAILURE 1

/* Ich habe keine Überstruktur, weil ich sowieso immer nur Zugriff auf das erste Element habe */

typedef struct _node {
    int element;
    struct _node *next; /* *next ist ein Zeiger auf struct _node */

} node;

typedef node* stack; /* Stack ist ein Zeiger auf ein node */

void stack_destroy(stack s);
int stack_isempty(stack s);
int stack_push(stack *s, int n);
int stack_pop(stack *s); /* Aufdecken und löschen */
int stack_top(stack s); /* nur aufdecken */

#endif

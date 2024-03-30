#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define EMPTY_QUEUE NULL
#define EMPTY_LIST NULL

/* Struktur innerhalb Queue */
typedef struct _node {
    int element;
    struct _node *next; /* *next ist ein Zeiger auf struct _node */

} node;
typedef node* list; /* list ist Zeiger auf node */

/* Überstruktur für Queue */
/* Notwendig, weil eig identisch zu Stacks, aber ich hänge immer ans Ende an. Deswegen ist es praktischer, ein direkt zu wissen wo das Ende ist, sonst muss ich alles durchlaufen und auf next auf NULL checken */
typedef struct _queue {
    list last;
    list first;
} * queue;

queue queue_create(void);
void queue_destroy(queue q);
int queue_isempty(queue q);
int queue_enter(queue q, int n);
int queue_remove(queue q, int *success);
int queue_first(queue q, int *success);
list list_destroy(list l);

#endif

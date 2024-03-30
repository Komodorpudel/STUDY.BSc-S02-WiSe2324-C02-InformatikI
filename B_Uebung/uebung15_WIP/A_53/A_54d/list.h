#ifndef EVL_H_INCLUDED
#define EVL_H_INCLUDED

#define EMPTY_LIST NULL
typedef struct _node {
    int element;
    struct _node *next;
} node;
typedef node *list;

list list_destroy(list l);
int list_size(list l);
void list_print(const list l);
int list_isempty(const list l);
list list_insert(list l, int n);
list list_delete(list l, int n);
int list_iselem(list l, int n);

#endif
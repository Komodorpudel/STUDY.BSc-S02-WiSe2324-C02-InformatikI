#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

#define EXIT_FAILURE 1

typedef struct _arraylist {
    int *elements;
    int size;
} arraylist;

arraylist *arraylist_create(void);
void arraylist_destroy(arraylist *m);
/* int arraylist_size(const arraylist *m); */
void arraylist_print(const arraylist *m);
int arraylist_isempty(const arraylist *m);
int arraylist_insert(arraylist *m, int n);
int arraylist_delete(arraylist *m, int n);
/* int arraylist_iselem(const arraylist *m, int n); */
#endif

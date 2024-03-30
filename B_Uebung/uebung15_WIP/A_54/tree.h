#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct _node {
    struct _node *right;
    int element;
    struct _node *left;
    } node;
typedef node* tree;
#define EMPTY_TREE NULL

#endif
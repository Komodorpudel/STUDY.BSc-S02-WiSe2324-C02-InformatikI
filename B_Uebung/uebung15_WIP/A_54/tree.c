#include <stdio.h>
#include "tree.h"

/* ------------------------------------ */
tree tree_add(tree root, int value)
{
    if (root == EMPTY_TREE) {
        root = malloc(sizeof(node));
        if (root == EMPTY_TREE) {
            return EMPTY_TREE;
        }
        root->element = value;
        root->left = EMPTY_TREE;
        root->right = EMPTY_TREE;
        return root;
    }
    if (value < root->element) {
        root->left = tree_add(root->left, value);
    }
    else if (value > root->element) {
        root->right = tree_add(root->right, value);
    }
    return root;
}

/* ------------------------------------ */
void tree_destroy(tree root)
{
    if (root != EMPTY_TREE) {
        tree_destroy(root->left);
        tree_destroy(root->right);
        free(root);
    }
}

/* ------------------------------------ */
void tree_print(tree root)
{
    if (root != EMPTY_TREE) {
        tree_print(root->left);
        printf("%i ", root->element);
        tree_print(root->right);
    }
}

/* ------------------------------------ */
tree tree_min(tree root)
{
    if (root == EMPTY_TREE) {
        return EMPTY_TREE;
    }
    if (root->left == EMPTY_TREE) {
        return root;
    }
    return tree_min(root->left);
}

/* ------------------------------------ */
int main(void)
{
    int i;
    int a[] = {5, 3, 8, 4, 1, 9, 6};
    tree temp, root = EMPTY_TREE;

    for (i = 0; i < 7; i++) {
        temp = tree_add(root, a[i]);
        if (temp == EMPTY_TREE) {
            printf("Fehler beim Hinzufuegen eines Werts!\n");
            tree_destroy(root);
            return 1;
        }
        root = temp;
        printf("%i hinzugefuegt\n", a[i]);
    }

    tree_print(root);
    printf("\nMinimum: %i\n", tree_min(root) -> element);
    tree_destroy(root);
    return 0;
}
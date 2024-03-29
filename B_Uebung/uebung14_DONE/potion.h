#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED

#define MAX_STRING 100

#define HEAL_FACTOR 3
#define MANA_FACTOR 2
#define SLEEP_FACTOR 0.5

typedef struct _potion {
    char name[MAX_STRING + 1];
    int weight; /* In Gramm */
    char effect[MAX_STRING + 1];
} potion;

potion create_health_potion(int weight);
potion create_mana_potion(int weight);
potion create_sleep_potion(int weight);
int potion_equals (potion *p1, potion *p2);
void print_potion(potion *p);

#endif

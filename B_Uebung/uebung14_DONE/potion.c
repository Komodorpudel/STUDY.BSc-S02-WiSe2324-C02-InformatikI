#include <stdio.h>
#include <math.h>
#include <string.h>
#include "potion.h"


potion create_health_potion(int weight)
{
    potion p;
    sprintf(p.name, "Heil-Trank");
    p.weight = weight;
    sprintf(p.effect, "Regeneriert %i Lebenspunkte", weight * HEAL_FACTOR);

    return p;

}

potion create_mana_potion(int weight)
{
    potion p;
    sprintf(p.name, "Mana-Trank");
    p.weight = weight;
    sprintf(p.effect, "Regeneriert %i Mana", weight * MANA_FACTOR);
    
    return p;
}

potion create_sleep_potion(int weight)
{
    potion p;
    sprintf(p.name, "Heiltrank");
    p.weight = weight;
    sprintf(p.effect, "Lässt nutzer %i Sekunden schlafen", (int) (0.5 * weight));

    return p;
 
}

int potion_equals (potion *p1, potion *p2)
{
    int name_equal = strcmp(p1 -> name, (*p2).name) == 0;
    int weight_equal = p1 -> weight == (*p2).weight;
    int effect_equal = strcmp(p1 -> effect, (*p2).effect) == 0;

    return name_equal && weight_equal && effect_equal;
}

void print_potion(potion *p)
{
    printf("---\n");
    printf("| Name: %s\n", p -> name);
    printf("| Gewicht: %i Gramm\n", p -> weight);
    printf("| Effekt: %s\n", p -> effect);
    printf("---\n");

}

#include <stdio.h>
#include "backpack.h"
#include "potion.h"

/* ----------------------------------------- */

backpack initialize_backpack(void)
{
    backpack b;
    b.total_weight = 0;
    return b;
}

/* ----------------------------------------- */

int potion_amount(backpack *b)
{
    int i;
    int weight_left = b -> total_weight;

    for(i = 0; i < BACKPACK_SIZE; i++){
        if(weight_left == 0) {
            break;
        }
        weight_left = weight_left - b -> potions[i].weight;
    }

    return i;
}

/* ----------------------------------------- */

void print_backpack(backpack *b)
{
    int i;
    int potion_num;

    if((b -> total_weight) == 0) {
        printf("Der Rucksack ist leer\n");
    }
    else{
        potion_num = potion_amount(b);
        printf("Der Rucksack enthält folgende Tränke:\n");

        for(i = 0; i < potion_num; i++){
            print_potion(b -> potions + 1);
        }
    }
}

/* ----------------------------------------- */

void add_potion_to_backpack(potion *p, backpack *b)
{
    /* Prüfen ob zu noch genug Platz */
    int pos = potion_amount(b);
    if(pos >= BACKPACK_SIZE){
        printf("Der Rucksack ist bereits voll.\n\n");
    }
    else{
        b -> potions[pos] = (*p);
        b -> total_weight = b -> total_weight + p -> weight;
    }
}

/* ----------------------------------------- */

void remove_potion_from_backpack(potion *p, backpack *b)
{
    int i;
    int pos = BACKPACK_SIZE;
    int potion_num = potion_amount(b);

    /* Erste Pos von Potion finden */
    for(i = 0; i < potion_num; i++){
        if(potion_equals(b -> potions + i, p)) {
            pos = i;
            break;
        }
    }

    if(pos < BACKPACK_SIZE) {
        b -> total_weight = b -> total_weight - p -> weight;

        /* Potions verschieben */
        for(i = pos; i < potion_num - i; i++){
            b -> potions[i] = b -> potions[i + 1];
        }
    }
    else {
        printf("Der gesuchte Trank wurde nicht gefunden. \n");
    }
}

int main(void)
{
    backpack b = initialize_backpack();
    potion h = create_health_potion(100);
    potion m = create_mana_potion(50);
    potion s = create_sleep_potion(17);
    potion h2 = create_health_potion(12);

    add_potion_to_backpack(&h, &b);
    add_potion_to_backpack(&m, &b);
    add_potion_to_backpack(&s, &b);
    
    print_backpack(&b);
    add_potion_to_backpack(&h2, &b);
    remove_potion_from_backpack(&h, &b);
    print_backpack(&b);
    remove_potion_from_backpack(&s, &b);
    print_backpack(&b);
    remove_potion_from_backpack(&m, &b);
    print_backpack(&b);
    return 0;
}

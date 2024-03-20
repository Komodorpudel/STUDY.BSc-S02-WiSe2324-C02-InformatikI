#include <stdio.h>
#define MAX_STRING 5

#define STRINGIFY(x) #x /* Verwandelt x in einen String */
#define STRINGIFY_VAL(x) STRINGIFY(x)

/* Immer gleicher Ablauf wenn ich eine Makro-Konstante als String in meinem Code verwenden möchte */

int main(void)
{

    printf("Programm gestartet\n");

    char eingabe1[MAX_STRING + 1];
    char eingabe2[MAX_STRING + 1];
    scanf("%" STRINGIFY_VAL(MAX_STRING) "s", eingabe1);
    scanf("%" STRINGIFY_VAL(MAX_STRING) "s", eingabe2);
    printf("Eingabe 1: %s\n", eingabe1);
    printf("Eingabe 2: %s\n", eingabe2);

    return 0;
}
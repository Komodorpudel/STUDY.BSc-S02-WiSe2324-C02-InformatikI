#include <stdio.h>
#define MAX_STRING 5
#define STRINGIFY(x) #x
#define STRINGIFY_VAL(x) STRINGIFY(x)
int main(void)
{
char eingabe1[MAX_STRING + 1];
char eingabe2[MAX_STRING + 1];
scanf("%" STRINGIFY_VAL(MAX_STRING) "s", eingabe1);
scanf("%" STRINGIFY_VAL(MAX_STRING) "s", eingabe2);
printf("Eingabe 1: %s\n", eingabe1);
printf("Eingabe 2: %s\n", eingabe2);
return 0;
}
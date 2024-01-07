#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int a = -1, b = 5;
    /* Fehler: Die Zeiger müssen auf gültige Speicheradressen zeigen */

    printf("Originalwerte: x = %i, y = %i\n", a, b);

    swap(&a, &b);
    /* Fehler: Ich muss Adressen übergeben, nicht die Zeiger */

    printf("Neue Werte: x = %i, y = %i\n", a, b);
    /* Fehler: Ich will Werte ausgeben */

    return 0;
}
#include <stdio.h>

int division(int zaehler, int nenner, int *rest)
{
    int div = zaehler / nenner;

    if (zaehler % nenner != 0) {
        *rest = zaehler % nenner;
        /* Fehler: *rest anstatt rest: Wwir wollen ja da hins schreiben wo der pointer zeigt und nicht auf den pointer selbst*/
    }
    return div;
}

int main(void)
{
    int zaehler = 111, nenner = 7;
    int rest = 0; /* Fehler: rest anstatt *rest: Keine notwendigkeit hier einen Pointer anzulegen */

    printf("Ergebnis der Division: %i\n", division(zaehler, nenner, &rest));
    /* Fehler: &rest anstatt rest: Wir müssen nur die Adresse übergeben */
    printf("Rest: %i\n", rest);
    /* Fehler: rest anstatt *rest: Wir wollen rest ausgeben und nicht den Zeiger auf rest */

    return 0;
}
#include <stdio.h>
#include <stdlib.h> /* für Exit_FAILURE */

void print_alarm(int size)
{

    if (size < 0) {
        fprintf(stderr, "Fehler: negative Größe %d ist nicht erlaubt.\n", size);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        putchar(7); // Sendet das Bell-Zeichen (ASCII-Code 7)
        printf("Gib was ein");
        getchar(); 
    }
}

int main()
{
    print_alarm(3); // Sollte 3 Alarmsignale ausgeben
    print_alarm(0); // Sollte nichts ausgeben
    print_alarm(-5); // Sollte mit einer Fehlermeldung abbrechen

    return 0;
}
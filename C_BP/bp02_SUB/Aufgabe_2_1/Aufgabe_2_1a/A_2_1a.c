#include <stdio.h>
#include <stdlib.h> /* für rand() */
#include <time.h>

int main() {
    
    // Zufallszahl generieren und speichern
    srand(time(NULL));
    int number = rand() % 2000;

    // Ausgabe Zufallszahl und check ob zahl dreistellig
    printf("Random number: %d\n ", number);

    if (number >= 100 && number < 1000) {
        printf("number is three digit");
    }

    else {
        printf("number is not three digit");
    }

    return 0;
}

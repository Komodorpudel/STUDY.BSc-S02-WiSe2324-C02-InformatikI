#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Zufallszahl generieren und speichern

    int number = rand() % 2000;

    // Ausgabe Zufallszahl und check ob zahl dreistellig
    printf("Random number: %d\n ", number);

    if (number >= 100 && number < 1000) {
        printf("number is three digit");
    }

    else {
        printf("numer is not three digit");
    }

    return 0;
}

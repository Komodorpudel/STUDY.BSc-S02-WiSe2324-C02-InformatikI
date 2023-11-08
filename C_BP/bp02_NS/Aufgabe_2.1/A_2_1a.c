#include <stdio.h>

int main() {
    
    // Zufallszahl generieren und speichern

    int number = rand() % 2000;


    // Ausgabe Zufallszahl und check ob zahl dreistellig

    printf("Random number: %d\n ", number);

    // check

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    
    int i;

    // Zufallszahl generieren und speichern
    srand((unsigned int)time(NULL));

    i = rand() % 40001;

    printf("my int: %i\n", i);

    if ( i <= 20000) {
        printf("Teilbar durch 5?\n");
        if (i % 5 == 0) {
            printf ("0");
        }
        else {
            printf("1");
        }
    }

    else {
        printf("2");

    }

    printf("\nEnde\n");

    return 0;

}

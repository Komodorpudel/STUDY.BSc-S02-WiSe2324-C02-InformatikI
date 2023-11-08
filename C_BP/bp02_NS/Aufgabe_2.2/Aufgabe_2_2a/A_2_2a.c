#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    
    // Zufallszahl generieren und speichern
    srand((unsigned int)time(NULL));

    int i = rand() % 40001;

    printf("my int: %i\n", i);

    printf("Teilbar durch 5?");
    if ( i <= 20000) {

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

    printf("\nEnde");

    return 0;

}

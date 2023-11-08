#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    
    // Zufallszahl generieren und speichern
    srand((unsigned int)time(NULL));

    int i = rand() % 40001;

    printf("my int: %i\n", i);

    println("Teilbar durch 5?");
    if ( i <= 20000) {

        if (i % 5 == 0) {

            printf ("0");

        }

        else {
            printf("1");
        }
    }

    return 0;

}

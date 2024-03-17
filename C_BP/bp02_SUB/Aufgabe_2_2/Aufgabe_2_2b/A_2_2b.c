#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    
    // Zufallszahl generieren und speichern
    srand(time(NULL));

    int a = rand();

    int b = rand();

    printf("A: %i; B: %i\n",a,b);

    // Determine Minimum

    if (a > b) {
        printf("a ist minimum");
    }
    else if ( a == b) {
        printf("a und b gleich");
    }
    else {
        printf("b ist minimum");
    }

    return 0;

}

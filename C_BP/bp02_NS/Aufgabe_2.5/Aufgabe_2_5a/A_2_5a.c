#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    
    // Zufallszahl generieren und speichern
    srand((unsigned int)time(NULL));

    int myNumber = rand() % 10;

    int index = 1;

    while(index <= myNumber) {
        printf("%e", pow(index, 0.5));
        ++index;
    }

    return 0;

}

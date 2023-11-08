#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    
    // Zufallszahl generieren und speichern
    srand((unsigned int)time(NULL));

    int myNumber = rand() % 9;

    int index = 1;

    while(index <= myNumber) {
        printf("%e", pow(index, 0.5));
        index = index + 1;
    }

    return 0;

}

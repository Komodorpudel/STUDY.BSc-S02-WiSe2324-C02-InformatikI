#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

int main() {
    
    // Zufallszahl generieren und speichern
    int myNumber;
    int index;
    double zwischen;

    srand(time(NULL));

    myNumber = rand() % 10;
    //myNumber = 8;

    index = 1;

    // loopen
    while(index <= myNumber) {
        zwischen = pow(index, 0.5);
        printf("%.3e       ", zwischen);
        ++index;
    }

    return 0;

}

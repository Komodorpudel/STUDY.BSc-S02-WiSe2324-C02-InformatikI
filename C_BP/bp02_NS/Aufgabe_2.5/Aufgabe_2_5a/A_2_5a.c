#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

int main() {
    
    // Zufallszahl generieren und speichern
    srand((unsigned int)time(NULL));

    //int myNumber = rand() % 10;
    int myNumber = 8;

    int index = 1;

    // loopen
    while(index <= myNumber) {
        double zwischen = pow(index, 0.5);
        printf("%.3e       ", zwischen);
        ++index;
    }

    return 0;

}

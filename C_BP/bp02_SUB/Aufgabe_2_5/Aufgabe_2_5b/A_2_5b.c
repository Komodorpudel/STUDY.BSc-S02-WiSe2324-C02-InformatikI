#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    
    // Zufallszahl generieren und speichern
    srand((unsigned int)time(NULL));

    // int n = rand() % 15;

    int n = 7;
    int zwischen = 1;

    for (int i = 1; i <= n; ++i) {

        zwischen = zwischen * 3;
        printf("%i\n", zwischen);

    }

}
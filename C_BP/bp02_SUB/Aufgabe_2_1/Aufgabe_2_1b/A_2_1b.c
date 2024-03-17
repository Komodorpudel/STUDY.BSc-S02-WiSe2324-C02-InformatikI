#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    
    char c;
    // Zufallszahl generieren und speichern
    srand(time(NULL));

    c = rand() % 128;

    printf("random character: %c\n", c);

    if (c <= 'a' || c > 'z') {

        printf("Der Char %c ist kein lateinischer Kleinbuchstabe", c);
    }

    return 0;

}
#include <stdio.h>

int main() {
    
    char b[16];
    int i;

    // Speichern der Ziffern von '0' bis '9' und der Kleinbuchstaben von 'a' bis 'f'
    for (i = 0; i < 10; i++) {
        b[i] = '0' + i; // Ziffern
    }
    for (i = 10; i < 16; i++) {
        b[i] = 'a' + (i - 10); // Kleinbuchstaben
    }

    // Ausgabe der Werte der 13-ten, 1-ten, 14-ten und 15-ten Komponente als Zeichen
    printf("%c%c%c%c\n", b[12], b[0], b[13], b[14]);

    return 0;
}

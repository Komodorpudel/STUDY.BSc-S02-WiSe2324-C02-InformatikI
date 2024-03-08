#include <stdio.h>

// Prototypes
void convert_to_base(int x, int base, char v[], int len_v);

int main () {

    int x = 2; /* Zahl die konvertiert werden soll */
    int base = 2; /* Basis in die Konvertiert werden soll */
    char array[] = {'0', '0', '0', '0', '0', '0', '0', '0','\0'}; /* Zielarray mit Terminierer */
    int len = (sizeof(array) / sizeof(array[0])) - 1; /* Länge - 1 wegen terminierer */

    convert_to_base(x, base, array, len);
    printf("Result: %s", array);

    return 0;

}

void convert_to_base(int x, int base, char v[], int len_v) { /* beachte, x und base werden als Kopien übergeben, v[] als Zeiger */

    // Vorgehensweise wie in Skript
    int index = len_v - 1;
    int digit;

    while (x > 0) {
        digit = x % base;

        if (digit < 10) {
            v[index] = '0' + digit; // beachte, v ist ein char array, daher addieren wir die int auf den char '0'
        }

        else {
            v[index] = 'A' + (digit - 10); // A = 10, B = 11, usw.
        }

        x = x / base; /* x ist int, daher ist das ganzzahlige Division */
        index--;

    }

}
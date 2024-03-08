#include <stdio.h>
#include <math.h>

// Functions
int convert_to_base(int x, int base, char v[], int len_v);

int main ()
{

    int x = 31;
    int base = 32;
    char array[] = {'0', '0', '0', '0', '0', '0', '0', '0','\0'}; // Terminierer hinzufügt
    int len = sizeof(array) / sizeof(array[0]) - 1;

    int success = convert_to_base(x, base, array, len);
    printf("Success: %i\n", success);
    printf("Result: %s", array);

    return 0;

}

int convert_to_base(int x, int base, char v[], int len_v)
{ // beachte, x und base werden als Kopien übergeben, v[] als Zeiger

    // ist die ubergebene Zahl ¨ x negativ, so soll die Funktion 0 zuruckgeben.
    if (x < 0) {
        return 0;
    };

    // Wird eine ungultige Basis ¨ ubergeben, so soll die Funktion 0 zur ¨ uckgeben.
    if (base < 2) { // basis 1 wird nicht unterstützt
        return 0;
    };

    /* Ist das ubergebene Feld zu klein, um ¨ x in der Basis base darzustellen, soll ebenfalls 0 zuruckgegeben werden */
    if (x > (pow(base, len_v) - 1)) { /*  */
        return 0;
    };

    /* Übergebenes Array mit 0en füllen (notwendig, weil theoretisch ein Array gefüllt mit 1en übergeben werden kann) */
    for (int i = 0; i < len_v; i++) {
        v[i] = '0';
    }

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

        x = x / base;
        index--;

    }

    return 1;

}
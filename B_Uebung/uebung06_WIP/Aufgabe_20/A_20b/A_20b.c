#include <stdio.h>

// Functions
int string_suffix(char v[], char w[]);
int string_len (char v[]);

int main()
{
    /* Test mit Zeichenketten gleicher und ungleicher Länge */
    printf("Test 1: %d\n", string_suffix("Informatik", "matik")); // Sollte 1 sein
    printf("Test 2: %d\n", string_suffix("Informatik", "info")); // Sollte 0 sein

    /* Test mit der leeren Zeichenkette */
    printf("Test 3: %d\n", string_suffix("Informatik", "")); // Sollte 1 sein
    printf("Test 4: %d\n", string_suffix("", "atik")); // Sollte 0 sein

    /* Test mit gleichen und ungleichen Zeichenketten */
    printf("Test 5: %d\n", string_suffix("Informatik", "Informatik")); // Sollte 1 sein
    printf("Test 6: %d\n", string_suffix("Informatik", "Informatikk")); // Sollte 0 sein

    return 0;
}

int string_suffix(char v[], char w[])
{
    int v_len = string_len(v);
    int w_len = string_len(w);

    int i = 0;


    /* Kein Suffix wenn länger */
    if (w_len > v_len) {
        return 0;
    }

    /* Von hinten vergleichen */
    for (; i < w_len; i++) {
        if (v[v_len - 1 - i] != w[w_len - 1 - i]) {
            return 0;
        }
    }

    return 1;

}

int string_len (char v[])
{
    int length = 0;

    while (v[length] != '\0') {
        length++;
    }

    return length;
}
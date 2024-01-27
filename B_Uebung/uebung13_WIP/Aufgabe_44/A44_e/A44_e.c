#include <stdio.h>
#include <string.h>

/* ------------------------------------------------- */

/* Jedes mal wenn ein Character aus s auch in t vorkommt, erhöhen wir c um 1 und brechen Suche ab für den jeweiligen Charakter aus s */
int strspn_count(const char *s, const char *t) {
    int c = 0; /* Counter for occurrences */
    int i = 0;
    int j = 0;
    int n;
    int m;

    n = strlen(s); /* Länge von s */
    m = strlen(t); /* Länge von t */

    /* Iteriere über jeden Charakter in s */
    for (i = 0; i < n; i++) {


        /* Iteriere über jeden Charakter in t */
        for (j = 0; j < m; j++) {
            /* Wenn die Charaktere übereinstimmen, erhöhe c */
            if (s[i] == t[j]) {
                c = c + 1;
                break; /* Breche die innere Schleife ab, wenn eine Übereinstimmung gefunden wurde */
            }
        }

        if (j == m) { /* Komplett Abbrechen, wenn wir bis zum Ende vom zweiten Wort durchlaufen mussten */
            break;
        }
    }

    return c; 
}

/* ------------------------------------------------- */

int main() {
    char s[] = "example string"; 
    char t[] = "aeiou";

    int count;

    count = strspn_count(s, t); 
    printf("Character count: %d\n", count);

    return 0;
}

/* ------------------------------------------------- */

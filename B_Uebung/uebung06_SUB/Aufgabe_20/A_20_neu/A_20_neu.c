#include <stdio.h>


/* Prototype */
void string_ncat(char v[], char w[], int n);
int string_suffix(char v[], char w[]);

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

void string_ncat(char v[], char w[], int n)
{
    int i;

    /* Wir finden das Ende von v */
    int v_length = 0;
    while (v[v_length] != '\0'){
        v_length++;
    }

    /* Wir hängen zeichen an unter an Annahme, dass bis zu n Zeichen sicher ist */
    for (i = 0; i < n; i++) {
        if (w[i] == '\0'){
            break;
        }

        v[v_length + i] = w[i];
    }

    /* Terminieren */

    v[v_length + i] = '\0';
}

int string_suffix(char v[], char w[])
{
    int v_length = 0;
    int w_length = 0;
    int i = 0;

    /* Das Ende finden von beiden */
    while (v[v_length] != '\0') {
        v_length++;
    }

    while (w[w_length] != '\0') {
        w_length++;
    }

    /* w länger als v? */
    if (w_length > v_length){
        return 0;
    }

    /* Am Ende starten und vergleichen */
    for(i = 0; i < w_length; i++){
        if(v[v_length - 1 - i] != w[w_length - 1 - i]){
            return 0;
        }
    }

    return 1; /* Ich kann nicht i zurückgeben, weil bei leerem w würde 0 zurückgegeben werden*/

}


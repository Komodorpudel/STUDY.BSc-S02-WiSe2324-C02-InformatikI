#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_d_copy_n(char *s, int n);
char **string_d_split(const char *s, char delim, int *count);

/* --------------------------------------------------- */

int main(void) {
    const char *input = "Mehl;Milch;;Eier";
    char delim = ';';
    int count, i;
    char **split_strings;

    // Aufrufen von string_d_split
    split_strings = string_d_split(input, delim, &count);

    // Überprüfen, ob die Funktion erfolgreich war
    if (split_strings == NULL) {
        printf("Fehler beim Aufteilen der Zeichenkette.\n");
        return 1;
    }

    // Ausgeben der ursprünglichen Zeichenkette
    printf("Ursprüngliche Zeichenkette: %s\n", input);

    // Ausgeben der aufgeteilten Teilzeichenketten
    printf("Aufgeteilte Teilzeichenketten:\n");
    for (i = 0; i < count; i++) {
        printf("%d: %s\n", i, split_strings[i]);
    }

    // Freigeben des dynamisch reservierten Speichers
    for (i = 0; i < count; i++) {
        free(split_strings[i]);
    }
    free(split_strings);

    return 0;
}

/* --------------------------------------------------- */

char *string_d_copy_n(char *s, int n)
{
    /* Speicherplatz veservieren */
    char *copy =  malloc((n + 1) * sizeof(char));
    if (copy == NULL) {
        return NULL; /* Wenn Reservierung fehlschlägt, soll null zurückgegeben werden */
    }

    if ( n <= 0) {
        copy[0] = '\0';
    }

    /* Wir verwenden strncpy um n Buchstaben von s nach copy zu kopieren */
    strncpy(copy, s, n);
    copy[n] = '\0'; /* Wir fügen an letzter Stelle den Terminierer hinzu */

    return copy;

}

/* --------------------------------------------------- */

/* Die Funktion gibt ein Array zurück mit Zeiger auf die Arrays, insofern Doppelzeiger (Wir zeigen auf das Array und das Array zeigt auf die Strings) */
char** string_d_split(const char *s, char delim, int *count)
{
    int i = 0;
    int start = 0; /* Startwert für den nächsten String */
    int max_strings = 1;
    int result_index = 0;

    /* Wenn s leer oder count == NUll (die adresse an der wir die Anzahl speichern sollen) dann return */
    if (!s || !count) {
        return NULL;
    }

    /* Wir durchlaufen das Array einmal und zählen die delim, um die Arraygröße zu bestimmen */
    for (; s[i] != '\0'; i++) {
        if(s[i] == delim) {
            max_strings = max_strings + 1; 
        }
    }

    /* Wir legen dynamisches Array mit passender Länge an */
    char **result = (char**) malloc(max_strings * sizeof(char *)); /* Wieso "char**"? Ein Array selbst ist ein pointer, und im array sind pointer */

    if (!result) {
        return NULL;
    }

    /* Zeichenkette s nach delim durchsuchen */
    for (i = 0; ; i++) {

        /* Wenn wir ein delim erkennen oder am Ende sind: */
        if(s[i] == delim || s[i] == '\0') {

            /* Funktionsaufruf  - Wir speichern in result[result_index] den Zeiger auf den neuen String*/
            result[result_index] = string_d_copy_n((char *)(s + start), (i - start));

            /* Fehlerbehandlung - wir leeren das ganze Array wieder */
            if (!result[result_index]) {
                for (i = 0; i < result_index; i++) {
                    free(result[i]);
                }
                free(result);
                return NULL;

            }

            result_index = result_index +1;

            /* Den Start für nächsten String abspeichern */
            start = i + 1;
        }

        /* Raus aus Schleife wenn am Ende angekommen */
        if (s[i] == '\0') {
            break;
        }
    }

    /* Count zurückgeben */
    *count = result_index;

    return result;

}

/* --------------------------------------------------- */

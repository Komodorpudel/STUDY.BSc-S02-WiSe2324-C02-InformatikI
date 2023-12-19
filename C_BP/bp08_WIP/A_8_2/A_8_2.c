#include <stdio.h>

void append_pointer(char *destination, char *source);
void append_pointer_2 (char *destination, char *source);
void append_array(char destination[], char source[]);

int main(void)
{
    char arr1[12] = "Hallo";
    printf("Das Array 1 enthaelt: '%s'\n", arr1);

    char arr2[12] = "Hallo";
    printf("Das Array 2 enthaelt: '%s'\n", arr1);

    char arr3[12] = "Hallo";
    printf("Das Array 3 enthaelt: '%s'\n", arr1);

    char arr_append[12] = "Welt";

    /* Methode 1  */
    append_pointer(arr1, arr_append);
    printf("Methode 1: %s\n", arr1 );

    /* Methode 2  */
    append_pointer_2(arr2, arr_append);
    printf("Methode 2: %s\n", arr2 );

    /* Methode 3  */
    append_array(arr3, arr_append);
    printf("Methode 3: %s\n", arr3 );

    return 0;
}

/* ++++++++++ 1. Zeiger und Zeichenketten ++++++++++ */
void append_pointer(char *destination, char *source)
{
    /* "\0" hat den Wahrheitswert falsch. */
    
    /* Diese Schleife geht solange weiter bis wir bei dem Terminierer angekommen sind (oder einer leeren Adresse) */
    while (*destination) ++destination;
    /* Es spielt hier keine Rolle ob "++destination oder destination++" */

    /* Destination zeigt nun auf den Terminierer und ich mache weiter: */

    /* +++++++++++++++++++++++++++++++++++++++ */

    /* ich schreibe den Wert auf den Source zeigt, an die Stelle auf die Destination zeigt.
    
    Dann zähle ich die Adressen auf die Destination und Source jeweils zeigen um eins hoch. Die schleife endet */

    /* while prüft ob der wert auf den Destination ungleich 0 ist und macht dann weiter */
    while ((*destination++ = *source++));

}

/* Alternative Schreibweise */
void append_pointer_2 (char *destination, char *source)
{
    /* Ans Ende gehen */
    while (*destination != '\0') {
        destination = destination + 1;
    };

    /* Anhängen solange source nicht bei "\0" ist */
    while (*source != '\0') {
        *destination = *source;
        destination = destination +1;
        source = source + 1;
    }

    /* Terminieren */
    *destination = '\0';

}

/* ++++++++++ 2. Überführung in Felder ++++++++++ */
void append_array(char destination[], char source[]) {

    int i = 0;
    int j = 0;

    /* Ans Ende von Destination gehen */
    while (destination[i] != '\0') {
        i = i + 1;
    };

    /* Anhängen solange source nicht bei "\0" ist */
    while (source[j] != '\0') {
        destination[i] = source[j];
        i = i +1;
        j = j + 1;
    }

    /* Terminieren */
    destination [i] = '\0';

}

